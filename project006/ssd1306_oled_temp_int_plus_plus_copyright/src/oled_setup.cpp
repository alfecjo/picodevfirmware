#include <stdio.h>

#include "Oled_setup.hpp"


ssd1306_t disp;

void Oled_setup::setup_oled(void)
{
    
    disp.external_vcc = false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);

    ssd1306_clear(&disp);
}

void Oled_setup::update_oled(float temp, float tensao)
{
    char display_str[20];
    char display_str1[20];

    snprintf(display_str, sizeof(display_str), "RP2040: %.2f C.", temp);
    snprintf(display_str1, sizeof(display_str1), "Vac: %.3f volts.", tensao);

    ssd1306_clear(&disp);

    ssd1306_draw_string(&disp, 0, 0, 1, display_str);
    ssd1306_draw_string(&disp, 0, 16, 1, display_str1);

    ssd1306_show(&disp);
}