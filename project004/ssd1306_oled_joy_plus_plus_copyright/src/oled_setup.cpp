#include <stdio.h>
#include <string.h>

#include "hardware/i2c.h"

extern "C"
{
#include "ssd1306.h"
}

#include "Oled_setup.hpp"

ssd1306_t disp;

void Oled_setup::setup_oled(void)
{
    disp.external_vcc = false;

    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);

    ssd1306_clear(&disp);
}

void Oled_setup::update_oled(uint16_t valor_x, uint16_t valor_y)
{
    char linha1[20];
    char linha2[20];

    snprintf(linha1, sizeof(linha1), "X:%4u Y:%4u", valor_x, valor_y);

    constexpr uint16_t LIMIAR_BAIXO = 500;
    constexpr uint16_t LIMIAR_CIMA = 3500;

    const char *direcao = "Centro";

    if (valor_x < LIMIAR_BAIXO && valor_y < LIMIAR_BAIXO)
        direcao = "Baixo Esq";
    else if (valor_x < LIMIAR_BAIXO && valor_y > LIMIAR_CIMA)
        direcao = "Baixo Dir";
    else if (valor_x > LIMIAR_CIMA && valor_y < LIMIAR_BAIXO)
        direcao = "Cima Esq";
    else if (valor_x > LIMIAR_CIMA && valor_y > LIMIAR_CIMA)
        direcao = "Cima Dir";
    else if (valor_x < LIMIAR_BAIXO)
        direcao = "Baixo";
    else if (valor_x > LIMIAR_CIMA)
        direcao = "Cima";
    else if (valor_y < LIMIAR_BAIXO)
        direcao = "Esquerda";
    else if (valor_y > LIMIAR_CIMA)
        direcao = "Direita";

    snprintf(linha1, sizeof(linha1), "X:%4u Y:%4u", valor_x, valor_y);
    snprintf(linha2, sizeof(linha2), "Mov: %s", direcao);

    // OLED
    ssd1306_clear(&disp);
    ssd1306_draw_string(&disp, 0, 8, 1, linha1);
    ssd1306_draw_string(&disp, 0, 32, 1, linha2);
    ssd1306_show(&disp);

    // Debug caso necessário
    printf(">>> OLED ATUALIZADO\n");
    printf("VALORES BRUTOS - X: %u, Y: %u\n", valor_x, valor_y);
    printf(">>> DIREÇÃO CALCULADA: '%s'\n", direcao);
}
