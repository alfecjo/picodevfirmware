cmake_minimum_required(VERSION 3.13)

project(adc_convert)

# Variáveis de caminhos
set(SRC_PATH src)
set(INC_PATH include)
set(TEST_PATH test)
set(UNITY_PATH unity)

# Firmware principal
add_executable(adc_convert
    ${SRC_PATH}/adc.c
    ${SRC_PATH}/adc_convert.c
)

target_include_directories(adc_convert
    PUBLIC
    ${INC_PATH}
)

target_link_libraries(adc_convert pico_stdlib hardware_adc)

pico_enable_stdio_usb(adc_convert 1)
pico_enable_stdio_uart(adc_convert 0)

pico_add_extra_outputs(adc_convert)

example_auto_set_url(adc_convert)

# ---------------------------------------------------
# Testes Unitários (não gera UF2, apenas executa)
# ---------------------------------------------------
option(BUILD_TESTS "Build and run unit tests" ON)

if (BUILD_TESTS)
    enable_testing()

    file(GLOB TEST_SOURCES "${TEST_PATH}/*.c")
    foreach(test_file ${TEST_SOURCES})
        get_filename_component(test_name ${test_file} NAME_WE)
        
        add_executable(${test_name}
            ${SRC_PATH}/adc.c
            ${UNITY_PATH}/unity.c
            ${test_file}
        )

        target_include_directories(${test_name}
            PUBLIC
            ${INC_PATH}
            ${UNITY_PATH}
        )

        target_link_libraries(${test_name} pico_stdlib hardware_adc)

        pico_enable_stdio_usb(${test_name} 0)
        pico_enable_stdio_uart(${test_name} 0)

        # Definindo o comando de teste
        add_test(
            NAME ${test_name}_run
            COMMAND ${test_name}
        )

        # Opcional: diretórios organizados
        set_target_properties(${test_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/results
            EXCLUDE_FROM_ALL TRUE
        )
    endforeach()
endif()
