#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "i2c_setup.h"

void setup_i2c0(void)
{
    i2c_init(i2c1, 400000);               // Initialize I2C1 at 400kHz
    gpio_set_function(14, GPIO_FUNC_I2C); // Set GPIO 14 for I2C
    gpio_set_function(15, GPIO_FUNC_I2C); // Set GPIO 15 for I2C
    gpio_pull_up(14);                     // Enable pull-up on GPIO 14
    gpio_pull_up(15);                     // Enable pull-up on GPIO 15
}
