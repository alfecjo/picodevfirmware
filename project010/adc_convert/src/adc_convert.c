#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "adc.h"

int main() {
    // Inicialização do Raspberry Pi Pico
    stdio_init_all();  // Inicializa a comunicação padrão (USB ou UART)
    
    // Configure o ADC aqui
    adc_init();
    adc_gpio_init(26);  // Configure o pino ADC (pino 26 do Pico)
    adc_select_input(0);  // Seleciona o canal de ADC desejado
    
    while (1) {
        // Leitura do valor do ADC
        uint16_t result = adc_read();
        
        // Converte o valor do ADC para temperatura
        float temperature = adc_to_celsius(result);
        
        // Imprime o valor da temperatura
        printf("Temperature: %.2f°C\n", temperature);
        
        // Pausa por 1 segundo
        sleep_ms(1000);
    }
}
