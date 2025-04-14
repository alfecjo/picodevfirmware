#include <stdio.h>
#include <stdint.h>

#include "pico/stdio.h"

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#include "i2c_setup.h"
#include "adc_setup.h"
#include "oled_setup.h"
#include "temperature.h"

// Callback da interrupção do timer
bool temperatura_callback(struct repeating_timer *t)
{
    float temperatura = read_temperature(); // Lê a temperatura
    float tensao = read_voltage();          // Lê a tensão

    printf("Temperatura: %.2f °C\n", temperatura); // Imprime a temperatura no console para debug
    printf("Tensão: %.3f V\n", tensao);            // Imprime a tensão no console para debug
    


    // Atualiza o display OLED
    update_oled(temperatura, tensao);

    return true; // Mantém o timer rodando
}

int main()
{
    // Inicializa todos stdio vinculados ao binário
    stdio_init_all();

    // Configurações iniciais
    setup_i2c0();
    setup_adc();
    setup_oled();

    // Criando o timer que chamará a função a cada 15 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(5000, temperatura_callback, NULL, &timer);

    while (1)
    {
        sleep_ms(60000); // Mantém o programa rodando sem travar o processador
    }

    return 0;
}
