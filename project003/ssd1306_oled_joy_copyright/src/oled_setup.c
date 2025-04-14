#include <stdio.h>
#include <string.h> 

#include "ssd1306.h"
#include "oled_setup.h"

// Estrutura global do display
ssd1306_t disp; // Declara uma variável global para armazenar as configurações do display SSD1306

void setup_oled(void)
{
    // Configura a alimentação do display
    disp.external_vcc = false; // Define se o display usa alimentação externa (false indica que usa alimentação interna)

    // Inicializa o display SSD1306
    // Parâmetros: &disp (estrutura de configuração), 128 (largura do display), 64 (altura do display), 0x3C (endereço I2C do display), i2c1 (bus I2C utilizado)
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);

    // Limpa a tela do display
    ssd1306_clear(&disp); // Chama a função para apagar qualquer conteúdo da tela
}

void update_oled(uint16_t valor_x, uint16_t valor_y) {
    char linha1[20];
    char linha2[20];
    char direcao[20] = "Centro";

    snprintf(linha1, sizeof(linha1), "X:%4u Y:%4u", valor_x, valor_y);

    // Direção
    if (valor_x < 500 && valor_y < 500)
        strcpy(direcao, "Baixo Esq");
    else if (valor_x < 500 && valor_y > 3500)
        strcpy(direcao, "Baixo Dir");
    else if (valor_x > 3500 && valor_y < 500)
        strcpy(direcao, "Cima Esq");
    else if (valor_x > 3500 && valor_y > 3500)
        strcpy(direcao, "Cima Dir");
    else if (valor_x < 500)
        strcpy(direcao, "Baixo");
    else if (valor_x > 3500)
        strcpy(direcao, "Cima");
    else if (valor_y < 500)
        strcpy(direcao, "Esquerda");
    else if (valor_y > 3500)
        strcpy(direcao, "Direita");

    snprintf(linha2, sizeof(linha2), "Mov: %s", direcao);

    // OLED
    ssd1306_clear(&disp);
    ssd1306_draw_string(&disp, 0, 8, 1, linha1);
    ssd1306_draw_string(&disp, 0, 32, 1, linha2);
    ssd1306_show(&disp);

    // Debug
    printf("VALORES BRUTOS - X: %u, Y: %u\n", valor_x, valor_y);
    printf(">>> DIREÇÃO CALCULADA: '%s'\n", direcao);
}
