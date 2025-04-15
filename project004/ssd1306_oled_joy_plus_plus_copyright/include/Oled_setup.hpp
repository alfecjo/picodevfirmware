#ifndef OLED_SETUP_H
#define OLED_SETUP_H

#include <cstdint>
#include "ssd1306.h"

class Oled_setup
{
public:
    void setup_oled(void);
    void update_oled(uint16_t valor_x, uint16_t valor_y);
};

#endif
