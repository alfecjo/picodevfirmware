#include "bmp280_i2c_temp.h"

#include "hardware/i2c.h"
#include "pico/stdlib.h"

void bmp280_init() {
    uint8_t buf[2];

    const uint8_t reg_config_val = ((0x04 << 5) | (0x05 << 2)) & 0xFC;
    buf[0] = REG_CONFIG;
    buf[1] = reg_config_val;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);

    const uint8_t reg_ctrl_meas_val = (0x01 << 5) | (0x00 << 2) | (0x03);
    buf[0] = REG_CTRL_MEAS;
    buf[1] = reg_ctrl_meas_val;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
}

void bmp280_reset() {
    uint8_t buf[2] = { REG_RESET, 0xB6 };
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
}

void bmp280_read_raw_temp(int32_t* temp) {
    uint8_t buf[3];
    uint8_t reg = REG_TEMP_MSB;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_default, ADDR, buf, 3, false);
    *temp = (buf[0] << 12) | (buf[1] << 4) | (buf[2] >> 4);
}

void bmp280_get_calib_params(struct bmp280_calib_param* params) {
    uint8_t buf[NUM_CALIB_PARAMS] = { 0 };
    uint8_t reg = REG_DIG_T1_LSB;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_default, ADDR, buf, NUM_CALIB_PARAMS, false);

    params->dig_t1 = (uint16_t)((buf[1] << 8) | buf[0]);
    params->dig_t2 = (int16_t)((buf[3] << 8) | buf[2]);
    params->dig_t3 = (int16_t)((buf[5] << 8) | buf[4]);
}

int32_t bmp280_convert(int32_t temp, struct bmp280_calib_param* params) {
    int32_t var1, var2;
    var1 = ((((temp >> 3) - ((int32_t)params->dig_t1 << 1))) * ((int32_t)params->dig_t2)) >> 11;
    var2 = (((((temp >> 4) - ((int32_t)params->dig_t1)) * ((temp >> 4) - ((int32_t)params->dig_t1))) >> 12) * ((int32_t)params->dig_t3)) >> 14;
    return var1 + var2;
}

float bmp280_convert_temp_float(int32_t temp, struct bmp280_calib_param* params) {
    int32_t t_fine = bmp280_convert(temp, params);
    return (t_fine * 5.0f + 128.0f) / 256.0f;
}