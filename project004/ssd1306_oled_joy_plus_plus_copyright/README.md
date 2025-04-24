## ⚠️ Important Note:
You may need to adjust the CMakeLists.txt file according to your development environment. Each setup might differ depending on system configurations, toolchain versions, or the integration of C and C++ codebases. Without these adjustments, the code may not behave as expected.

---

## Overview

The objective of this project is to read analog joystick values using a Raspberry Pi Pico W (or [BitDogLab](https://github.com/BitDogLab)) and display the results on both the serial terminal and an OLED screen via I2C. The joystick’s analog values are digitized through an ADC (Analog-to-Digital Converter), allowing real-time monitoring and interaction.

This hybrid implementation integrates C and C++, simulating a common enterprise environment where embedded firmware (in C) interacts with system-level components or UI logic (in C++), promoting modularity and scalability.

---

## 🧠 Logic Flow – Hybrid Embedded Architecture

## Enhanced Project004 – Raspberry Pi Pico W or [BitDogLab](https://github.com/BitDogLab)

## Step-by-Step Logic

### 1. **Reading Joystick Values**

The program configures I2C and ADC peripherals for reading joystick input and communicating with the OLED display. The joystick provides analog signals on two axes:

X-axis: connected to GPIO26 (ADC0)

Y-axis: connected to GPIO27 (ADC1)

These values, ranging from 0 to 4095, represent the joystick’s full range of movement. They are sampled at fixed intervals (500 ms).

### 2. **Mapping Joystick Movement to Directions**

After reading the raw values of the joystick (X and Y), the program maps these values to specific directions, which will be displayed on the OLED:

- **Horizontal Movement** (X-axis):
  - If `X < 500`, the joystick is moved to the **left**.
  - If `X > 3500`, the joystick is moved to the **right**.
  - Otherwise, the joystick is in a **central** position.

- **Vertical Movement** (Y-axis):
  - If `Y < 500`, the joystick is moved **down**.
  - If `Y > 3500`, the joystick is moved **up**.
  - Otherwise, the joystick is in a **central** position.

### 3. **Displaying Values**

The program updates the OLED display to show both the **raw X and Y values** and the **direction of movement**. The output on the display is updated every 500 milliseconds, showing the current joystick position.

- **Terminal Output:**
  - The program prints the joystick’s raw X and Y values in the terminal for debugging purposes. 
  - Additionally, the direction of movement is shown on the OLED display.

### 4. **OLED Display**

The OLED display shows two lines of information:
1. **Line 1**: Displays the raw values of `X` and `Y`.
2. **Line 2**: Displays the direction of the joystick movement, such as "Up", "Down", "Left", "Right", or "Center".

This real-time feedback allows users to visually track the joystick’s movement and direction.

## Summary

In summary, this program allows you to:
- Read the joystick’s digital values for both X and Y axes.
- Map these values to directional movement (Up, Down, Left, Right, or Center).
- Display the raw values and movement direction both on the terminal and on an OLED screen.
- Continuously update the display every 500 milliseconds for real-time tracking.

This simple yet effective logic makes it easy to monitor joystick movements for various applications, such as controlling robots or navigating menus in embedded systems.

### 🖼️ Hardware Setup

This section illustrates the hardware used in this project to help replicate the setup accurately.

### 🔧 Components Used

- Raspberry Pi Pico W or [BitDogLab](https://github.com/BitDogLab)
- SSD1306 OLED Display (I2C)
- Joystick
- Breadboard and jumper wires
- USB cable (for power and programming)

---

### 📝 **The code was written in C and tested using the [BitDogLab](https://github.com/BitDogLab) platform.**

---

### 🔧 **Status**

✅ Tested – Working properly 🟢

---

### 📋 **Checklist of Test Cases That Supported Project Development**

- 🟢 Test 001 – Success!

---

### 🖼️ Hardware Setup

![Final tested project](./assets/project004.gif)

---

## 🐳 Run in a Containerized Environment

Tired of manual setups and toolchain installations? Want to skip the setup and run the projects in a ready-to-use development environment?

🚀 **Launch all projects using our custom Docker image with full Pico SDK support!**  
The image includes build tools, dependencies, and sample projects — all pre-configured.

👉 Visit the repository and get started now:  
[📦 rp2040-container - BitDogLab Environment](https://github.com/alfecjo/rp2040-container)

- 💡 Use this container to compile, test, and develop your Raspberry Pi Pico and [BitDogLab](https://github.com/BitDogLab) projects instantly — no manual installations needed!
- 🛠️ Created and maintained by the author of this project to simplify and accelerate development.

---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/) Student**

![HBr](./assets/hbr.jpg)

Have suggestions or found a bug?
Feel free to contribute or open an [issue](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/issues). 🚀

---

- ## Return to the main page
  - [Embarcatech HBr 2025 Project](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)
