#ifndef RGB_LED_HPP
#define RGB_LED_HPP

#include "hardware/gpio.h"
#include "pico/stdlib.h"

enum LedColor
{
    OFF,
    RED,
    GREEN
};

class RgbLed
{
public:
    RgbLed();
    void initLed();
    void setColorLed(LedColor color);

private:

    static constexpr uint GREEN_LED = 11; // GP11
    static constexpr uint RED_LED = 13;   // GP13
};

#endif