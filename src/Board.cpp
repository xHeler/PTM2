#include "Board.h"
#include "Throw.h"

// 74HC595
int clockPin = 9;
int latchPin = 10;
int dataPin = 11;
byte leds = 0;
int currentLED = 0;

// 74HC165
int load = 7;
int clockEnablePin = 4;
int dataIn = 5;
int clockIn = 6;

Board::Board() {
  // Setup 74HC595 connections
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Setup 74HC165 connections
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);

  // Setup two additional analog pins as output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void Board::update() {
    for(uint8_t i = 0; i < 10; ++i) {
  
    bitSet(leds, i);
    // set current master to active
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);

    // Write pulse to load pin
    digitalWrite(load, LOW);
    delayMicroseconds(5);
    digitalWrite(load, HIGH);
    delayMicroseconds(5);
    bitClear(leds, i);

    // Get data from 74HC165
    digitalWrite(clockIn, HIGH);
    digitalWrite(clockEnablePin, LOW);
    byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
    digitalWrite(clockEnablePin, HIGH);
    
    // Print to serial monitor
    int j = fromByteToIndex(incoming);

    if (j >= 0 && j <= 6){
      Serial.print("i: ");
      Serial.print(i);
      Serial.print(", j: ");
      Serial.print(j);
      Throw t = SETUP_MATRIX[i][j];
      Serial.print(", Result: ");
      Serial.println(t.getResult());
    }
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
  }
}