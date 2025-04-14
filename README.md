# 🚀 EmbarcaTech 2025 - Phase II

[![GitHub Pages](https://img.shields.io/badge/GitHub-Pages-blue?logo=github)](https://alfecjo.github.io/antonio_almeida_embarcatech_HBr_2025/)

## 📚 Objective
This repository showcases the **Embedded Systems** projects developed in **EmbarcaTech 2025 - Phase II**. Here, you will find source code, documentation, and resources used in the development of these systems.

## 🔗 Projects
Below is a list of developed projects. Each has its own directory within the repository:

## 🎯 Project Objective
Each project's purpose and specific goals are described in detail inside its own directory.  
To learn more about a project, refer to its individual `README.md` file located within the project's folder.

## 📂 Repository Structure
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
│── /project002
│   │── /ssd1306_oled__plus_plus_copyright
│       │── assets               # Images, Videos, and Diagrams
│       │── docs                 # Technical Documentation
│       ├── include/             # Headers (.h, .hpp)
│       ├── src/                 # Main source code (.c, .cpp)
│       ├── CMakeLists.txt       # Configuração do projeto
│       ├── README.md            # Project Overview
│── /project003
│   │── /ssd1306_oled_joy_copyright
│       │── assets               # Images, Videos, and Diagrams
│       │── docs                 # Technical Documentation
│       ├── include/             # Headers (.h, .hpp)
│       ├── src/                 # Main source code (.c, .cpp)
│       ├── CMakeLists.txt       # Configuração do projeto
│       ├── README.md            # Project Overview
│── /project003
│   │── /ssd1306_oled_temp_int_copyright
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
- [Project002 - ssd1306_oled_copyright_plus](./project002/ssd1306_oled__plus_plus_copyright/)
- [Project003 - ssd1306_oled_joy_copyright](./project003/ssd1306_oled_joy_copyright/)
- [Project004 - ssd1306_oled_temp_int_copyright](./project004/ssd1306_oled_temp_int_copyright/)

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

## 🔌 Uploading Firmware to the Raspberry Pi Pico W

1. **Connect** your Raspberry Pi Pico W to your computer via USB while holding down the **BOOTSEL** button.
2. The device will mount as a USB mass storage device (usually named `RPI-RP2`).
3. **Copy** the compiled `.uf2` firmware file to the mounted drive.
4. Once the transfer is complete, the Pico W will automatically reboot and begin running the new firmware.

> 💡 **Tip:** This firmware is part of the current project and can eventually be tested or integrated with the [BitDogLab](https://github.com/BitDogLab) environment as needed.


## 👤 Author
**Antonio Almeida - Hbr Campinas**

Have suggestions or found a bug?
Feel free to contribute or open an [issue](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/issues). 🚀
