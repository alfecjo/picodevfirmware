# 🖥️ OLED Display with Raspberry Pi Pico

## 📘 Introduction

OLED (Organic Light-Emitting Diode) displays are compact, power-efficient screens that are perfect for embedded systems like the **Raspberry Pi Pico**. These displays are popular in IoT, wearables, and microcontroller projects due to their **clear contrast**, **low power consumption**, and **no need for backlight**.

In this document, we explain the **basic usage**, **initialization**, and **data display techniques** using an OLED screen with the Raspberry Pi Pico.

---

## 🔌 OLED Basics

- **Common Sizes**: 128x32 and 128x64 pixels
- **Color**: Monochrome (typically white or blue)
- **Interface**: I2C (or SPI)
- **I2C Address**: Usually `0x3C` or `0x3D`
- **Controller Chip**: SSD1306 (very common)

---

## 🔧 Wiring to the Raspberry Pi Pico

Here is a basic wiring example using I2C:

| OLED Pin | Description      | Pico Pin     |
|----------|------------------|--------------|
| GND      | Ground           | GND          |
| VCC      | Power Supply     | 3.3V (OUT)   |
| SCL      | Clock Line       | GP1 (I2C0 SCL) |
| SDA      | Data Line        | GP0 (I2C0 SDA) |

> Note: You can choose other I2C pins if needed, just configure them in your code.

---

## 📄 Required Libraries

You’ll need an SSD1306-compatible library such as:

- `ssd1306.h` for controlling the display
- `hardware/i2c.h` from the Pico SDK

---

## 🧰 Initializing the OLED

Here is a minimal example to initialize a 128x64 display over I2C:

```c
#include "ssd1306.h"
#include "hardware/i2c.h"

ssd1306_t disp;

void setup_oled(void) {
    disp.external_vcc = false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c0);
    ssd1306_clear(&disp);
}
