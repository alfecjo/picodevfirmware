# Pico W LED Blink Modular Project

This project demonstrates a modular architecture for controlling the onboard LED of the Raspberry Pi Pico W.  
It is organized into distinct layers: **drivers**, **HAL (Hardware Abstraction Layer)**, and **application logic**.

## 📁 Project Structure

```
led_toggle/
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

### 📋 Project Overview

## 🗂️ Directory Structure

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

---

## 🐳 Run, Maintain and Deploy the Application in a Docker Containerized EnvironmentRun in a Containerized Environment

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

![HBr](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/blob/main/hbr.jpg)

---

- ## Return to the main page
  [![HBr 2025 Project](https://img.shields.io/badge/HBr_2025_Project-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)
