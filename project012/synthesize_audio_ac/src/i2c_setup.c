#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "i2c_setup.h"

//=== Inicializa ADC e configura I2C ===
void setup_i2c0(void)
{
    i2c_init(i2c1, 400000);               
    gpio_set_function(14, GPIO_FUNC_I2C); 
    gpio_set_function(15, GPIO_FUNC_I2C); 
    gpio_pull_up(14);                     
    gpio_pull_up(15);                     
}
