# Tarefa: Roteiro de FreeRTOS #1 - EmbarcaTech 2025

Autor: **Antonio Carlos Ferreira de Almeida**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, 11 de junho de 2025

---

# Projeto: Sistema Multitarefa com FreeRTOS no Raspberry Pi Pico

Este projeto implementa um sistema multitarefa embarcado na BitDogLab (Raspberry Pi Pico), usando o sistema operacional de tempo real **FreeRTOS**. O sistema é desenvolvido em linguagem **C** utilizando o **Pico SDK** e **VSCode**, com foco em concorrência entre tarefas para controlar periféricos básicos.

---

## 🎯 Funcionalidades

- Controle cíclico de um **LED RGB** (verde → azul → vermelho).
- Emissão periódica de **bipes com buzzer**.
- Dois botões físicos:
  - **Botão A (GP5)**: Pausa/retoma a tarefa do LED.
  - **Botão B (GP6)**: Pausa/retoma a tarefa do buzzer.

---

## 📌 Pinagem Utilizada

| Periférico | Pino GPIO |
|------------|------------|
| LED Verde  | GP11       |
| LED Azul   | GP12       |
| LED Vermelho | GP13     |
| Buzzer     | GP10       |
| Botão A    | GP5        |
| Botão B    | GP6        |

---

## ⚙️ Configuração do Ambiente

### Pré-requisitos

- Raspberry Pi Pico SDK configurado
- CMake
- Compilador `arm-none-eabi-gcc`
- VSCode com extensão C/C++
- FreeRTOS Kernel

### Como adicionar o FreeRTOS

1. Baixe do site oficial: [FreeRTOS Download](https://www.freertos.org/Documentation/02-Kernel/01-About-the-FreeRTOS-kernel/03-Download-freeRTOS/01-DownloadFreeRTOS)

2. Copie as pastas:
   - `Source/include/`
   - `Source/portable/GCC/RISC-V/`
   - `Source/list.c`, `Source/queue.c`, `Source/tasks.c`

3. Organize na pasta `freertos/` conforme acima.

---

## 🔧 Compilação (prepare o CMakeLists.txt em acordo com seu ambiente...)

```bash
mkdir build
cd build
cmake ..
make
```

---

### 👨‍💻 Tarefas

- vTaskLED: alterna as cores do LED RGB.

- vTaskBuzzer: gera beeps no buzzer.

- vTaskBotaoA: monitora o botão A para suspender/retomar o LED.

- vTaskBotaoB: monitora o botão B para suspender/retomar o buzzer.

---

## 📜 Licença
GNU GPL-3.0.
