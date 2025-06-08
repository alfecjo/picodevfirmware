#ifndef AUDIO_PLAYBACK_H
#define AUDIO_PLAYBACK_H

#include <stdint.h>
#include "audio_config.h"


#define PWM_PIN 10

void init_pwm(void);
void play_audio(const uint16_t *buffer, size_t num_samples);

#endif