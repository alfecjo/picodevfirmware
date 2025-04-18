#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "i2c_setup.h"

void setup_i2c0(void)
{
    i2c_init(i2c1, 400000);               // Init I2C1 at 400kHz
    gpio_set_function(14, GPIO_FUNC_I2C); // Set GPIO14 as I2C
    gpio_set_function(15, GPIO_FUNC_I2C); // Set GPIO15 as I2C
    gpio_pull_up(14);                     // Enable pull-up on GPIO14
    gpio_pull_up(15);                     // Enable pull-up on GPIO15
}
