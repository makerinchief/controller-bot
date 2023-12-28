/*
  Controller Bot
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details
*/


// Basic script to print joystick values to Serial Monitor

#include <SPI.h>

typedef struct JoyStickValues {
  int16_t left_x;
  int16_t left_y;
  int16_t left_b;
  int16_t right_x;
  int16_t right_y;
  int16_t right_b;
};

JoyStickValues joystick_values;

//Analog Pins 0 - 3
const int LY_PIN = 14;
const int LX_PIN = 15;
const int RY_PIN = 16;
const int RX_PIN = 17;

//Digital Pins for Joystick buttons
const int LB_PIN = 3;
const int RB_PIN = 4;

unsigned long controller_current = 0;
unsigned long controller_previous = 0;
long controller_interval = 250;

void setup() {

  Serial.begin(115200);

  pinMode(RB_PIN, INPUT_PULLUP);
  pinMode(LB_PIN, INPUT_PULLUP);

}

void loop() {

  controller_current = millis();

  if (controller_current - controller_previous > controller_interval) {

    // Read each joystick
    joystick_values.left_x = analogRead(LY_PIN);
    joystick_values.left_y = analogRead(LX_PIN);
    joystick_values.left_b = digitalRead(LB_PIN);

    joystick_values.right_x = analogRead(RY_PIN);
    joystick_values.right_y = analogRead(RX_PIN);
    joystick_values.right_b = digitalRead(RB_PIN);

    //Print each joystick value to the Serial Monitor
    Serial.print(joystick_values.left_x);
    Serial.print(" : ");
    Serial.print(joystick_values.left_y);
    Serial.print(" : ");
    Serial.print(joystick_values.left_b);
    Serial.print(" : ");
    Serial.print(joystick_values.right_x);
    Serial.print(" : ");
    Serial.print(joystick_values.right_y);
    Serial.print(" : ");
    Serial.println(joystick_values.right_b);

  }
}
