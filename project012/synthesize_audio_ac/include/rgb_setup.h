#ifndef RGB_SETUP_H
#define RGB_SETUP_H

#include "pico/stdlib.h"

#define GREEN_LED 11  // GP11
#define RED_LED   13  // GP13

typedef enum {
    LED_OFF,
    LED_RED,
    LED_GREEN,
} LedState;

void setup_led_rgb(void);
void set_led_state(LedState state);

#endif
