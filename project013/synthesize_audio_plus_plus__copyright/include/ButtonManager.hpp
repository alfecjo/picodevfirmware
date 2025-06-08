#ifndef BUTTON_MANAGER_HPP
#define BUTTON_MANAGER_HPP

#include "pico/stdlib.h"

class ButtonManager {
public:
    ButtonManager(uint gpioRecord, uint gpioPlay);
    bool isRecordPressed();
    bool isPlayPressed();

private:
    uint recordPin;
    uint playPin;

    void initButtons();
};
#endif // BUTTON_MANAGER_HPP