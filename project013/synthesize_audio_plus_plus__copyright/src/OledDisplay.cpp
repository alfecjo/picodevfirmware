#include "hardware/i2c.h"

#include "OledDisplay.hpp"
#include "RgbLed.hpp"
extern "C"
{
#include "ssd1306.h"
}

ssd1306_t disp;

OledDisplay::OledDisplay() {
    disp.external_vcc = false;
    init();
}

void OledDisplay::init() {
    ssd1306_init(&disp, WIDTH, HEIGHT, 0x3C, i2c1);
    ssd1306_clear(&disp);
    ssd1306_show(&disp);
}

void OledDisplay::displayWaveformEnvelope(uint16_t* samples, size_t totalSamples, RgbLed& led) {
    const size_t samplesPerColumn = totalSamples / WIDTH;
    bool encontrouSinalForte = false;

    ssd1306_clear(&disp);

    for (int x = 0; x < WIDTH; x++) {
        size_t start = x * samplesPerColumn;
        size_t end = start + samplesPerColumn;
        if (end > totalSamples)
            end = totalSamples;

        uint16_t minVal = 4095;
        uint16_t maxVal = 0;

        for (size_t i = start; i < end; i++) {
            uint16_t val = samples[i];
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
        }

        if ((maxVal - minVal) < LIMIAR_DE_RUIDO) {
            minVal = 2048;
            maxVal = 2048;
        } else {
            encontrouSinalForte = true;
        }

        int yMin = (minVal * HEIGHT) / 4095;
        int yMax = (maxVal * HEIGHT) / 4095;

        ssd1306_draw_line(&disp, x, yMin, x, yMax);
    }

    ssd1306_draw_line(&disp, 0, HEIGHT / 2, WIDTH - 1, HEIGHT / 2);
    ssd1306_show(&disp);

    if (encontrouSinalForte)
        led.setColorLed(GREEN);
    else
        led.setColorLed(OFF);
}
