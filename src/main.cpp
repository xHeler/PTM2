#include <Arduino.h>
#include <LiquidCrystal_AIP31068_I2C.h>

LiquidCrystal_AIP31068_I2C lcd(0x3E,20,4);  // set the LCD address to 0x3E for a 20 chars and 4 line display


void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.blink_on();
  lcd.print("[ 1 ] Players ");
  lcd.setCursor(0,1);
  lcd.print("[ 301 ] Points ");
  lcd.setCursor(0,3);
  lcd.print("[ ] Start");
  lcd.setCursor(19, 0);
}


void loop()
{
}