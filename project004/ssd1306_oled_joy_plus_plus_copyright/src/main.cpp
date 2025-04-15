#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <sstream>

#include "Adc_setup.hpp"
#include "Oled_setup.hpp"
#include "Joystick.hpp"
#include "I2c_setup.hpp"

extern "C" {
    #include "pico/stdlib.h"
    #include "hardware/i2c.h"
    #include "hardware/adc.h"
    
    #include "ssd1306.h"
}

// Opcional: encapsular leitura do joystick
int main() {
    stdio_init_all();

    I2c_setup i2c_setup;
    Adc_setup adc_setup;
    Oled_setup oled_setup;
    Joystick joystick;
    
    i2c_setup.setup_i2c0();
    adc_setup.setup_adc();
    oled_setup.setup_oled();

    while (true) {
        auto joy = joystick.read();
        std::cout << "Joystick X: " << joy.x << " | Y: " << joy.y << std::endl;
        oled_setup.update_oled(joy.x, joy.y);
        sleep_ms(500);
    }

    return 0;
}