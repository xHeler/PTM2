#include "Menu.h"

enum Button {
    START = 250,
    STOP = 251,
    UP = 252,
    DOWN = 253
};

Menu::Menu(Throw & last) {
    this->last = &last;
}

void Menu::update() {
    switch (this->last->getResult())
    {
    case START:
        Serial.println("Start");
        break;
    case STOP:
        Serial.println("Stop");
        break;
    case UP:
        Serial.println("Up");
        break;
    case DOWN:
        Serial.println("Down");
        break;
    default:
        return;
    }
    this->last->multiplier = 0;
    this->last->value = 0;
    delay(250);
}
