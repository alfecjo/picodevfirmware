#include <stdint.h>
#include <stdlib.h>
#include <time.h>

extern "C"
{
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
}

#include "config.hpp"
#include "I2c_setup.hpp"
#include "Oled_setup.hpp"

int main()
{
    I2c_setup i2c_setup;
    Oled_setup oled_setup;

    stdio_init_all();
    i2c_setup.setup_i2c();
    oled_setup.setup_oled();

    uint32_t seed = to_us_since_boot(get_absolute_time());
    srand(seed);

    uint8_t bins[NUM_BINS] = {0};

    while (1)
    {
        int final_bin = 0;
        oled_setup.animate_ball(&disp, &final_bin, bins);

        bins[final_bin]++;
        
        oled_setup.draw_bins(&disp, bins, NUM_BINS, MAX_HEIGHT);

        sleep_ms(300);
    }

    return 0;
}
