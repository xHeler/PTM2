#include "Settings.h"

Settings::Settings():
id{0}, numberOfPlayers{0}, startPoints{301}, doubleIn{false}, doubleOut{false}
{
    for(int i = 0; i < this->numberOfPlayers; ++i)
        this->playersId[i] = 0;
}

Settings::Settings(const uint16_t &id, const uint8_t &numberOfPlayers, const uint16_t &startPoints, const bool &doubleIn, const bool &doubleOut):
id{id}, numberOfPlayers{numberOfPlayers}, startPoints{startPoints}, doubleIn{doubleIn}, doubleOut{doubleOut}{
    
    for(int i = 0; i < this->numberOfPlayers; ++i)
        this->playersId[i] = playersId[i];
        
}