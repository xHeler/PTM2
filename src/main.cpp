#include <Arduino.h>
#include "Board.h"
#include "Menu.h"

Board board;
Menu menu(board.getThrow());

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  board.update();
  menu.update();
}