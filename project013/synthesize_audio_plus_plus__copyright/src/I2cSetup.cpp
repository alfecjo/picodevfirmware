#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "I2cSetup.hpp"

I2cSetup::I2cSetup() {
    init();
}

void I2cSetup::init() {
    i2c_init(i2c1, FREQUENCY);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
}
