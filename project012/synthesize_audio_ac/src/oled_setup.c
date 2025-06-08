#include "oled_setup.h"
#include "rgb_setup.h"
#include "ssd1306.h"

ssd1306_t disp;

//=== Inicializa configura OLED ===
void setup_oled(void)
{
    disp.external_vcc = false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
    ssd1306_show(&disp);
}

//=== Define amostragem ===
void display_waveform_envelope(uint16_t *samples, size_t total_samples)
{
    const int DISPLAY_WIDTH = 128;
    const int DISPLAY_HEIGHT = 64;

    const size_t samples_per_column = total_samples / DISPLAY_WIDTH;

    bool encontrou_sinal_forte = false;

    ssd1306_clear(&disp);

    for (int x = 0; x < DISPLAY_WIDTH; x++)
    {
        size_t start = x * samples_per_column;
        size_t end = start + samples_per_column;
        if (end > total_samples)
            end = total_samples;

        uint16_t min_val = 4095;
        uint16_t max_val = 0;

        for (size_t i = start; i < end; i++)
        {
            uint16_t val = samples[i];
            if (val < min_val)
                min_val = val;
            if (val > max_val)
                max_val = val;
        }

        if ((max_val - min_val) < LIMIAR_DE_RUIDO)
        {
            min_val = 2048;
            max_val = 2048;
        }
        else
        {
            encontrou_sinal_forte = true; // Detecção de áudio real
        }

        // Normaliza para a altura do display (0-63)
        int y_min = (min_val * DISPLAY_HEIGHT) / 4095;
        int y_max = (max_val * DISPLAY_HEIGHT) / 4095;

        ssd1306_draw_line(&disp, x, y_min, x, y_max);
    }

    // Linha média de referência
    ssd1306_draw_line(&disp, 0, DISPLAY_HEIGHT / 2, DISPLAY_WIDTH - 1, DISPLAY_HEIGHT / 2);
    ssd1306_show(&disp);

    // LED verde acende se houver som detectado
    if (encontrou_sinal_forte)
        set_led_state(LED_GREEN);
    else
        set_led_state(LED_OFF);
}
