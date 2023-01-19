#ifndef SETTINGS_H
#define SETTINGS_H

#include "Arduino.h"
#include <stdint.h>

#ifndef MAX_PLAYERS
    #define MAX_PLAYERS 10
#endif

struct Settings{
    public:
        uint16_t id;
        uint8_t numberOfPlayers;
        uint16_t startPoints;
        bool doubleIn;
        bool doubleOut;
        uint16_t playersId[MAX_PLAYERS];

        Settings();
        Settings(const uint16_t &id, const uint8_t &numberOfPlayers, const uint16_t &startPoints, const bool &doubleIn, const bool &doubleOut);
};

#endif