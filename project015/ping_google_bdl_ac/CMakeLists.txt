set(TARGET_NAME picow_freertos_ping_ac)
add_executable(${TARGET_NAME}
            src/picow_freertos_ping_ac.c
            src/ping.c
            src/i2c_setup.c
            src/oled_setup.c
            src/ssd1306.c
            )
    target_compile_definitions(${TARGET_NAME} PRIVATE
            WIFI_SSID=\"${WIFI_SSID}\"
            WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
            NO_SYS=0            # don't want NO_SYS (generally this would be in your lwipopts.h)
            LWIP_SOCKET=1       # we need the socket API (generally this would be in your lwipopts.h)
            PING_USE_SOCKETS=1
            )
    target_include_directories(${TARGET_NAME} PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/include       # inclui ping.h na raiz
            ${CMAKE_CURRENT_LIST_DIR}/..            # para FreeRTOSConfig.h
            ${CMAKE_CURRENT_LIST_DIR}/../..         # para lwipopts.h
            )
    target_link_libraries(${TARGET_NAME}
            pico_cyw43_arch_lwip_sys_freertos
            pico_stdlib
            pico_lwip_iperf
            FreeRTOS-Kernel-Heap4 # FreeRTOS kernel and dynamic heap
            hardware_i2c
            )
    pico_add_extra_outputs(${TARGET_NAME})

    pico_enable_stdio_usb(${TARGET_NAME} 1)
