set(TARGET_NAME picow_mqtt_client)

add_executable(${TARGET_NAME}
    mqtt_client.c
)

target_link_libraries(${TARGET_NAME}
    pico_stdlib
    hardware_adc
    pico_cyw43_arch_lwip_threadsafe_background
    pico_lwip_mqtt
    pico_mbedtls
    pico_lwip_mbedtls
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(${TARGET_NAME} PRIVATE
    WIFI_SSID=\"${WIFI_SSID}\"
    WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
    MQTT_SERVER=\"${MQTT_SERVER}\"
)

if (EXISTS "${MQTT_CERT_PATH}/${MQTT_CERT_INC}")
    target_compile_definitions(${TARGET_NAME} PRIVATE
        MQTT_CERT_INC=\"${MQTT_CERT_INC}\"
        ALTCP_MBEDTLS_AUTHMODE=MBEDTLS_SSL_VERIFY_REQUIRED
    )
    target_include_directories(${TARGET_NAME} PRIVATE
        ${MQTT_CERT_PATH}
    )
endif()

if (MQTT_USERNAME AND MQTT_PASSWORD)
    target_compile_definitions(${TARGET_NAME} PRIVATE
        MQTT_USERNAME=\"${MQTT_USERNAME}\"
        MQTT_PASSWORD=\"${MQTT_PASSWORD}\"
    )
endif()

set_source_files_properties(
    ${PICO_LWIP_PATH}/src/apps/altcp_tls/altcp_tls_mbedtls.c
    PROPERTIES
    COMPILE_OPTIONS "-Wno-unused-result"
)

pico_add_extra_outputs(${TARGET_NAME})
pico_enable_stdio_usb(${TARGET_NAME} 1)