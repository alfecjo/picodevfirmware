#include "ButtonManager.hpp"
#include "hardware/gpio.h"

ButtonManager::ButtonManager(uint gpioRecord, uint gpioPlay)
    : recordPin(gpioRecord), playPin(gpioPlay)
{
    initButtons(); // chama o método privado que inicializa os GPIOs
}

void ButtonManager::initButtons()
{
    gpio_init(recordPin);
    gpio_set_dir(recordPin, GPIO_IN);
    gpio_pull_up(recordPin);

    gpio_init(playPin);
    gpio_set_dir(playPin, GPIO_IN);
    gpio_pull_up(playPin);
}

bool ButtonManager::isRecordPressed()
{
    return !gpio_get(recordPin); // botão pressionado = nível baixo
}

bool ButtonManager::isPlayPressed()
{
    return !gpio_get(playPin);
}
