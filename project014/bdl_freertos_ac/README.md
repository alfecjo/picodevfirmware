# Project: Multitasking System with FreeRTOS on Raspberry Pi Pico

This project implements an embedded multitasking system on the BitDogLab (Raspberry Pi Pico), using the real-time operating system **FreeRTOS**.  
The system is developed in **C** language using the **Pico SDK** and **VSCode**, focusing on task concurrency to control basic peripherals.

---

## 🎯 Features

- Cyclic control of an **RGB LED** (green → blue → red).
- Periodic **beeping via buzzer**.
- Two physical buttons:
  - **Button A (GP5)**: Pauses/resumes the LED task.
  - **Button B (GP6)**: Pauses/resumes the buzzer task.

---

## 📌 Pinout Used

| Peripheral    | GPIO Pin |
|---------------|-----------|
| Green LED     | GP11      |
| Blue LED      | GP12      |
| Red LED       | GP13      |
| Buzzer        | GP10      |
| Button A      | GP5       |
| Button B      | GP6       |

---

## ⚙️ Environment Setup

### Prerequisites

- Raspberry Pi Pico SDK properly configured
- CMake
- `arm-none-eabi-gcc` toolchain
- VSCode with C/C++ extension
- FreeRTOS Kernel

### How to Add FreeRTOS

1. Download from the official website:  
   👉 [FreeRTOS Download](https://www.freertos.org/Documentation/02-Kernel/01-About-the-FreeRTOS-kernel/03-Download-freeRTOS/01-DownloadFreeRTOS)

2. Copy the following folders and files to your project:
   - `Source/include/`
   - `Source/portable/GCC/RISC-V/`
   - `Source/list.c`, `Source/queue.c`, `Source/tasks.c`

3. Organize them inside your `freertos/` directory accordingly.
