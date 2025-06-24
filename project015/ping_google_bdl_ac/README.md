## ⚠️ Important Note – Required Environment Variables

To run this example successfully, it is **mandatory to configure a few environment variables** before compilation. These ensure the application runs exactly as shown in the video:

- `WIFI_SSID` – The name of the Wi-Fi network.
- `WIFI_PASSWORD` – The password for that network.
- *(Optional)* `PING_ADDR` – The IP or hostname to be pinged (default: `8.8.8.8`).

You can set these either:

- **Directly in the source code** for local testing,
- Or preferably via **compile-time definitions** in your `CMakeLists.txt` using `target_compile_definitions()`.

> 🔒 **Security Tip:** Avoid storing sensitive credentials in versioned files. Use environment variables or `.env` files (and add them to `.gitignore`).

---

## 🧵 Tasks Created

Once FreeRTOS is initialized, two main tasks are launched:

- **`main_task`**  
  Responsible for **connecting the device to Wi-Fi in station mode**.  
  Once connected, it initializes the **ICMP ping module** using the **lwIP stack (RAW API)** to monitor latency to Google’s DNS: `8.8.8.8`.

- **`oled_ping_task`**  
  A dedicated task to **update the OLED display via I²C**.  
  It constantly checks the `oled_needs_update` flag and, if set, updates two lines of text using the `update_oled_text()` function.

---

## 🧱 Architecture

The project adheres to solid embedded design principles:

- **High Cohesion**  
  Each task has a **well-defined single responsibility** (Wi-Fi/ping or OLED), which makes the code easier to **maintain, extend, and debug**.

- **Low Coupling**  
  Tasks operate independently and **do not block each other**. Each task manages its own scope and relies only on shared state when necessary — **no blocking calls between tasks**.

- **Modularity & Scalability**  
  The design makes it easy to add **new peripherals, sensors, or services**, supporting evolving project requirements.

---

## ⚙️ Runtime Behavior

- FreeRTOS runs on top of the Pico SDK, using **core 0** by default.
- Tasks are **scheduled cooperatively** using `vTaskDelay()`.
- Communication between the **network stack and the display** happens through **shared global variables**, updated via callbacks in `ping.c`.

> ✅ This approach ensures **minimal coupling**, allowing any task to read the shared state without needing to be tightly integrated.

---

## ✅ Benefits

- **Responsive OLED UI**, thanks to the dedicated task that offloads display updates.
- **Clean separation of concerns**, making the application **easy to understand and extend**.
- **Reusable and portable code**, adaptable to other FreeRTOS-compatible platforms with Wi-Fi + I²C/OLED support.
- **Strong foundation for further expansion**, including logging, sensor integration, or system diagnostics.

---

> 💡 *This project showcases how modern embedded systems can efficiently integrate networking, multitasking, and visual feedback using FreeRTOS — proving that with the right structure, the sky is the limit.*

---

## 📽️ Video Demonstration

[![Project Demo Video](https://github.com/EmbarcaTech-2025/tarefa-freertos-2-antonio-almeida/blob/main/assets/ping.png)](https://www.youtube.com/watch?v=GLwqQY0oyi4)

---

*BDL = BitDogLab, the board used for educational and prototyping purposes.*

---

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
