#pragma once

#include <Arduino.h>
#include "Throw.h"

enum Button {
    START = 250,
    STOP = 251,
    UP = 252,
    DOWN = 253
};

class Menu {
private:
    Throw* last;
public:
    Menu(Throw & last);
    void update();
};