#ifndef SINTHETIZE_AUDIO_AC_HPP
#define SINTHETIZE_AUDIO_AC_HPP

#include <cstdint>
#include <array>

namespace AudioConfig {
    constexpr uint32_t DEFAULT_PWM_PIN= 2;

    constexpr uint32_t SAMPLE_RATE = 16000;
    constexpr uint32_t RECORD_DURATION = 4;
    constexpr uint32_t NUM_SAMPLES = SAMPLE_RATE * RECORD_DURATION;

    // Buffer global para armazenar o áudio capturado
    extern std::array<uint16_t, NUM_SAMPLES> audio_buffer;

}

#endif
