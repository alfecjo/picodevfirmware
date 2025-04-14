#ifndef JOYSTICK_H
#define JOYSTICK_H

typedef struct {
    uint16_t x; // valor de 0 a 4095
    uint16_t y;
} joystick_t;

joystick_t read_joystick(void);

#endif
