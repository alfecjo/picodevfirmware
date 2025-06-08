project( synthesize_audio_plus_plus_ac C CXX ASM)

# Cria o executável com os arquivos-fonte
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/AudioConfig.cpp
        src/I2cSetup.cpp
        src/OledDisplay.cpp
        src/ssd1306.c
        src/RgbLed.cpp
        src/CaptureAudioSetup.cpp
        src/AudioPlayback.cpp
        src/ButtonsManager.cpp
        )

# Diretórios de inclusão
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

# Vincula bibliotecas necessárias
target_link_libraries(${PROJECT_NAME}
        pico_stdlib
        hardware_adc
        hardware_i2c
        hardware_dma
        hardware_pwm
        hardware_gpio
        )

pico_add_extra_outputs(${PROJECT_NAME})

# (Opcional) Define a URL do exemplo
example_auto_set_url(${PROJECT_NAME})

# Habilita suporte à USB para saída padrão (stdout via USB serial)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)  # Desativa UART, se desejar apenas USB