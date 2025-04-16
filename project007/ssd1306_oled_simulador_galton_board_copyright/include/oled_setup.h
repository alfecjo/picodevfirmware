#ifndef OLED_SETUP_H  
#define OLED_SETUP_H

#include <ssd1306.h>

#define NUM_BINS 16
#define MAX_HEIGHT 50
#define NUM_LEVELS 10
#define BALL_RADIUS 2

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

extern ssd1306_t disp; // Declara uma variável global para armazenar as configurações do display SSD1306

void setup_oled(void);

void update_oled(float);

void draw_bins(ssd1306_t* disp, uint8_t* bins, int num_bins, int max_height);

int get_x_from_pos(int pos);

void draw_ball(ssd1306_t *disp, int x, int y);

void animate_ball(ssd1306_t *disp, int *final_bin, uint8_t *bins);

#endif
