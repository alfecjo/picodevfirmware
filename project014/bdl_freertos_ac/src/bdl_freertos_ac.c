#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// LED RGB - GP13 (R), GP11 (G), GP12 (B)
#define LED_R 13
#define LED_G 11
#define LED_B 12

// Buzzer - GP10
#define BUZZER 10

// Botões
#define BTN_LED 5
#define BTN_BUZZER 6

TaskHandle_t led_task_handle = NULL;
TaskHandle_t buzzer_task_handle = NULL;

void init_gpio() {
    gpio_init(LED_R); gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G); gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B); gpio_set_dir(LED_B, GPIO_OUT);
    gpio_init(BUZZER); gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_init(BTN_LED); gpio_set_dir(BTN_LED, GPIO_IN); gpio_pull_up(BTN_LED);
    gpio_init(BTN_BUZZER); gpio_set_dir(BTN_BUZZER, GPIO_IN); gpio_pull_up(BTN_BUZZER);
}

void set_rgb(bool r, bool g, bool b) {
    gpio_put(LED_R, r);
    gpio_put(LED_G, g);
    gpio_put(LED_B, b);
}

void led_task(void *params) {
    while (1) {
        set_rgb(1, 0, 0); vTaskDelay(pdMS_TO_TICKS(500)); // Vermelho
        set_rgb(0, 1, 0); vTaskDelay(pdMS_TO_TICKS(500)); // Verde
        set_rgb(0, 0, 1); vTaskDelay(pdMS_TO_TICKS(500)); // Azul
    }
}

void buzzer_task(void *params) {
    while (1) {
        gpio_put(BUZZER, 1);
        vTaskDelay(pdMS_TO_TICKS(100));
        gpio_put(BUZZER, 0);
        vTaskDelay(pdMS_TO_TICKS(900));
    }
}

void button_task(void *params) {
    bool led_suspended = false;
    bool buzzer_suspended = false;

    while (1) {
        // Botão A - LED
        if (gpio_get(BTN_LED) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50)); // debounce
            if (!led_suspended) {
                vTaskSuspend(led_task_handle);
                led_suspended = true;
            } else {
                vTaskResume(led_task_handle);
                led_suspended = false;
            }
            while (gpio_get(BTN_LED) == 0); // espera soltar
        }

        // Botão B - Buzzer
        if (gpio_get(BTN_BUZZER) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50)); // debounce
            if (!buzzer_suspended) {
                vTaskSuspend(buzzer_task_handle);
                buzzer_suspended = true;
            } else {
                vTaskResume(buzzer_task_handle);
                buzzer_suspended = false;
            }
            while (gpio_get(BTN_BUZZER) == 0); // espera soltar
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

int main() {
    stdio_init_all();
    init_gpio();

    xTaskCreate(led_task, "LED Task", 256, NULL, 1, &led_task_handle);
    xTaskCreate(buzzer_task, "Buzzer Task", 256, NULL, 1, &buzzer_task_handle);
    xTaskCreate(button_task, "Button Task", 256, NULL, 2, NULL);

    vTaskStartScheduler();

    while (true); 
}
