## ⚠️ Important Note:
You may need to adjust the `CMakeLists.txt` file according to your development environment, as each setup might differ based on the developer's system configuration. Without these adjustments, the code may not behave as expected.

---

# 🎙️ BitDogLab Audio Recorder – C++ Version

This project implements an **audio recorder and player** using the **BitDogLab platform (Raspberry Pi Pico)**, developed with a modern **C++ approach**, focusing on **object-oriented design, modular architecture**, and **code reusability**.

The system leverages **classes and encapsulation** to handle hardware components such as the ADC, PWM, buttons, RGB LED, and OLED display, making the codebase **cleaner, more scalable**, and easier to maintain.

> 💡 Compared to the structured C version, this implementation **uses C++ features** such as constructors, encapsulated member functions, and abstraction layers, while still respecting the constraints of embedded systems programming.

## 📦 Features

- 🎚️ **Audio recording** using encapsulated ADC controller (adjustable sampling rate)
- 🔊 **Audio playback** via PWM driver class
- 🎛️ **User control via hardware abstraction classes**:
  - `RecordButton`: triggers recording
  - `PlayButton`: triggers playback
- 🌈 **RGB LED feedback controller**:
  - Red: recording
  - Green: playback
  - Off: idle
- 📺 **Waveform display module** renders recorded signal on an OLED screen

## 🧰 Components Used

- **Raspberry Pi Pico (BitDogLab)**
- **RP2040 internal ADC**
- **OLED display** (I2C, encapsulated in `DisplayDriver` class)
- **RGB LED controller** class
- **Button handler** class (debounced, interrupt-based)
- **PWM audio output** class
- **DMA manager** for efficient data transfer

---

## 📊 C vs C++ Design Comparison

| Feature / Aspect               | Structured C Version                            | C++ Object-Oriented Version                              |
|-------------------------------|--------------------------------------------------|-----------------------------------------------------------|
| **Programming Style**         | Procedural                                       | Object-Oriented                                           |
| **Code Structure**            | Flat, function-based                             | Modular, class-based                                     |
| **Hardware Abstraction**      | Direct register access in functions              | Encapsulated in classes (e.g., `ADCController`, `LED`)   |
| **Reusability**               | Low                                              | High (e.g., reusable classes across projects)            |
| **Maintainability**           | Moderate (depends on discipline)                 | High (encapsulation aids long-term scalability)          |
| **Performance**               | High (minimal abstraction overhead)              | Slightly lower, but optimized for embedded use cases     |
| **Learning Focus**            | Emphasizes hardware control and low-level logic  | Emphasizes architecture, abstraction, clean design       |
| **Use of C++ Features**       | None                                             | Classes, constructors, private/public access, methods    |

---

> 🧭 Choose the version that fits your learning goals:
> - Use **C** for mastering low-level embedded control.
> - Use **C++** to design scalable and maintainable firmware for larger projects.

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

### 📽️ Video... 

[![Vídeo de Apresentação do Projeto](https://github.com/alfecjo/picodevfirmware/blob/main/project013/synthesize_audio_plus_plus__copyright/assets/syntetize%20C%2B%2B.png)](https://www.youtube.com/watch?v=ZfnCZQWFPbg)

---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/) Embedded Systems Student**

[![HBr - Serviços](https://github.com/alfecjo/picodevfirmware/blob/main/project000/antonio_almeida_embarcatech_HBr_2025_fase_1/hbr.jpg)](https://hardware.org.br/servicos/)

Have suggestions or found a bug?
Feel free to contribute or open an [issue](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025/issues). 🚀

---

- ## Return to the main page
  [![HBr 2025 Project](https://img.shields.io/badge/HBr_2025_Project-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/antonio_almeida_embarcatech_HBr_2025)

