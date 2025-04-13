#include <stdio.h>

#include "hardware/irq.h"

#include "ContadorApp.hpp"

extern "C"
{
#include "i2c_setup.h"
#include "oled_setup.h"
#include "ssd1306.h"
}

extern "C" bool timer_callback(repeating_timer *t);
extern "C" void gpio_callback(uint gpio, uint32_t events);

ContadorApp *ContadorApp::instancia = nullptr;

ContadorApp::ContadorApp(uint gpio_a, uint gpio_b)
    : botao_a(gpio_a), botao_b(gpio_b)
{
    if (!instancia)
        instancia = this;
}

void ContadorApp::init()
{
    setup_i2c0();
    setup_oled();

    gpio_init(botao_a);
    gpio_set_dir(botao_a, GPIO_IN);
    gpio_pull_up(botao_a);
    gpio_set_irq_enabled_with_callback(botao_a, GPIO_IRQ_EDGE_FALL, true, gpio_callback);

    gpio_init(botao_b);
    gpio_set_dir(botao_b, GPIO_IN);
    gpio_pull_up(botao_b);
    gpio_set_irq_enabled_with_callback(botao_b, GPIO_IRQ_EDGE_FALL, true, gpio_callback);

    static repeating_timer timer;
    add_repeating_timer_ms(1000, timer_callback, nullptr, &timer);
}

void ContadorApp::handle_gpio(uint gpio, uint32_t events)
{
    printf("GPIO callback: gpio=%d, events=0x%X\n", gpio, events);

    if (gpio == botao_a && (events & GPIO_IRQ_EDGE_FALL))
    {
        printf("Botão A pressionado!\n");
        if (!modo_ativo)
        {
            contador = 9;
            cliques_botao_b = 0;
            modo_ativo = true;
            primeiro_clique_b = true;

            printf("Modo ativado! contador = %d, cliques_botao_b = %d\n", contador, cliques_botao_b);
        }
        return;
    }

    if (gpio == botao_b && (events & GPIO_IRQ_EDGE_FALL))
    {
        printf("Botão B pressionado! cliques_botao_b = %d\n", cliques_botao_b);
        absolute_time_t agora = get_absolute_time();

        if (primeiro_clique_b)
        {
            primeiro_clique_b = false;
            ultimo_clique_b = agora;
            printf(">>> Primeiro clique: inicializando ultimo_clique_b\n");
            return;
        }

        printf("agora = %llu, ultimo_clique_b = %llu\n", 
            to_us_since_boot(agora), 
            to_us_since_boot(ultimo_clique_b));

        int64_t diff = absolute_time_diff_us(ultimo_clique_b, agora);
        printf("contador=%d, diff=%lld us\n", contador, diff);

        if (modo_ativo && contador > 0 && diff > DEBOUNCE_MS * 1000)
        {
            cliques_botao_b++;
            ultimo_clique_b = agora;
            printf(">>> Clique válido! cliques_botao_b = %d\n", cliques_botao_b);
        }
        else
        {
            printf(">>> Clique ignorado (modo_ativo=%d, contador=%d, debounce=%lld)\n",
                   modo_ativo, contador, diff);
        }
        return;
    }
}

bool ContadorApp::handle_timer()
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

// --- CALLBACKS ---
extern "C" void gpio_callback(uint gpio, uint32_t events)
{
    if (auto app = ContadorApp::getInstance())
        app->handle_gpio(gpio, events);
}

extern "C" bool timer_callback(repeating_timer *t)
{
    if (auto app = ContadorApp::getInstance())
        return app->handle_timer();
    return true;
}
