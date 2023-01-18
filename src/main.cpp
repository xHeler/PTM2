
#include <Arduino.h>
#include <LiquidCrystal_AIP31068_I2C.h>

LiquidCrystal_AIP31068_I2C lcd(0x3E, 20, 4); // set the LCD address to 0x3E for a 20 chars and 4 line display

void setup()
{
lcd.init();
lcd.setCursor(3, 0);
lcd.print("Hello, world!");
lcd.setCursor(2, 1);
lcd.print("Ywrobot Arduino!");
lcd.setCursor(0, 2);
lcd.print("Arduino LCM IIC 2004");
lcd.setCursor(2, 3);
lcd.print("Power By Ec-yuan!");
}

void loop()
{
}