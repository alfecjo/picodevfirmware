#include <stdlib.h>
#include <stdio.h>
#include "ssd1306.h"
#include "oled_setup.h"

ssd1306_t disp; // Display object

static int counter = 0; // Animation counter

// Initialize the display
void setup_oled(void)
{
    disp.external_vcc = false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
}

// Draw a ball at the specified position
void draw_ball(ssd1306_t *disp, int x, int y)
{
    char buffer[4];
    snprintf(buffer, sizeof(buffer), "%d", counter);
    ssd1306_draw_string(disp, x, y, 1, buffer);
}

// Draw bars representing bins
void draw_bins(ssd1306_t *disp, uint8_t *bins, int num_bins, int max_height)
{
    ssd1306_clear(disp);

    for (int i = 0; i < num_bins; i++)
    {
        int height = bins[i];
        if (height > max_height)
            height = max_height;

        int x_start = i * (disp->width / num_bins);
        int bar_width = (disp->width / num_bins) - 1;

        for (int h = 0; h < height; h++)
        {
            int y = disp->height - 1 - h;
            for (int w = 0; w < bar_width; w++)
            {
                ssd1306_draw_pixel(disp, x_start + w, y);
            }
        }
        char bin_count_str[4];
        snprintf(bin_count_str, sizeof(bin_count_str), "%d", bins[i]);

        int text_x = x_start + (bar_width / 2) - 3;
        int text_y = disp->height - height - 10;

        if (text_y < 0)
            text_y = 0;

        if (bins[i] != 0)
            ssd1306_draw_string(disp, text_x, text_y, 1, bin_count_str);
    }

    ssd1306_show(disp);
}

// Get x position of a bin
int get_x_from_pos(ssd1306_t *disp, int pos)
{
    int bin_width = disp->width / NUM_BINS;
    return pos * bin_width + bin_width / 2;
}

// Animate a ball bouncing in the bins
void animate_ball(ssd1306_t *disp, int *final_bin, uint8_t *bins)
{
    int pos = NUM_BINS / 2;

    for (int level = 0; level < NUM_LEVELS; level++)
    {
        if (rand() % 2 == 0)
            pos++;
        else
            pos--;

        if (pos < 0)
            pos = 0;
        if (pos >= NUM_BINS)
            pos = NUM_BINS - 1;

        // Calculate ball position
        int x = get_x_from_pos(disp, pos);
        int y = level * (disp->height / (NUM_LEVELS + 1));

        // Stop when collision with bar (if collision detection is enabled)
        if (DISABLE_COLLISION_DETECTION)
        {
            int bar_height = bins[pos];
            int bar_y = disp->height - bar_height;
            if (y >= bar_y)
            {
                break;
            }
        }

        // Redraw screen
        ssd1306_clear(disp);
        draw_bins(disp, bins, NUM_BINS, MAX_HEIGHT);
        draw_ball(disp, x, y);
        ssd1306_show(disp);

        sleep_ms(100);
    }
    *final_bin = pos;
    counter++;
}
