#include <Arduino.h>

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

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);

  // Setup 74HC595 connections
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Setup 74HC165 connections
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
}

void loop()
{

  for(uint8_t i = 0; i < 8; ++i) {
    
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

    // Get data from 74HC165
    digitalWrite(clockIn, HIGH);
    digitalWrite(clockEnablePin, LOW);
    byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
    digitalWrite(clockEnablePin, HIGH);

    bitClear(leds, i);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);

    // Print to serial monitor
    Serial.print("Master ");
    Serial.print(i);
    Serial.print(". ");
    Serial.println(incoming, BIN);

  
  }
  delay(250);
}