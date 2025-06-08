#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "audio_playback.h"
#include "rgb_setup.h"


// === Inicializa saída PWM para reprodução ===
void init_pwm() {
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_wrap(slice, 255);             // 8-bit resolução
    pwm_set_clkdiv(slice, 1.40f);          // ~31.25kHz para sysclk de 125MHz
    pwm_set_enabled(slice, true);
}

// === Reproduz o áudio do buffer ===
void play_audio(const uint16_t *buffer, size_t num_samples) {
    set_led_state(LED_GREEN);
    //printf(">> Reproduzindo áudio...\n");

    for (int i = 0; i < num_samples; i++) {
        uint8_t sample = buffer[i] >> 4;  // 12 bits -> 8 bits (0-4095 → 0-255)
        pwm_set_gpio_level(PWM_PIN, sample);

        sleep_us(1000000 / SAMPLE_RATE);  // delay para 8kHz
    }

    pwm_set_gpio_level(PWM_PIN, 0); // silêncio após reprodução
    set_led_state(LED_OFF);
   //printf(">> Reprodução finalizada.\n");
}
