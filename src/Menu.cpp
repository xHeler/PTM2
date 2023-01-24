#include "Menu.h"

enum Button {
    START = 250,
    STOP = 251,
    UP = 252,
    DOWN = 253
};

Menu::Menu(Throw & last) {
    this->last = &last;
    this->isStarted = false;
    players = 2;
    start_points = 301;
    dbl_in = false;
    dbl_out = false;
    option = 0;
    display.start(players, start_points, dbl_in, dbl_out, option);
}

void Menu::update() {
  // Player player(1, "Test", 301, 3);
  // display.game(3, player);
    switch (this->last->getResult())
    {
    case START:
        Serial.println("Start");
        isStarted = true;
        break;
    case STOP:
        Serial.println("Stop");
        if (option == 0){
            players += 1;
            if (players == 5)
                players = 1;
        } else if (option == 1){
            if (start_points == 301){
                start_points = 501;
            } else {
                start_points = 301;
            }
        } else if (option == 2) {
            dbl_in = !dbl_in;
        } else if (option == 3) {
            dbl_out = !dbl_out;
        }
        display.start(players, start_points, dbl_in, dbl_out, option);

        break;
    case UP:
        Serial.println("Up");
        
        if (option > 0)
        {
            option -=1;
            Serial.println(option);
            display.start(players, start_points, dbl_in, dbl_out, option);
        }
        
        break;
    case DOWN:
        Serial.println("Down");
        
        if (option < 3)
        {
            option += 1;
            Serial.println(option);
            display.start(players, start_points, dbl_in, dbl_out, option);
        }
        break;
    default:
        return;
    }
    this->last->multiplier = 0;
    this->last->value = 0;
    delay(150);
}
