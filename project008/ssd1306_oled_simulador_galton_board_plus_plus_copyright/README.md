## ⚠️ Important Note:
You may need to adapt your CMakeLists.txt or build system based on your specific development environment. System-specific configurations (e.g., I2C bus, OLED wiring, SDK path) may require manual setup to ensure proper execution.

---

### 🚀 **Assignment**

### 📌 Galton Board Simulation on SSD1306 OLED Display (Hybrid C/C++ with OOP)

---

# 🧠 Project – **Galton Board Simulator** with SSD1306 OLED Display

## 🖥️ Platform
Raspberry Pi Pico / [BitDogLab](https://github.com/BitDogLab/BitDogLab)

## 📦 Description
The **Galton Board Simulator** is a modular and interactive application that simulates the physics behind a Galton Board using an SSD1306 OLED display. The simulation demonstrates the fall of balls in a binomial distribution and visually represents it through dynamically updated histogram bars.

---

## ✨ Features

- 🎯 Animated Galton board simulation
- 🔄 Realistic ball movement with left/right randomization
- 📊 Histogram that updates dynamically with each ball
- ⚙️ Adjustable parameters (bins, ball size, animation speed)
- 🖥️ Graphical output on SSD1306 OLED via I2C
- 🧩 Written in modular **C++** with embedded principles

---

## 🧠 Simulation Logic

### ⚙️ Step-by-Step Process

#### 1. Ball Animation
- Balls start at the top center of the screen.
- At each obstacle level, they randomly move left or right.
- Once a ball reaches the bottom, the corresponding bin is incremented.
- Simple collision handling ensures balls stack if bins are full.

#### 2. Histogram Rendering
- Each frame clears and redraws the screen.
- Histogram bars represent the count of balls in each bin.
- Display updated using `ssd1306_show()`.

#### 3. Customization Options

You can tune these values in the code:

```cpp
#define NUM_BINS       16      // Number of histogram bins
#define MAX_HEIGHT     50      // Maximum height of a bar
#define NUM_LEVELS     10      // Levels of obstacles
#define BALL_RADIUS     2      // Size of the ball
```

## 🖼️ Hardware Setup

This section illustrates the hardware used in this project to help replicate the setup accurately.

### 🔧 Components Used

- **Raspberry Pi Pico**
- **SSD1306 OLED Display** (I2C)
- **USB cable** (for power and programming)

---

## 💡 Customization

You can modify the following parameters in the code to adjust the simulation to your needs:

- **Number of Bins**: The number of columns in the histogram.
- **Maximum Bar Height**: Adjust the height of the histogram bars.
- **Ball Size**: Increase or decrease the ball's size.
- **Animation Speed**: Modify the delay between frames for the animation.

---

## 🧑‍💻 Code Walkthrough

💡 This project serves as an excellent example of **embedded systems engineering** using the **Raspberry Pi Pico** platform and the **Pico SDK** framework. It allows dynamic data visualization through an OLED display, being highly customizable and ideal for exploring concepts of physics, statistical simulations, and embedded device programming.

### 🔧 **Status**

✅ Tested – Working properly 🟢

---

### 📋 **Checklist of Test Cases That Supported Project Development**

- 🟢 Test 001 – Success! Time-based.

---

### 🖼️ Hardware Setup

<p align="center">
  <img src="./assets/project008.gif" alt="Final tested project" />
</p>

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

[![HBr - Serviços](https://github.com/alfecjo/picodevfirmware/blob/main/project000/antonio_almeida_embarcatech_HBr_2025_fase_1/hbr.jpg)](https://hardware.org.br/servicos/)

Have suggestions or found a bug?
Feel free to contribute or open an [issue](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/issues). 🚀

---

- ## Return to the main page
  [![HBr 2025 Project](https://img.shields.io/badge/HBr_2025_Project-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)
