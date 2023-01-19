#include "Game.h"

Game::Game(const Settings &set): settings{set} {   
    for(int i = 0; i < set.numberOfPlayers; ++i){
        this->playerList[i] = Player(i, String("Player #" + String(i+1)).c_str(), settings.startPoints, 255);
    }

    this->throwingPlayerId = this->playerList[0].id;
    this->round = 0;
    this->multiplier = 0;
    this->value = 0;
}