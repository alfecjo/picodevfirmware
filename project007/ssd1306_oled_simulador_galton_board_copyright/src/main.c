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
    stdio_init_all(); // Initialize stdio
    setup_i2c(); // Initialize I2C
    setup_oled(); // Initialize OLED
    
    uint32_t seed = to_us_since_boot(get_absolute_time()); // Seed for random number generation
    srand(seed); // Seed the random number generator

    uint8_t bins[NUM_BINS] = {0}; // Array to hold the counts for each bin

    while (1)
    {
        int final_bin = 0;
        animate_ball(&disp, &final_bin, bins); // Animate the ball and get the final bin

        // Increment the count for the final bin
        bins[final_bin]++;

        // Check if the bin count exceeds the maximum height
        draw_bins(&disp, bins, NUM_BINS, MAX_HEIGHT);

        sleep_ms(300);
    }

    return 0;
}
