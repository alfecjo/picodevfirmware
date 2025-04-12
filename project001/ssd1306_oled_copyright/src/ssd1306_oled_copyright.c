#include <stdio.h>
#include <stdint.h>

#include "pico/time.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#include "i2c_setup.h"
#include "oled_setup.h"

// modo_ativo: controla se o sistema está em contagem ou não.
volatile bool modo_ativo = false;
// contador: começa em 9 quando o modo é ativado e decrementa a cada segundo.
volatile uint8_t contador = 0;
// cliques_botao_b: conta quantas vezes o botão B foi pressionado durante a contagem.
volatile uint8_t cliques_botao_b = 0;

absolute_time_t ultimo_clique_b;
const int DEBOUNCE_MS = 200;

#define BOTAO_A 5
#define BOTAO_B 6

void gpio_callback(uint gpio, uint32_t events)
{
    if (gpio == BOTAO_A && (events & GPIO_IRQ_EDGE_FALL))
    {
        // Só ativa se o sistema estiver parado (modo_ativo == false).
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

        if (modo_ativo && contador > 0 && absolute_time_diff_us(ultimo_clique_b, agora) > DEBOUNCE_MS * 1000)
        {
            cliques_botao_b++;
            ultimo_clique_b = agora;
        }
    }
}

// Configuração dos botões
// BOTAO_A: inicia a contagem regressiva de 9 segundos.
// BOTAO_B: conta quantas vezes foi pressionado durante a contagem.
// Ambos os botões têm pull-up habilitado e interrupção configurada para a borda de queda.
// O botão A inicia a contagem e o botão B incrementa o contador de cliques.
// O botão A só pode ser pressionado quando o sistema não está em contagem (modo_ativo == false).
// O botão B só conta cliques se o sistema estiver em contagem (modo_ativo == true) e o contador for positivo.
// O botão A e o botão B são configurados para gerar uma interrupção na borda de queda.
// Texto gerado pelo Copilot
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

    // Cria o timer que executa a função a cada 1 segundo
    struct repeating_timer timer;
    add_repeating_timer_ms(1000, contador_callback, NULL, &timer);

    while (1)
    {
        tight_loop_contents(); // economiza energia e mantém o core ativo
    }

    return 0;
}
