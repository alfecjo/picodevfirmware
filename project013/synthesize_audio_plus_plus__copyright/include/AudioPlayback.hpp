#ifndef AUDIO_PLAYBACK_HPP
#define AUDIO_PLAYBACK_HPP

#include <stdint.h>
#include <stddef.h>
#include "RgbLed.hpp"
#include "AudioConfig.hpp"

class AudioPlayback {
public:
    AudioPlayback(uint pwmPin = AudioConfig::DEFAULT_PWM_PIN,
                  RgbLed* led = nullptr,
                  uint sampleRate = AudioConfig::SAMPLE_RATE);
    void initPWM();
    void playAudio(const uint16_t* buffer, size_t numSamples);

private:
    uint pwmPin;
    uint sampleRate;
    RgbLed* led;
    uint pwmSlice;
};

#endif
