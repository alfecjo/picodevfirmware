#ifndef OLED_SETUP_H
#define OLED_SETUP_H

#include <stdint.h>
#include <stddef.h>
#include "ssd1306.h"

#define LIMIAR_DE_RUIDO 100

extern ssd1306_t disp;

void setup_oled(void);
void display_waveform_envelope(uint16_t *samples, size_t total_samples);

#endif
