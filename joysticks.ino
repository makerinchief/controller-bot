// #include "datatypes.h"

// //Analog Pins 0 - 3
// const int LY_PIN = 14;
// const int LX_PIN = 15;
// const int RY_PIN = 16;
// const int RX_PIN = 17;

// //Digital Pins for Joystick buttons
// const int RB_PIN = 4;
// const int LB_PIN = 5;

// //Use a timer instead of delay() in order to multitask
// unsigned long joystick_current = 0;
// unsigned long joystick_previous = 0;
// long joystick_interval = 10;

// JoyStickValues joystick_values;

// void joysticks_init() {
//   pinMode(RB_PIN, INPUT_PULLUP);
//   pinMode(LB_PIN, INPUT_PULLUP);
// }

// // Due to the way the joystick is oreientated,
// // we need to swap indexs in order to get accurate
// // results.  The easiest way to do this is to swap
// // the pins being read for x and y.

// struct JoyStickValues joysticks_read() {

//   // Full range of values
//   joystick_values.left_x = analogRead(LY_PIN);
//   joystick_values.left_y = analogRead(LX_PIN);
//   joystick_values.left_b = digitalRead(LB_PIN);
//   joystick_values.right_x = analogRead(RY_PIN);
//   joystick_values.right_y = analogRead(RX_PIN);
//   joystick_values.right_b = digitalRead(RB_PIN);

//   // Divide range in half for more stable resolution
//   //  joystick_values.left_y = map(analogRead(LX_PIN), 0, 1023, 0, 512);
//   //  joystick_values.left_x = map(analogRead(LY_PIN), 0, 1023, 0, 512);
//   //  joystick_values.left_b = map(analogRead(LB_PIN), 0, 1023, 0, 512);
//   //  joystick_values.right_y = map(analogRead(RX_PIN), 0, 1023, 0, 512);
//   //  joystick_values.right_x = map(analogRead(RY_PIN), 0, 1023, 0, 512);
//   //  joystick_values.right_b = map(analogRead(RB_PIN), 0, 1023, 0, 512);

//   return joystick_values;
// }

// struct JoyStickValues joysticks_get_values() {
//   return joystick_values;
// }

// void joysticks_print_values() {
//   //Print the data
//   Serial.print(joystick_values.left_x);
//   Serial.print(" : ");
//   Serial.print(joystick_values.left_y);
//   Serial.print(" : ");
//   Serial.print(joystick_values.left_b);
//   Serial.print(" : ");
//   Serial.print(joystick_values.right_x);
//   Serial.print(" : ");
//   Serial.print(joystick_values.right_y);
//   Serial.print(" : ");
//   Serial.println(joystick_values.right_b);
// }

// void joysticks_test() {
//   joystick_current = millis();
//   if (joystick_current - joystick_previous >= joystick_interval) {
//     joysticks_read();
//     joysticks_print_values();
//     joystick_previous = joystick_current;
//   }
// }
