#ifndef OLED_SETUP_H  
#define OLED_SETUP_H

#include <ssd1306.h>
#include "config.h"
#include "stdint.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

extern ssd1306_t disp; // Display object

void setup_oled(void); // Function to initialize the OLED display

void draw_bins(ssd1306_t* disp, uint8_t* bins, int num_bins, int max_height); // Draw the bins on the display

int get_x_from_pos(ssd1306_t *disp, int pos); // Get the x coordinate for a given bin position

void draw_ball(ssd1306_t *disp, int x, int y); // Draw the ball on the display

void animate_ball(ssd1306_t *disp, int *final_bin, uint8_t *bins); // Animate the ball falling into the final bin

#endif
