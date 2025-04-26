# Pico W LED Blink Modular Project

This project demonstrates a modular architecture for controlling the onboard LED of the Raspberry Pi Pico W.  
It is organized into distinct layers: **drivers**, **HAL (Hardware Abstraction Layer)**, and **application logic**.

## 📁 Project Structure

```
project/
├── app/
│   └── main.c
├── drivers/
│   └── led_embutido.c
├── hal/
│   └── hal_led.c
├── include/
│   ├── led_embutido.h
│   └── hal_led.h
└── CMakeLists.txt
```

## 📋 Project Overview

- 🗂️ Directory Structure

- drivers/:
Direct access to hardware (led_embutido.c).

- hal/:
Hardware Abstraction Layer that provides clean, reusable functions (hal_led.c).

- app/:
Main application logic (main.c).

- include/:
Header files (.h) for drivers and HAL.

- CMakeLists.txt:
Configures and builds the entire project.

## 🚀 Final Result

- The onboard LED blinks every 500 ms.

- The main application only uses high-level functions (hal_led_toggle()).

- Implementation details of the LED control are properly separated across layers:

 - drivers → HAL → app

## 🎯 Key Takeaway

- Clear separation between hardware access and application logic improves code maintainability, scalability, and readability.