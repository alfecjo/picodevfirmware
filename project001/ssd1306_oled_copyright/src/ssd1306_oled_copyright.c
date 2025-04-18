#include <stdio.h>
#include <stdint.h>

#include "pico/time.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#include "i2c_setup.h"
#include "oled_setup.h"

// Active mode flag
volatile bool modo_ativo = false;
// Countdown value
volatile uint8_t contador = 0;
// Counts button B presses
volatile uint8_t cliques_botao_b = 0;

absolute_time_t ultimo_clique_b;
const int DEBOUNCE_MS = 200;

#define BOTAO_A 5
#define BOTAO_B 6

void gpio_callback(uint gpio, uint32_t events)
{
    if (gpio == BOTAO_A && (events & GPIO_IRQ_EDGE_FALL))
    {
        // Start count if inactive
        if (!modo_ativo)
        {
            contador = 9;
            cliques_botao_b = 0;
            modo_ativo = true;
        }
    }

    if (gpio == BOTAO_B && (events & GPIO_IRQ_EDGE_FALL))
    {
        absolute_time_t agora = get_absolute_time();

        // Count B presses if active and debounce passed
        if (modo_ativo && contador > 0 &&
            absolute_time_diff_us(ultimo_clique_b, agora) > DEBOUNCE_MS * 1000)
        {
            cliques_botao_b++;
            ultimo_clique_b = agora;
        }
    }
}

// Set up buttons with pull-ups and interrupts on falling edge
void setup_botoes(void)
{
    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);
    gpio_set_irq_enabled(BOTAO_B, GPIO_IRQ_EDGE_FALL, true);
}

// Callback runs every second
bool contador_callback(struct repeating_timer *t)
{
    if (modo_ativo)
    {
        update_oled_info(contador, cliques_botao_b);

        if (contador == 0)
        {
            modo_ativo = false;
        }
        else
        {
            contador--;
        }
    }
    return true;
}

int main()
{
    stdio_init_all();

    setup_i2c0();
    setup_oled();
    setup_botoes();

    // Start repeating timer every 1s
    struct repeating_timer timer;
    add_repeating_timer_ms(1000, contador_callback, NULL, &timer);

    while (1)
    {
        tight_loop_contents(); // Low-power idle
    }

    return 0;
}
