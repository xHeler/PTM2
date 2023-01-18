#pragma once

#include <Arduino.h>
#include "Throw.h"


class Menu {
private:
    Throw* last;
public:
    Menu(Throw & last);
    void update();
};