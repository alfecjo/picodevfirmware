#pragma once

#include "pico/stdlib.h"

class ContadorApp
{
public:
    ContadorApp(uint gpio_a, uint gpio_b);

    void init();
    void handle_gpio(uint gpio, uint32_t events);
    bool handle_timer();

    static ContadorApp *getInstance() { return instancia; }

private:
    volatile uint8_t contador = 0;
    volatile uint8_t cliques_botao_b = 0;
    volatile bool modo_ativo = false;

    absolute_time_t ultimo_clique_b;
    bool primeiro_clique_b = true;
    static constexpr uint DEBOUNCE_MS = 150;

    uint botao_a;
    uint botao_b;

    static ContadorApp *instancia;
};
