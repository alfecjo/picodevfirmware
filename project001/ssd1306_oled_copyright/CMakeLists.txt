# Adiciona o executável
add_executable(ssd1306_oled_copyright
    src/ssd1306_oled_copyright.c
    src/ssd1306.c
    src/i2c_setup.c
    src/oled_setup.c
)

# Diretórios de inclusão
target_include_directories(ssd1306_oled_copyright
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Linka as bibliotecas necessárias
target_link_libraries(ssd1306_oled_copyright pico_stdlib hardware_i2c)

# Habilita USB e desabilita UART
pico_enable_stdio_usb(ssd1306_oled_copyright 1)
pico_enable_stdio_uart(ssd1306_oled_copyright 0)

# Gera arquivos extras (map/bin/hex/uf2)
pico_add_extra_outputs(ssd1306_oled_copyright)

# Adiciona URL do projeto
example_auto_set_url(ssd1306_oled_copyright)
