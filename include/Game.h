#ifndef GAME_H
#define GAME_H
#include <Arduino.h>

#include "Player.h"
#include "Settings.h"

enum GameStatus{
    GameStatus_Active, GameStatus_Pause, GameStatus_Save, GameStatus_Finished
};
class Game{
    public:
        Settings settings; 
        GameStatus status = GameStatus_Active;
        uint16_t throwingPlayerId;
        uint16_t round = 0;
        Player playerList[MAX_PLAYERS];
        uint8_t multiplier;
        uint8_t value;

        Game(const Settings &set);
};

#endif