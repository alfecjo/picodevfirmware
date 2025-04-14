#include <stdio.h>
#include <stdint.h>

#include "pico/stdio.h"

#include "pico/stdlib.h"

#include "i2c_setup.h"
#include "adc_setup.h"
#include "oled_setup.h"
#include "joystick.h"

#include "ssd1306.h"

int main()
{
    // Inicializa todos stdio vinculados ao binário
    stdio_init_all();

    // Configurações iniciais
    setup_i2c0();
    setup_adc();
    setup_oled();

    joystick_t joy;

    while (1)
    {
        joy = read_joystick();

        // Mostra no terminal
        printf("Joystick X: %d | Y: %d\n", joy.x, joy.y);

        update_oled(joy.x, joy.y);
        
        sleep_ms(500);
    }

    return 0;
}