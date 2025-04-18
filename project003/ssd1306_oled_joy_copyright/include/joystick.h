#ifndef JOYSTICK_H      // Prevents multiple inclusions
#define JOYSTICK_H

typedef struct {
    uint16_t x; // value from 0 to 4095
    uint16_t y;
} joystick_t;

joystick_t read_joystick(void); // Reads and returns joystick values

#endif
