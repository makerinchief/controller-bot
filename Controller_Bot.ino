/*
  Controller Bot
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details
*/

//NRFLite is used to make communication easy
//https://github.com/dparson55/NRFLite
#include <SPI.h>
// #include <NRFLite.h>
// #include "datatypes.h"

// NRFLite controller_radio;

// typedef struct TestStruct {
//   int val_1;
//   int val_2;
// };

typedef struct JoyStickValues {
  int16_t left_x;
  int16_t left_y;
  int16_t left_b;
  int16_t right_x;
  int16_t right_y;
  int16_t right_b;
};

typedef struct ControllerPacket {
  int16_t left_x;
  int16_t left_y;
  int16_t left_b;
  int16_t right_x;
  int16_t right_y;
  int16_t right_b;
};

// typedef struct TankBotPacket {
//   char direction;
//   int16_t left_speed;
//   int16_t right_speed;
// };

JoyStickValues joystick_values;
ControllerPacket controller_packet;
// TankBotPacket tank_packet;

//The joystick data can be noisy so we can create a threshold for each axis
// int16_t axis_threshold = 25;

//Analog Pins 0 - 3
const int LY_PIN = 14;
const int LX_PIN = 15;
const int RY_PIN = 16;
const int RX_PIN = 17;

//Digital Pins for Joystick buttons
const int LB_PIN = 3;
const int RB_PIN = 4;

//Use a timer instead of delay() in order to multitask
unsigned long joystick_current = 0;
unsigned long joystick_previous = 0;
long joystick_interval = 10;

unsigned long controller_current = 0;
unsigned long controller_previous = 0;
long controller_interval = 100;

void setup() {

  Serial.begin(115200);

  pinMode(RB_PIN, INPUT_PULLUP);
  pinMode(LB_PIN, INPUT_PULLUP);

  // joysticks_init();
  // display_init();
  // display_test();
  // delay(2000);
  // display_clear();
  // display_text(0, 1, "Controller Bot");
  // if (!radio_init()) {
  //   Serial.println("!NO RADIO FOUND!");
  //   display_text(1, 0, "NO RADIO FOUND");
  // }
  
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

    //   joystick_vals = joysticks_read();
    //   //  joysticks_print_values();
    //   //  display_joysticks(joystick_vals);
    //   int l_spd = map(joystick_vals.left_y, 0, 1023, 256, -256);
    //   int r_spd = map(joystick_vals.right_y, 0, 1023, 256, -256);
    //   char direction;
    //   if (abs(l_spd) > axis_threshold) {
    //     tank_packet.left_speed = l_spd;
    //   } else {
    //     tank_packet.left_speed = 0;
    //   }
    //   if (abs(r_spd) > axis_threshold) {
    //     tank_packet.right_speed = r_spd;
    //   } else {
    //     tank_packet.right_speed = 0;
    //   }
    //   if (l_spd > 0 && r_spd > 0) {
    //     direction = 'f';
    //   }
    //   if (l_spd < 0 && r_spd < 0) {
    //     direction = 'b';
    //   }
    //   if (l_spd < 0 && r_spd > 0) {
    //     direction = 'l';
    //   }
    //   if (l_spd > 0 && r_spd < 0) {
    //     direction = 'r';
    //   }
    //   if (abs(l_spd) <= axis_threshold &&
    //       abs(r_spd) <= axis_threshold) {
    //     direction = 's';
    //   }
    //   tank_packet.direction = direction;
    //   Serial.print("L SPD: ");
    //   Serial.print(abs(l_spd));
    //   Serial.print(" R SPD: ");
    //   Serial.print(abs(r_spd));
    //   Serial.print(" DIR: ");
    //   Serial.println(direction);
    //   radio_send_tankbot(tank_packet);
    //   controller_previous = controller_previous;

  }
}
