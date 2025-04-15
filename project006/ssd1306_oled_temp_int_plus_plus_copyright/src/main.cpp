#include <stdio.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#include "Temperature.hpp"
#include "Oled_setup.hpp"
#include "I2c_setup.hpp"
#include "Adc_setup.hpp"

struct CallbackData {
    Temperature temp;
    Oled_setup* oled;
};

bool temperatura_callback(struct repeating_timer *timer)
{
    auto* data = static_cast<CallbackData*>(timer->user_data);

    float temperatura = data->temp.read_temperature();
    float tensao = data->temp.read_voltage();

    // Debug: Imprime os valores lidos
    printf("Temperatura: %.2f °C\n", temperatura);
    printf("Tensão: %.3f V\n", tensao);

    data->oled->update_oled(temperatura, tensao);

    return true;
}

int main()
{
    stdio_init_all();

    I2c_setup i2c;
    Adc_setup adc;
    Oled_setup oled;

    i2c.setup_i2c();
    adc.setup_adc();
    oled.setup_oled();

    static CallbackData cb_data{
        Temperature(),
        &oled
    };    

    struct repeating_timer timer;
    if (!add_repeating_timer_ms(5000, temperatura_callback, &cb_data, &timer)) {
        printf("Erro ao iniciar o timer!\n"); // Para debug
    }
    
    while (true) {
        tight_loop_contents();
    }
}