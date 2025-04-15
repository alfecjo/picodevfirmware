project(ssd1306_oled_joy_plus_plus_copyright)

# Adiciona o executável
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/joystick.cpp
    src/ssd1306.c
    src/adc_setup.cpp
    src/i2c_setup.cpp
    src/oled_setup.cpp
)

# Diretórios de inclusão
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Linka as bibliotecas necessárias
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_i2c hardware_adc)

# Habilita USB e desabilita UART
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Gera arquivos extras (map/bin/hex/uf2)
pico_add_extra_outputs(${PROJECT_NAME})

# Adiciona URL do projeto
example_auto_set_url(${PROJECT_NAME})
