#include <stdio.h>
#include <string.h> 

#include "ssd1306.h"
#include "oled_setup.h"

// Global display structure
ssd1306_t disp; // Declares a global variable to store SSD1306 display settings

void setup_oled(void)
{
    // Configure the display power
    disp.external_vcc = false; // Sets whether the display uses external power (false means it uses internal power)

    // Initialize the SSD1306 display
    // Parameters: &disp (configuration structure), 128 (width), 64 (height), 0x3C (I2C address), i2c1 (I2C bus used)
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);

    // Clear the display screen
    ssd1306_clear(&disp); // Clears any content on the screen
}

void update_oled(uint16_t valor_x, uint16_t valor_y) {
    char linha1[20];
    char linha2[20];
    char direcao[20] = "Centro"; // Default direction is "Center"

    // Format the joystick values as string for display
    snprintf(linha1, sizeof(linha1), "X:%4u Y:%4u", valor_x, valor_y);

    // Direction based on joystick position
    if (valor_x < 500 && valor_y < 500)
        strcpy(direcao, "Baixo Esq");
    else if (valor_x < 500 && valor_y > 3500)
        strcpy(direcao, "Baixo Dir");
    else if (valor_x > 3500 && valor_y < 500)
        strcpy(direcao, "Cima Esq");
    else if (valor_x > 3500 && valor_y > 3500)
        strcpy(direcao, "Cima Dir");
    else if (valor_x < 500)
        strcpy(direcao, "Baixo");
    else if (valor_x > 3500)
        strcpy(direcao, "Cima");
    else if (valor_y < 500)
        strcpy(direcao, "Esquerda");
    else if (valor_y > 3500)
        strcpy(direcao, "Direita");

    snprintf(linha2, sizeof(linha2), "Mov: %s", direcao);

    // OLED update
    ssd1306_clear(&disp); // Clear the display
    ssd1306_draw_string(&disp, 0, 8, 1, linha1); // Display X, Y values
    ssd1306_draw_string(&disp, 0, 32, 1, linha2); // Display direction
    ssd1306_show(&disp); // Show the updated display

    // Debug print
    printf("RAW VALUES - X: %u, Y: %u\n", valor_x, valor_y);
    printf(">>> CALCULATED DIRECTION: '%s'\n", direcao);
}
