#include <Arduino.h>
#include "Board.h"

Board board;

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  board.update();
}