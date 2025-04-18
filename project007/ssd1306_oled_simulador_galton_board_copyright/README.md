## ⚠️ Important Note:
You may need to adjust the `CMakeLists.txt` file according to your development environment, as each setup might differ based on the developer's system configuration. Without these adjustments, the code may not behave as expected.

---

### 🚀 **Assignment**

### 📌 Galton Board Simulation on SSD1306 OLED Display

---

# Analysis of Galton Board Results

## Introduction

The Galton Board, also known as a Quincunx, is a mechanical device used to demonstrate the central limit theorem and the binomial distribution. It consists of a vertical board with pegs arranged in a triangular grid. As balls drop from the top and bounce left or right at each peg, they accumulate in bins at the bottom.

## Statistical Behavior

Each ball undergoes a series of independent binary decisions (left or right), creating a distribution of outcomes that approximates a binomial distribution. As the number of rows increases, this distribution tends to resemble a **normal (Gaussian) distribution**, due to the central limit theorem.

## Key Observations

- The **middle bins** accumulate the most balls.
- **Outer bins** (extremes) collect fewer balls.
- The distribution is **symmetrical**, assuming the board is not biased and each deflection has a 50/50 probability.
- The resulting shape is **bell-curved**, like a histogram of a normal distribution.

## Mathematical Model

For `n` levels (rows of pegs), and assuming each bounce has a 50% chance to go left or right, the probability of a ball landing in bin `k` (where `k` ranges from `0` to `n`) follows the binomial distribution:

![Galton Board - equação 01](./assets/formula1.jpg)

Where `C(n, k)` is the binomial coefficient:

![Galton Board - equação 01](./assets/formula2.jpg)

## Simulation Results (Example)

If a simulation drops 1000 balls with 10 rows of pegs, a possible result might be:

| Bin Index | Balls |
|-----------|-------|
| 0         | 2     |
| 1         | 13    |
| 2         | 55    |
| 3         | 125   |
| 4         | 210   |
| 5         | 240   |
| 6         | 210   |
| 7         | 125   |
| 8         | 55    |
| 9         | 13    |
| 10        | 2     |

This illustrates a distribution very close to the expected binomial shape.

## Conclusion

The Galton Board provides an intuitive and visual representation of fundamental statistical principles such as:

- **The binomial distribution**
- **The normal distribution as a limit**
- **Randomness and probability**
  
It is a powerful educational tool that shows how complex distributions emerge from simple, repeated random events.

---

## 🖥️ Platform
Raspberry Pi Pico / [BitDogLab](https://github.com/BitDogLab)

## 📦 Description
The **Galton Board Simulator** is a modular and interactive application that simulates the physics behind a Galton Board using an SSD1306 OLED display. The simulation demonstrates the fall of balls in a binomial distribution and visually represents it through dynamically updated histogram bars.

---

## 💡 Features

- ✅ Simulation of falling balls in a Galton Board
- ✅ Animated ball movement with collision detection
- ✅ Histogram bars that update dynamically
- ✅ Customizable parameters (number of bins, maximum height of bars)
- ✅ SSD1306 OLED display (128x64) via I2C for graphical output
- ✅ Written in C with embedded systems principles

---

## 🛠️ Logic Explanation

### Step-by-Step Logic

#### 1. **Animating the Falling Balls**
The balls fall down the columns, colliding with obstacles and gradually collecting in the histogram bins. The system uses random values to determine which bin each ball falls into, updating the histogram on each collision.

- The balls are animated using the `animate_ball` function, which handles the falling movement and changes in direction.
- The histogram is updated by incrementing the corresponding bin once the ball lands.
  
#### 2. **Histogram Update**
The histogram displays the number of balls in each column. Each bar's height is incremented when a ball reaches its respective bin. The bars are redrawn on the OLED display after each update.

---

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

![Galton Board](./assets/GaltonBoard.gif)