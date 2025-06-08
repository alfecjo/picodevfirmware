#include <cstdio>
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "AudioPlayback.hpp"
#include "RgbLed.hpp"
#include "AudioConfig.hpp"

AudioPlayback::AudioPlayback(uint pwmPin, RgbLed* led, uint sampleRate)
    : pwmPin(pwmPin), sampleRate(sampleRate), led(led) {
    if (this->led == nullptr) {
        static RgbLed defaultLed; // instância local estática usada como fallback
        this->led = &defaultLed;
    }
}

void AudioPlayback::initPWM() {
    gpio_set_function(pwmPin, GPIO_FUNC_PWM);
    pwmSlice = pwm_gpio_to_slice_num(pwmPin);
    pwm_set_wrap(pwmSlice, 255);       // 8-bit resolução
    pwm_set_clkdiv(pwmSlice, 1.40f);   // ~31.25kHz para 125MHz
    pwm_set_enabled(pwmSlice, true);
}

void AudioPlayback::playAudio(const uint16_t* buffer, size_t numSamples) {
    led->setColorLed(GREEN);
    printf(">> Reproduzindo áudio...\n");

    for (size_t i = 0; i < numSamples; ++i) {
        uint8_t sample = buffer[i] >> 4;  // 12 bits → 8 bits
        pwm_set_gpio_level(pwmPin, sample);
        sleep_us(1000000 / sampleRate);
    }

    pwm_set_gpio_level(pwmPin, 0); // silêncio após reprodução
    led->setColorLed(OFF);
    printf(">> Reprodução finalizada.\n");
}
