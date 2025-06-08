## ⚠️ Important Note:
You may need to adjust the `CMakeLists.txt` file according to your development environment, as each setup might differ based on the developer's system configuration. Without these adjustments, the code may not behave as expected.

---

# 🎙️ BitDogLab Audio Recorder

This project implements an **audio recorder and player** using the **BitDogLab platform (Raspberry Pi Pico W)**, developed primarily in **structured C** — emphasizing **low-level, procedural programming** rather than object-oriented approaches.

The system interacts with the user through **physical buttons**, provides **visual feedback via an RGB LED**, and **displays the recorded waveform on an OLED screen** during playback.

> 🛠️ This version was designed with a focus on **C language fundamentals**, in contrast to C++-based implementations. It prioritizes **explicit control over hardware**, **manual memory management**, and **direct register access**, as typically seen in embedded C projects.

## 📦 Features

- 🎚️ **Audio recording** using the internal ADC (with adjustable sampling rate - tests with 12k and 16k)
- 🔊 **Audio playback** through PWM output
- 🎛️ **User interaction via physical buttons**:
  - `RECORD BUTTON`: starts recording
  - `PLAY BUTTON`: plays back the recorded audio
- 🌈 **Visual feedback via RGB LED**:
  - Red: recording
  - Green: playback
  - Off: idle
- 📺 **Real-time waveform visualization** of the recorded signal on an OLED display

## 🧰 Components Used

- **Raspberry Pi Pico (BitDogLab)**
- **RP2040 internal ADC**
- **OLED display** (I2C interface)
- **RGB LED**
- **Physical buttons** (GPIO-controlled)
- **PWM output** for audio playback
- **DMA** for efficient ADC sampling

---

If you're looking for a version implemented in **C++ with higher-level abstractions**, consider exploring the [C++-based variant](https://github.com/alfecjo/picodevfirmware/tree/main/project013/synthesize_audio_plus_plus__copyright) which introduces encapsulation, modularity, and reusable components.

---

### 📽️ Video... 

[![Vídeo de Apresentação do Projeto](https://github.com/alfecjo/picodevfirmware/blob/main/project012/synthesize_audio_ac/assets/syntetize%20C.png)](https://www.youtube.com/watch?v=dL5RZdOgLoE)

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
