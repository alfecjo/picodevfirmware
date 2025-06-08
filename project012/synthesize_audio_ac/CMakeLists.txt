project( synthesize_audio_ac)

# Cria o executável com os arquivos-fonte
add_executable(${PROJECT_NAME}
        src/main.c
        src/i2c_setup.c
        src/oled_setup.c
        src/ssd1306.c
        src/rgb_setup.c
        src/capture_audio_setup.c
        src/audio_playback.c
        src/buttons_setup.c
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