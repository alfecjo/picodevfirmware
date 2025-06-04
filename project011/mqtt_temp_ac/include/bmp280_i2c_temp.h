#ifndef BMP280_I2C_TEMP_H  
#define BMP280_I2C_TEMP_H  

#include "pico/stdlib.h"

#define ADDR _u(0x76)  // I2C address for BMP280

// BMP280 registers for temperature
#define REG_CONFIG _u(0xF5)
#define REG_CTRL_MEAS _u(0xF4)
#define REG_RESET _u(0xE0)

#define REG_TEMP_XLSB _u(0xFC)
#define REG_TEMP_LSB _u(0xFB)
#define REG_TEMP_MSB _u(0xFA)

#define REG_DIG_T1_LSB _u(0x88)
#define REG_DIG_T1_MSB _u(0x89)
#define REG_DIG_T2_LSB _u(0x8A)
#define REG_DIG_T2_MSB _u(0x8B)
#define REG_DIG_T3_LSB _u(0x8C)
#define REG_DIG_T3_MSB _u(0x8D)

#define NUM_CALIB_PARAMS 6

struct bmp280_calib_param {
    uint16_t dig_t1;
    int16_t dig_t2;
    int16_t dig_t3;
};

void bmp280_init();

void bmp280_init();

void bmp280_reset();

void bmp280_read_raw_temp(int32_t* temp);

void bmp280_get_calib_params(struct bmp280_calib_param* params);

int32_t bmp280_convert(int32_t temp, struct bmp280_calib_param* params);

float bmp280_convert_temp_float(int32_t temp, struct bmp280_calib_param* params);

#endif