#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <Arduino.h>
#include "Game.h"
#include "Board.h"
#include "Display.h"

class GameApi : public Game {
   public:
    Board board;
    Display display;

    GameApi(const Settings &set) : Game(set) {
        Serial.println("Stworzono gre");
        display.game(1, Player(0, "Player #1", set.startPoints, 3));
    };
    GameStatus Loop();
};

#endif