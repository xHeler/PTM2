#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <Arduino.h>
#include "Game.h"
#include "Board.h"

class GameApi : public Game {
   public:
    Board board;

    GameApi(const Settings &set) : Game(set) {
        Serial.println("Stworzono gre");
    };
    GameStatus Loop();
};

#endif