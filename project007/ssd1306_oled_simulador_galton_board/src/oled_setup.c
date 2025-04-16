#include <stdio.h>

#include "ssd1306.h"
#include "oled_setup.h"

extern void srand(unsigned int __seed);
extern int rand(void);

ssd1306_t disp; // A definição real da variável está aqui

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

// Função para atualizar a exibição no OLED (Temperatura ou Umidade)
void update_oled(float valor)
{
    char display_str[20]; // Declara um array de caracteres para armazenar a string com 20 caracteres de espaço

    // Se for temperatura, exibe com formato "Temp: X.X C"
    snprintf(display_str, sizeof(display_str), "Temp: %.1f C", valor);

    // Limpa a tela do display antes de atualizar com o novo valor
    ssd1306_clear(&disp);

    // Desenha a string (temperatura ou umidade) na posição X=10, Y=24 com o tamanho do texto 2
    ssd1306_draw_string(&disp, 10, 24, 2, display_str);

    // Atualiza o display com as informações desenhadas
    ssd1306_show(&disp); // Atualiza o conteúdo do display para mostrar a nova string
}

void draw_ball(ssd1306_t *disp, int x, int y) {
    int size = 4; // ou 3, se quiser maior

    for (int dx = 0; dx < size; dx++) {
        for (int dy = 0; dy < size; dy++) {
            ssd1306_draw_pixel(disp, x + dx, y + dy);
        }
    }
}


void draw_bins(ssd1306_t *disp, uint8_t *bins, int num_bins, int max_height) {
    ssd1306_clear(disp);

    for (int i = 0; i < num_bins; i++) {
        int height = bins[i];
        if (height > max_height)
            height = max_height;

        int x_start = i * (SSD1306_WIDTH / num_bins);
        int bar_width = (SSD1306_WIDTH / num_bins) - 1;

        for (int h = 0; h < height; h++) {
            int y = SSD1306_HEIGHT - 1 - h;
            for (int w = 0; w < bar_width; w++) {
                ssd1306_draw_pixel(disp, x_start + w, y);
            }
        }
    }

    ssd1306_show(disp);
}

int get_x_from_pos(int pos)
{
    return pos * (SSD1306_WIDTH / NUM_BINS) + (SSD1306_WIDTH / NUM_BINS) / 2;
}

void animate_ball(ssd1306_t *disp, int *final_bin, uint8_t *bins) {
    int pos = NUM_BINS / 2;

    for (int level = 0; level < NUM_LEVELS; level++) {
        if (rand() % 2 == 0)
            pos++;
        else
            pos--;

        if (pos < 0)
            pos = 0;
        if (pos >= NUM_BINS)
            pos = NUM_BINS - 1;

        // Calcula posição da bolinha
        int x = get_x_from_pos(pos);
        int y = level * (SSD1306_HEIGHT / (NUM_LEVELS + 1));

        // Verifica se y atingiu ou ultrapassou a barra atual
        int bar_height = bins[pos];
        int bar_y = SSD1306_HEIGHT - bar_height;

        if (y >= bar_y) {
            break; // A bolinha “tocou” a barra
        }

        // Redesenha a tela
        ssd1306_clear(disp);
        draw_bins(disp, bins, NUM_BINS, MAX_HEIGHT);
        draw_ball(disp, x, y);
        ssd1306_show(disp);

        sleep_ms(100);
    }

    *final_bin = pos;
}

