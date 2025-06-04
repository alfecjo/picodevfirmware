#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "i2c_setup.h"

void i2c_setup() {
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
}
