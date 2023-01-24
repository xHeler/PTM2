#include <Arduino.h>
#include "Game-api.h"
#include "Display.h"
#include "Menu.h"

Settings settings;

void setup()
{
  Serial.begin(9600);
  
  //display.start(2, 301, false, true, 0);
  // Player player(1, "Test", 301, 3);
  // display.game(3, player);
  Board board;
  Menu menu(board.getThrow());
  Serial.println("Darts started.");
  while (!menu.isStarted)
  {
    board.update();
    menu.update();
  }
  settings = Settings(0, menu.players, menu.start_points, menu.dbl_in, menu.dbl_out);
}


void loop()
{
  GameApi game(settings);
  while(true)
    game.Loop();
}