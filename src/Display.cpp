#include "Display.h"
#include <LiquidCrystal_AIP31068_I2C.h>

LiquidCrystal_AIP31068_I2C lcd(0x3E, 20, 4); 

Display::Display() {
    lcd.init();
}

void Display::start(const int players, const int points, bool dbl_in, bool dbl_out, const int option) {
    lcd.setCursor(0,0);
    lcd.blink_on();
    lcd.print("[  ");
    lcd.print(players);
    lcd.print("  ] Players ");
    lcd.setCursor(0,1);
    lcd.print("[ ");
    lcd.print(points);
    lcd.print(" ] Points ");
    lcd.setCursor(0,2);
    lcd.print("[  ");
    if (dbl_in)
    {
        lcd.print("X");
    } else {
        lcd.print(" ");
    }
    lcd.print("  ] Double in ");
    
    lcd.setCursor(0,3);
    lcd.print("[  ");
    if (dbl_out)
    {
        lcd.print("X");
    } else {
        lcd.print(" ");
    }
    lcd.print("  ] Double out ");
    lcd.setCursor(19, option);
}

void Display::game(const int round, const Player player) {
    lcd.setCursor(0, 0);
    lcd.blink_off();

    lcd.print("Round: ");
    lcd.print(round);
    
    lcd.setCursor(0, 1);
    lcd.print(player.nick);

    lcd.setCursor(9, 2);
    lcd.print(player.points);
    lcd.setCursor(3, 3);
    for (int i = 0; i < 3 - player.attempts; ++i)
        lcd.print("[ X ]");
    for (int i = 0; i < player.attempts; ++i)
        lcd.print("[   ]");
}