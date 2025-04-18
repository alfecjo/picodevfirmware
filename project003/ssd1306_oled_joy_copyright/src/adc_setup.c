#include "hardware/adc.h"
#include "adc_setup.h"

void setup_adc()
{
    adc_init(); // Initialize ADC

    adc_set_temp_sensor_enabled(false); // Disable internal temperature sensor
}
