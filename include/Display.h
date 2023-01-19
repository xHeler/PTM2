#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Player.h>

class Display {
public:
    Display();

    void start(const int players, const int points, bool dbl_in, bool dbl_out, const int option);
    void game(const int round, const Player player);
};

#endif