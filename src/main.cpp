#include <Arduino.h>
#include "Game-api.h"
#include "Display.h"

Settings settings;

void setup()
{
  Display display;
  Serial.begin(9600);
  settings = Settings(0, 2, 301, false, false);
  //display.start(2, 301, false, true, 0);
  Player player(1, "Test", 301, 3);
  display.game(3, player);
}


void loop()
{
  GameApi game(settings);
  while(true)
    game.Loop();
}