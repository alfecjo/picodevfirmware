#include <stdio.h>
#include "ssd1306.h"
#include "oled_setup.h"

ssd1306_t disp;

void setup_oled(void)
{
    disp.external_vcc = false;                         // Use internal VCC
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);           // Init display (128x64, I2C addr 0x3C)
    ssd1306_clear(&disp);                              // Clear screen
}

void update_oled_info(int contador, int cliques)
{
    char linha1[20];
    char linha2[20];

    snprintf(linha1, sizeof(linha1), "Contador: %d", contador); // Format line 1
    snprintf(linha2, sizeof(linha2), "Cliques B: %d", cliques); // Format line 2

    ssd1306_clear(&disp);                              // Clear screen
    ssd1306_draw_string(&disp, 0, 10, 1, linha1);       // Draw line 1
    ssd1306_draw_string(&disp, 0, 30, 1, linha2);       // Draw line 2
    ssd1306_show(&disp);                               // Refresh screen
}
