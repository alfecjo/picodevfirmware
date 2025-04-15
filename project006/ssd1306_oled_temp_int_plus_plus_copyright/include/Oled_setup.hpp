#ifndef OLED_SETUP_H
#define OLED_SETUP_H

#include <cstdint>

extern "C"
{
#include "ssd1306.h"
}

class Oled_setup
{
public:
    void setup_oled(void);
    void update_oled(float temp, float tensao);
};

#endif
