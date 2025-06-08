#ifndef CAPTURE_AUDIO_SETUP_HPP
#define CAPTURE_AUDIO_SETUP_HPP

#include "pico/stdlib.h"
#include "RgbLed.hpp"
#include "OledDisplay.hpp"
#include "AudioConfig.hpp"

class CaptureAudioSetup {
public:
    static constexpr uint ADC_PIN = 28;
    
    // Usando constantes do namespace AudioConfig
    static constexpr uint SAMPLE_RATE = AudioConfig::SAMPLE_RATE;
    static constexpr uint RECORD_DURATION = AudioConfig::RECORD_DURATION;
    static constexpr uint NUM_SAMPLES = AudioConfig::NUM_SAMPLES;

    CaptureAudioSetup();

    void configure_dma(uint16_t* buffer);
    void record_audio();

private:
    int dma_chan = -1;
    RgbLed led;
    OledDisplay oled;
};

#endif // CAPTURE_AUDIO_SETUP_HPP
