#ifndef OLED_SETUP_HPP
#define OLED_SETUP_HPP

#include <cstdint>
#include "config.hpp"

extern "C"
{
#include "ssd1306.h"
}

extern ssd1306_t disp; // Declara uma variável global para armazenar as configurações do display SSD1306

class Oled_setup
{
private:
    int counter = 0; // Contador para o número de animações

public:
    void setup_oled(void);

    void draw_bins(ssd1306_t *disp, uint8_t *bins, int num_bins, int max_height);

    int get_x_from_pos(ssd1306_t *disp, int pos);

    void draw_ball(ssd1306_t *disp, int x, int y);

    void animate_ball(ssd1306_t *disp, int *final_bin, uint8_t *bins);
};

#endif
