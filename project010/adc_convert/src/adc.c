#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// Função para converter o valor do ADC para temperatura em Celsius
float adc_to_celsius(uint16_t adc_val) {
    float voltage = (adc_val * 3.3f) / 4095.0f;  // Converte o valor ADC para tensão
    float temperature = 27.0f - (voltage - 0.706f) / 0.001721f;  // Converte a tensão para temperatura
    return temperature;
}
