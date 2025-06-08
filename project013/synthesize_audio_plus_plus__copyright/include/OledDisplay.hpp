#ifndef OLED_DISPLAY_HPP
#define OLED_DISPLAY_HPP

#include <cstdint>
#include <cstddef>
#include "RgbLed.hpp"

extern "C"
{
#include "ssd1306.h"
}

extern ssd1306_t disp; // Declara uma variável global para armazenar as configurações do display SSD1306

class OledDisplay
{
public:
    OledDisplay(); // Construtor
    void init();
    void displayWaveformEnvelope(uint16_t *samples, size_t totalSamples, RgbLed &led);

private:
    static constexpr int WIDTH = 128;
    static constexpr int HEIGHT = 64;
    static constexpr int LIMIAR_DE_RUIDO = 100;
};

#endif
