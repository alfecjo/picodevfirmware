#ifndef OLED_SETUP_H 
#define OLED_SETUP_H 

#include "ssd1306.h"         // Necessário para conhecer o tipo ssd1306_t
extern ssd1306_t disp;       // Permite que outros arquivos usem a variável disp

void setup_oled(void);
void update_oled(uint16_t valor_x, uint16_t valor_y);

#endif  
