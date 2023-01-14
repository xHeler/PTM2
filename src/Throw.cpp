#include "Throw.h"
#include "math.h"


Throw::Throw(const uint8_t &multiplier, const uint8_t &value):
    multiplier{multiplier}, value{value}
{}

Throw::Throw(){
    this->multiplier = 0;
    this->value = 0;
}
Throw &Throw::operator=(const Throw &other) {
    this->multiplier = other.multiplier;
    this->value = other.value;
    return *this;
}

uint8_t Throw::getResult() {
    return this->multiplier * this->value;
}

bool Throw::operator==(const Throw &other) const {
    return this->multiplier == other.multiplier && this->value == other.value;
}

bool Throw::operator!=(const Throw &other) const {
    return this->multiplier != other.multiplier || this->value != other.value;
}

bool Throw::operator!() const {
    return this->multiplier == 0 || this->value == 0;
}

bool Throw::operator==(const int &other) const {
    return this->multiplier*this->value == other;
}

bool Throw::operator>(const int &other) const{
    return this->multiplier*this->value > other;
}
bool Throw::operator<(const int &other) const{
    return this->multiplier*this->value < other;
}

uint16_t operator- (const uint16_t &points, const Throw &hit){
    return points - hit.multiplier*hit.value;
}

uint16_t operator+ (const uint16_t &points, const Throw &hit){
    return points + hit.multiplier*hit.value;
}

uint8_t fromByteToIndex(byte states) {
    int b = int(states);
    switch(b) {
        case 254:
            return 6;
        case 253:
            return 5;
        case 251:
            return 4;
        case 247:
            return 3;
        case 239:
            return 2;
        case 223:
            return 1;
        case 191:
            return 0;
    }
    return -1;
}