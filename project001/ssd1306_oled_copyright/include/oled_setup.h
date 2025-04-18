#ifndef OLED_SETUP_H // Prevent multiple inclusions
#define OLED_SETUP_H


void setup_oled(void); // Initializes OLED (defined in oled_setup.c)


void update_oled_info(int contador, int cliques); // Updates OLED display with the current counter and clicks (defined in oled_setup.c)

#endif
