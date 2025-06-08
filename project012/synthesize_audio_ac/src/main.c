#include <stdio.h>
#include "pico/stdlib.h"

#include "oled_setup.h"
#include "i2c_setup.h"
#include "rgb_setup.h"
#include "buttons_setup.h"
#include "capture_audio_setup.h"
#include "audio_playback.h"
#include "audio_config.h"

uint16_t audio_buffer[NUM_SAMPLES];

// === Função principal ===
int main() {
    stdio_init_all();
    init_adc();
    init_pwm();
    init_buttons();
    setup_i2c0();  
    setup_oled();  
    setup_led_rgb();

    //printf("Sistema iniciado.\n");

     while (true) {
        if (!gpio_get(BUTTON_RECORD)) {
            sleep_ms(150);
            record_audio(audio_buffer);
            set_led_state(LED_OFF);
        }

        if (!gpio_get(BUTTON_PLAY)) {
            sleep_ms(150);
            play_audio(audio_buffer, NUM_SAMPLES);
            set_led_state(LED_OFF);
        }
        sleep_ms(100);
    }
}