#include "hardware/gpio.h"
#include "buttons_setup.h"


// === Inicializa os botões ===
void init_buttons() {
    gpio_init(BUTTON_RECORD);
    gpio_set_dir(BUTTON_RECORD, GPIO_IN);
    gpio_pull_up(BUTTON_RECORD);

    gpio_init(BUTTON_PLAY);
    gpio_set_dir(BUTTON_PLAY, GPIO_IN);
    gpio_pull_up(BUTTON_PLAY);
}
