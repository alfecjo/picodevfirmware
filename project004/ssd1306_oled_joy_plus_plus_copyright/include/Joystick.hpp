#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP

#include <cstdint>

class Joystick {
public:
    struct State {
        uint16_t x;
        uint16_t y;
    };

    State read() const;
};

#endif
