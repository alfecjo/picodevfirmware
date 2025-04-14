#include <stdio.h>
#include "ssd1306.h"
#include "oled_setup.h"

ssd1306_t disp;

void setup_oled(void)
{
    disp.external_vcc = false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
}

void update_oled_info(int contador, int cliques)
{
    char linha1[20];
    char linha2[20];

    snprintf(linha1, sizeof(linha1), "Contador: %d", contador);
    snprintf(linha2, sizeof(linha2), "Cliques B: %d", cliques);

    ssd1306_clear(&disp);
    ssd1306_draw_string(&disp, 0, 10, 1, linha1);
    ssd1306_draw_string(&disp, 0, 30, 1, linha2);
    ssd1306_show(&disp);
}
