#pragma once

#include <Arduino.h>
#include "Throw.h"
#include "Display.h"

class Menu {
private:
    Throw* last;
    Display display;
    
public:
    Menu(Throw & last);
    void update();
    bool isStarted;
    int players;
    int start_points;
    bool dbl_in;
    bool dbl_out;
    int option;
};