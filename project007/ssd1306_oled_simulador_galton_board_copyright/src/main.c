#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#include "i2c_setup.h"
#include "oled_setup.h"

int main()
{
    stdio_init_all();
    setup_i2c();
    setup_oled();
    
    uint32_t seed = to_us_since_boot(get_absolute_time());
    srand(seed);

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
