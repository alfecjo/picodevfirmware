#include "hardware/adc.h"
#include "Adc_setup.hpp"

void Adc_setup::setup_adc()
{
    adc_init(); // Inicializa o ADC

    adc_set_temp_sensor_enabled(false); // Desativa o sensor de temperatura interno
}