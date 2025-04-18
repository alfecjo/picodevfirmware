#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "Temperature.hpp"

Temperature::Temperature() {
    adc_init();
    adc_select_input(4);
}

float Temperature::read_temperature(void)
{
    const float conversion_factor = 3.3f / (1 << 12); 
    uint16_t raw = adc_read();                        
    float voltage = raw * conversion_factor;          

    return 27.0f - (voltage - 0.706f) / 0.001721f; 
}

float Temperature::read_voltage(void){
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t raw = adc_read();                       
    float voltage = raw * conversion_factor;         

    return voltage;
}
