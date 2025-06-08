#include "hardware/adc.h"
#include "hardware/dma.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"

#include "pico/stdlib.h"
#include "capture_audio_setup.h"
#include "rgb_setup.h"
#include "oled_setup.h"

int dma_chan;

//=== Inicializa ADC e configura FIFO ===
void init_adc() {
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(2); // ADC2 corresponde ao GPIO28

    adc_fifo_setup(true, true, 1, false, false);
    adc_set_clkdiv(48000000.0f / (SAMPLE_RATE * 1.0f));  // Ex: 6.0 para 8 kHz
}

// === Configura o canal DMA para ler do ADC FIFO ===
void configure_dma(uint16_t *buffer) {
    dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);

    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_16);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_ADC);

    dma_channel_configure(
        dma_chan, &cfg,
        buffer,          // destino
        &adc_hw->fifo,   // origem
        NUM_SAMPLES,
        false            // não iniciar ainda
    );
}

// === Grava áudio no buffer ===
void record_audio(uint16_t *buffer) {
    set_led_state(LED_RED);
    //printf(">> Gravando áudio...\n");

    configure_dma(buffer);     // configura DMA para nova gravação
    adc_run(true);
    dma_channel_start(dma_chan);
    dma_channel_wait_for_finish_blocking(dma_chan);
    adc_run(false);
    adc_fifo_drain();

    //printf(">> Gravação finalizada.\n");

    display_waveform_envelope(buffer, NUM_SAMPLES);
}

