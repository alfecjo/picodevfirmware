#ifndef CAPTURE_AUDIO_SETUP_H  
#define CAPTURE_AUDIO_SETUP_H  

#include <stdint.h>
#include "audio_config.h"


#define ADC_PIN 28
#define RECORD_DURATION 4       // 4 segundos


void init_adc(void);
void configure_dma(uint16_t *buffer);
void record_audio(uint16_t *buffer);

#endif 