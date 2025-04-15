#include "hardware/adc.h"
#include "Joystick.hpp"

Joystick::State Joystick::read() const
{
    State joy;

    adc_select_input(0);            // GPIO26
    joy.x = adc_read();

    adc_select_input(1);            // GPIO27
    joy.y = adc_read();

    return joy;
}
