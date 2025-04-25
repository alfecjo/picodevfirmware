## ⚠️ Important Note:
You may need to adjust the `CMakeLists.txt` file according to your development environment, as each setup might differ based on the developer's system configuration. Without these adjustments, the code may not behave as expected.

---

### 🚀 **Assignment**

### 📌 Countdown Timer with Event Logging via Interrupts

---


### 🛠️ Logic Explanation

### 🎯 Write a program in C/C++ that implements a **countdown timer controlled by interrupts**, following this behavior:

# Enhanced Project001 – Raspberry Pi Pico W (C++ & OOP)

This project is an enhanced version of the original `project001`, designed specifically for the Raspberry Pi Pico W. It integrates both C and C++ code, transitioning from a procedural approach to an object-oriented one (OOP).

The core logic remains the same as the original project, but the architecture has been restructured using C++ classes and modern design patterns, such as the Singleton pattern. This encourages deeper exploration and understanding of C++ in the context of embedded systems development.

## 🔧 Key Features

- Uses C++ for encapsulating application logic in a clean and scalable way.
- Maintains compatibility with C-based SDK components via `extern "C"`.
- Integrates button input handling with hardware interrupts (GPIO).
- Implements debounce logic using `absolute_time_diff_us()`.
- Includes a timer-based display update loop with the `repeating_timer` API.
- Displays information on an SSD1306 OLED screen over I2C.

## 🚀 Purpose

This version aims to spark curiosity and experimentation in developers who are familiar with the Pico SDK in C and are looking to evolve into C++-based, object-oriented design practices. By mixing both C and C++, it becomes a practical gateway to:

- Learn how to structure firmware using C++ OOP principles.
- Understand integration between C-based libraries and C++ classes.
- Begin architecting larger and more maintainable embedded applications.


1. Every time **Button A (GPIO5)** is pressed:
   1. The countdown resets to **9**, and the value is shown on the **OLED display**.
   2. The system enters **active countdown mode**, decrementing the counter by 1 every second until it reaches 0.
   3. While the countdown is running (from 9 to 0):
      - The system should count how many times **Button B (GPIO6)** is pressed.
      - This number should also be displayed in real time on the OLED.
   4. When the countdown reaches **0**:
      - The system **freezes**.
      - Any additional Button B presses are **ignored** (they are not counted outside the countdown window).
   5. While frozen, the OLED displays:
      - The final countdown value: `0`.
      - The **total number of Button B presses** registered during the 9-second countdown window.
2. To restart the process:
   1. Press **Button A** again.
   2. The countdown is reset to **9**.
   3. The counter for Button B presses is also reset to **0**.
   4. A new countdown cycle begins.

### 🖼️ Hardware Setup

This section illustrates the hardware used in this project to help replicate the setup accurately.

### 🔧 Components Used

- Raspberry Pi Pico W or [BitDogLab](https://github.com/BitDogLab)
- SSD1306 OLED Display (I2C)
- Push buttons (x2)
- Breadboard and jumper wires
- USB cable (for power and programming)

---

### 📝 **The code was written in C/C++ and tested using the [BitDogLab](https://github.com/BitDogLab) platform.**

---

### 🔧 **Status**

✅ Tested – Working properly 🟢

---

### 📋 **Checklist of Test Cases That Supported Project Development**

- 🟢 Test 001 – Success! Time-based software debounce implemented.

---

### 🖼️ Hardware Setup

![Final tested project](./assets/project002.gif)

---

## 🐳 Run in a Containerized Environment

Tired of manual setups and toolchain installations? Want to skip the setup and run the projects in a ready-to-use development environment?

🚀 **Launch all projects using our custom Docker image with full Pico SDK support!**  
The image includes build tools, dependencies, and sample projects — all pre-configured.

👇 Visit the repository and get started now:  

<p align="center">
  <a href="https://github.com/alfecjo/rp2040-container">
    <img src="https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/raw/main/picodevbox.png" alt="PicoDevBox" width="200"/>
  </a>
</p>

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
  [![HBr 2025 Project](https://img.shields.io/badge/HBr_2025_Project-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)
