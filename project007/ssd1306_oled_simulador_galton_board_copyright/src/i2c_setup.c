#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "i2c_setup.h"

void setup_i2c(void)
{
    i2c_init(i2c1, 400000);               // Initialize I2C1 with 400kHz speed
    gpio_set_function(14, GPIO_FUNC_I2C); // Pin 14 for I2C
    gpio_set_function(15, GPIO_FUNC_I2C); // Pin 15 for I2C
    gpio_pull_up(14);                     // Pull-up resistor on pin 14
    gpio_pull_up(15);                     // Pull-up resistor on pin 15
}
