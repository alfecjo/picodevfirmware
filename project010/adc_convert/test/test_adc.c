#include "unity.h"
#include "adc.h"

void setUp(void) {}

void tearDown(void) {}

// Teste principal
void test_adc_to_celsius(void) {
    uint16_t adc_val = (uint16_t)((0.706f * 4095.0f) / 3.3f);  // Calcula ADC para 0.706 V
    float expected_temp = 27.0f;
    float result = adc_to_celsius(adc_val);

    // Verifica se o resultado está próximo do esperado (tolerância de 0.5 °C)
    TEST_ASSERT_FLOAT_WITHIN(0.5f, expected_temp, result);
}

// Função principal do Unity
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_adc_to_celsius);
    return UNITY_END();
}
