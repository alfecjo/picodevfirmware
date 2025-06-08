#include "rgb_setup.h"

//=== Inicializa ADC e configura Led ===
void setup_led_rgb(void)
{
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_put(GREEN_LED, 0);

    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_put(RED_LED, 0);
}

//=== Controla estado dos Led's ===
void set_led_state(LedState state)
{
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);

    switch (state)
    {
    case LED_RED:
        gpio_put(RED_LED, 1);
        break;
    case LED_GREEN:
        gpio_put(GREEN_LED, 1);
        break;
    case LED_OFF:
        gpio_put(GREEN_LED, 0);
        gpio_put(RED_LED, 0);
        break;
    default:
        // Todos já foram desligados acima
        break;
    }
}
