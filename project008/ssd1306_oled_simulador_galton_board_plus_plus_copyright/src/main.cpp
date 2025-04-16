#include <stdint.h>
#include <stdlib.h>
#include <time.h>

extern "C"
{
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
}

#include "I2c_setup.hpp"
#include "Oled_setup.hpp"

#define NUM_BINS 16
#define MAX_HEIGHT 50

int main()
{
    I2c_setup i2c_setup;
    Oled_setup oled_setup;

    stdio_init_all();
    i2c_setup.setup_i2c();
    oled_setup.setup_oled();
    srand(time(NULL));

    uint8_t bins[NUM_BINS] = {0};

    while (1)
    {
        int final_bin = 0;
        oled_setup.animate_ball(&disp, &final_bin, bins);

        // Atualiza bin
        bins[final_bin]++;

        // Redesenha histograma por cima
        oled_setup.draw_bins(&disp, bins, NUM_BINS, MAX_HEIGHT);

        sleep_ms(300);
    }

    return 0;
}
