#include "RgbLed.hpp"

RgbLed::RgbLed()
{
    initLed();
}

void RgbLed::initLed(){
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_put(GREEN_LED, 0);

    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_put(RED_LED, 0);
}

//=== Controla estado dos Led's ===
void RgbLed::setColorLed(LedColor color){
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);

    switch (color)
    {
    case RED:
        gpio_put(RED_LED, 1);
        break;
    case GREEN:
        gpio_put(GREEN_LED, 1);
        break;
    case OFF:        
        break;
    default:
        // Ambos já estão desligados acima
        break;
    }
}