#include "Menu.h"

Menu::Menu(Throw & last) {
    this->last = &last;
}

void Menu::update() {
    Serial.println(last->getResult());
}