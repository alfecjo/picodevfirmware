#include "hardware/adc.h"
#include "adc_setup.h"

void setup_adc()
{
    adc_init(); // Inicializa o ADC

    adc_set_temp_sensor_enabled(false); // Desativa o sensor de temperatura interno
}