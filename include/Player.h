#ifndef PLAYRER_H
#define PLAYRER_H

#include <Arduino.h>
#include <string.h>

#ifndef NICK_LENGTH
    #define NICK_LENGTH 15
#endif

class Player{
    public:
        uint16_t id;
        char nick[NICK_LENGTH];
        uint16_t points;
        uint8_t attempts = 0;

        Player();
        Player(const uint16_t &id, const char nick[NICK_LENGTH], const uint16_t &points = 301, const uint8_t &attempts = 0);
};

#endif