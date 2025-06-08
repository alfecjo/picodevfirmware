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

If you're looking for a version implemented in **C++ with higher-level abstractions**, consider exploring the [C++-based variant](#) which introduces encapsulation, modularity, and reusable components.
