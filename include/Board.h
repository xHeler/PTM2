#pragma once

#include <Arduino.h>
#include "Throw.h"

class Board {
private:
    Throw last;
    void check_default_matrix();
    void check_additional_matrix();
public:
    Board();
    
    void update();
    Throw getLastThrow();
    Throw getLastThrowAndReset();
    Throw & getThrow();
};