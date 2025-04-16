#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#include "i2c_setup.h"
#include "oled_setup.h"

#define NUM_BINS 16
#define MAX_HEIGHT 50

int main()
{
    stdio_init_all();
    setup_i2c();
    setup_oled();
    srand(time(NULL));

    uint8_t bins[NUM_BINS] = {0};

    while (1)
    {
        int final_bin = 0;
        animate_ball(&disp, &final_bin, bins);

        // Atualiza bin
        bins[final_bin]++;

        // Redesenha histograma por cima
        draw_bins(&disp, bins, NUM_BINS, MAX_HEIGHT);

        sleep_ms(300);
    }

    return 0;
}
