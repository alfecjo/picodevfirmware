#ifndef AUDIO_CONFIG_H
#define AUDIO_CONFIG_H

#include <stdint.h>

#define SAMPLE_RATE     22000
#define RECORD_DURATION 4
#define NUM_SAMPLES     (SAMPLE_RATE * RECORD_DURATION)

extern uint16_t audio_buffer[NUM_SAMPLES];

#endif
