#include <Arduino.h>

#define NUM_LINES_MASTER  8
#define NUM_LINES_SLAVE  7

// Define Connections to 74H165
int load = 7;
int clockEnablePin = 4;
int dataIn = 5;
int clockIn = 6;

// Define Connections to 74HC595
const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;
int iterator = 7;
byte master = 0;

void setup()
{
  Serial.begin(9600);

  // Setup 74HC165 connections
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);

  // Setup pins as Outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  // set all zero

}

void loop()
{
  iterator = 0;
  if (iterator == 7) {
    iterator = 0;
  } else {
    iterator++;
  }

  bitSet(master, iterator);

  // Write pulse to load pin
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);

  for(uint8_t i = 0; i < NUM_LINES_MASTER; ++i) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);
    digitalWrite(latchPin, HIGH);
  }

  for(uint8_t i = 0; i < NUM_LINES_MASTER; ++i) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);
    digitalWrite(latchPin, LOW);

    // Get data from 74HC165
    digitalWrite(clockIn, HIGH);
    digitalWrite(clockEnablePin, LOW);
    byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
    digitalWrite(clockEnablePin, HIGH);
    // Print to serial monitor
    Serial.print("Master ");
    Serial.print(i);
    Serial.print(". Pin States:\r\n");
    Serial.println(incoming, BIN);
  }

  delay(100);
}