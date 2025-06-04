if (DEFINED ENV{MQTT_SERVER} AND (NOT MQTT_SERVER))
    set(MQTT_SERVER $ENV{MQTT_SERVER})
    message("Using MQTT_SERVER from environment ('${MQTT_SERVER}')")
endif()

set(MQTT_SERVER "${MQTT_SERVER}" CACHE INTERNAL "MQTT server for examples")

if (DEFINED ENV{MQTT_USERNAME} AND (NOT MQTT_USERNAME))
    set(MQTT_USERNAME $ENV{MQTT_USERNAME})
    message("Using MQTT_USERNAME from environment ('${MQTT_USERNAME}')")
endif()
set(MQTT_USERNAME "${MQTT_USERNAME}" CACHE INTERNAL "MQTT user name for examples")
if (DEFINED ENV{MQTT_PASSWORD} AND (NOT MQTT_PASSWORD))
    set(MQTT_PASSWORD $ENV{MQTT_PASSWORD})
    message("Using MQTT_PASSWORD from environment")
endif()
set(MQTT_PASSWORD "${MQTT_PASSWORD}" CACHE INTERNAL "MQTT password for examples")

if (NOT MQTT_CERT_PATH)
    set(MQTT_CERT_PATH ${CMAKE_CURRENT_LIST_DIR}/certs/${MQTT_SERVER})
endif()

if (NOT MQTT_CERT_INC)
    set(MQTT_CERT_INC mqtt_client.inc)
endif()

set(TARGET_NAME picow_mqtt_temp_ac)
add_executable(${TARGET_NAME}
    src/iot_security_lab.c  
    src/bmp280_i2c_temp.c
    src/i2c_setup.c  
    )

target_include_directories(${TARGET_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${TARGET_NAME}
    pico_stdlib
    hardware_adc
    hardware_i2c
    pico_cyw43_arch_lwip_threadsafe_background
    pico_lwip_mqtt
    pico_mbedtls
    pico_lwip_mbedtls
    )

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
    )

target_compile_definitions(${TARGET_NAME} PRIVATE
    WIFI_SSID=\"${WIFI_SSID}\"
    WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
    MQTT_SERVER=\"${MQTT_SERVER}\"
    )
    
if (EXISTS "${MQTT_CERT_PATH}/${MQTT_CERT_INC}")
    target_compile_definitions(${TARGET_NAME} PRIVATE
        MQTT_CERT_INC=\"${MQTT_CERT_INC}\" # contains the tls certificates for MQTT_SERVER needed by the client
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
pico_add_extra_outputs(${TARGET_NAME})

# Ignore warnings from lwip code
set_source_files_properties(
    ${PICO_LWIP_PATH}/src/apps/altcp_tls/altcp_tls_mbedtls.c
    PROPERTIES
    COMPILE_OPTIONS "-Wno-unused-result"
    )

# verificar saídas com minicom
pico_enable_stdio_usb(${TARGET_NAME} 1)
