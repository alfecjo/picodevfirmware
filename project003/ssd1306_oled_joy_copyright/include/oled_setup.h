#ifndef OLED_SETUP_H   // Prevents multiple inclusions
#define OLED_SETUP_H

#include "ssd1306.h"         // Required for ssd1306_t type
extern ssd1306_t disp;       // Makes 'disp' accessible from other files

void setup_oled(void);       // Initializes the OLED display
void update_oled(uint16_t valor_x, uint16_t valor_y); // Updates display with X and Y values

#endif
