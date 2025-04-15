#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "Temperature.hpp"

Temperature::Temperature() {
    adc_init();         // Inicializa o ADC
    adc_select_input(4); // O sensor de temperatura interno está no canal 4
}

float Temperature::read_temperature(void)
{
    const float conversion_factor = 3.3f / (1 << 12); // Fator de conversão para 12 bits
    uint16_t raw = adc_read();                        // Lê o valor bruto do ADC
    float voltage = raw * conversion_factor;          // Converte para tensão

    return 27.0f - (voltage - 0.706f) / 0.001721f; // Converte para temperatura
}

float Temperature::read_voltage(void){
    const float conversion_factor = 3.3f / (1 << 12); // Fator de conversão para 12 bits
    uint16_t raw = adc_read();                        // Lê o valor bruto do ADC
    float voltage = raw * conversion_factor;          // Converte para tensão

    return voltage; // Retorna a tensão lida
}
