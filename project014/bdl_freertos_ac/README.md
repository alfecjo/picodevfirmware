# Project: Multitasking System with FreeRTOS on [BitDogLab](https://github.com/BitDogLab/BitDogLab)

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

---

## 🐳 Run, Maintain and Deploy the Application in a Docker Containerized Environment

Tired of manual setups and toolchain installations? Want to skip the setup and run the projects in a ready-to-use development environment?

🚀 **Launch all projects using our custom Docker image with full Pico SDK support!**  
The image includes build tools, dependencies, and sample projects — all pre-configured.

👇 Visit the repository and get started now:  

<p align="center">
  <a href="https://github.com/alfecjo/rp2040-container">
    <img src="https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/raw/main/picodevbox.png" alt="PicoDevBox" width="200"/>
  </a>
</p>

- 💡 Use this container to compile, test, and develop your Raspberry Pi Pico and [BitDogLab](https://github.com/BitDogLab/BitDogLab) projects instantly — no manual installations needed!
- 🛠️ Created and maintained by the author of this project to simplify and accelerate development.

---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/) Embedded Systems Student**

[![HBr - Serviços](https://github.com/alfecjo/picodevfirmware/blob/main/project000/antonio_almeida_embarcatech_HBr_2025_fase_1/hbr.jpg)](https://hardware.org.br/servicos/)

Have suggestions or found a bug?
Feel free to contribute or open an [issue](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/issues). 🚀

---

- ## Return to the main page
  [![HBr 2025 Project](https://img.shields.io/badge/HBr_2025_Project-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)
