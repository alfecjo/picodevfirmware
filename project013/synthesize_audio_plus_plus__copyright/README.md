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
