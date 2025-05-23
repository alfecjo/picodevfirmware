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
    // Initialize all stdio associated with the binary
    stdio_init_all();

    // Initial setup configurations
    setup_i2c0();
    setup_adc();
    setup_oled();

    joystick_t joy;

    while (1)
    {
        joy = read_joystick(); // Read joystick values

        // Display joystick values in the terminal
        printf("Joystick X: %d | Y: %d\n", joy.x, joy.y);

        update_oled(joy.x, joy.y); // Update OLED display with joystick values
        
        sleep_ms(500); // Wait for 500ms
    }

    return 0;
}
