#include <stdio.h>
#include "pico/stdlib.h"

#include "OledDisplay.hpp"
#include "I2cSetup.hpp"
#include "RgbLed.hpp"
#include "ButtonManager.hpp"
#include "AudioConfig.hpp"
#include "AudioPlayback.hpp"
#include "CaptureAudioSetup.hpp"

// === Função principal ===
int main()
{
    stdio_init_all();

    const uint GPIO_RECORD = 5;
    const uint GPIO_PLAY = 6;

    
    RgbLed led;
    AudioPlayback player(10, &led, AudioConfig::SAMPLE_RATE);
    player.initPWM();
    
    I2cSetup i2cSetup;
    
    OledDisplay oledDisplay;
    
    CaptureAudioSetup audioCapture; 

    ButtonManager buttonManager(GPIO_RECORD, GPIO_PLAY);

    printf("Sistema iniciado.\n");


    while (true)
    {
        if (buttonManager.isRecordPressed())
        {
            printf("Botão de gravação pressionado!\n");
            audioCapture.record_audio();
            led.setColorLed(RED); // Indica gravação em andamento com LED vermelho
            sleep_ms(3000);
        }

        if (buttonManager.isPlayPressed())
        {
            printf("Botão de reprodução pressionado!\n");
            player.playAudio(AudioConfig::audio_buffer.data(), AudioConfig::NUM_SAMPLES);
            sleep_ms(3000);
        }

        sleep_ms(100);
    }
}