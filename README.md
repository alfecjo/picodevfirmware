# 🚀 EmbarcaTech 2025 - Phase II

[![GitHub Pages](https://img.shields.io/badge/GitHub-Pages-blue?logo=github)](https://alfecjo.github.io/antonio_almeida_embarcatech_HBr_2025/)

## 📚 Objective
This repository showcases the **Embedded Systems** projects developed in **EmbarcaTech 2025 - Phase II**. Here, you will find source code, documentation, and resources used in the development of these systems.

## 📂 Repository Structure


## 🔗 Projects
Below is a list of developed projects. Each has its own directory within the repository:

## 🎯 Project Objective
Describe the purpose and goals of the project here.

## 🔧 Components Used
- List the components or hardware used in the project (e.g., Raspberry Pi Pico W, sensors, actuators, etc.).

```
/projects
│── /project001
│   │── /ssd1306_oled_copyright
│       │── assets               # Images, Videos, and Diagrams
│       │── docs                 # Technical Documentation
│       ├── include/             # Headers (.h, .hpp)
│       ├── src/                 # Main source code (.c, .cpp)
│       ├── CMakeLists.txt       # Configuração do projeto
│       ├── README.md            # Project Overview
│── README.md  (General repository explanation)
├── LICENSE
```

- [Project001 - ssd1306_oled_copyright](./project001/ssd1306_oled_copyright/)

## 🖼️ Hardware Setup
Suggestion: Include a **general picture of the kit** or the **setup used** in the projects. This can help with experiment replication.

## 🛠️ Requirements and Setup
To compile and run the projects on the **Raspberry Pi Pico W**, follow these steps:

1. **Install the Pico SDK** following the official Raspberry Pi instructions.

2. Clone this repository:
   ```bash
   git clone https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025.git
   cd antonio_almeida_embarcatech_HBr_2025/project001/ssd1306_oled_copyright
   ```

3. **Create the build directory and compile:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Upload the firmware to the Raspberry Pi Pico W.**

### 🔌 Uploading Firmware to the Raspberry Pi Pico W

1. **Connect** your Raspberry Pi Pico W to your computer via USB while holding down the **BOOTSEL** button.
2. The device will mount as a USB mass storage device (usually named `RPI-RP2`).
3. **Copy** the compiled `.uf2` firmware file to the mounted drive.
4. Once the transfer is complete, the Pico W will automatically reboot and begin running the new firmware.

> 💡 **Tip:** This firmware is part of the current project and can eventually be tested or integrated with the [BitDogLab](https://github.com/BitDogLab) environment as needed.


## 👤 Author
**Antonio Almeida - Hbr Campinas**

If you have any questions or suggestions, feel free to contribute or open an _issue_. 🚀
