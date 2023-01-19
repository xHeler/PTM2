#include "Player.h"

Player::Player(const uint16_t &id, const char nick[NICK_LENGTH], const uint16_t &points, const uint8_t &attempts):
id{id}{
    strcpy(this->nick, nick);
    this->points = points;
    this->attempts = attempts;
}
Player::Player():id{0}, nick{"nick"}, points{0}, attempts{0}{
    
}