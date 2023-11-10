/*
  Controller Bot
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details
*/

#include "datatypes.h"

JoyStickValues joystick_vals;
TankBotPacket tank_packet;

//The joystick data can be noisy so we can create a threshold for each axis
int16_t axis_threshold = 25;

unsigned long controller_current = 0;
unsigned long controller_previous = 0;
long controller_interval = 100;

void setup() {

  Serial.begin(115200);
  joysticks_init();

  display_init();
  display_test();
  delay(2000);
  display_clear();

  display_text(0, 1, "Controller Bot");

  if (!radio_init()) {
    Serial.println("!NO RADIO FOUND!");
    display_text(1, 0, "NO RADIO FOUND");
  }

}

void loop() {

  controller_current = millis();

  if (controller_current - controller_previous > controller_interval) {

    joystick_vals = joysticks_read();

    //  joysticks_print_values();
    //  display_joysticks(joystick_vals);

    int l_spd = map(joystick_vals.left_y, 0, 1023, 256, -256);
    int r_spd = map(joystick_vals.right_y, 0, 1023, 256, -256);
    char direction;

    if (abs(l_spd) > axis_threshold) {
      tank_packet.left_speed = l_spd;
    } else {
      tank_packet.left_speed = 0;
    }

    if (abs(r_spd) > axis_threshold) {
      tank_packet.right_speed = r_spd;
    } else {
      tank_packet.right_speed = 0;
    }

    if (l_spd > 0 && r_spd > 0) {
      direction = 'f';
    }

    if (l_spd < 0 && r_spd < 0) {
      direction = 'b';
    }

    if (l_spd < 0 && r_spd > 0) {
      direction = 'l';
    }

    if (l_spd > 0 && r_spd < 0) {
      direction = 'r';
    }

    if (abs(l_spd) <= axis_threshold &&
        abs(r_spd) <= axis_threshold) {
      direction = 's';
    }

    tank_packet.direction = direction;

    Serial.print("L SPD: ");
    Serial.print(abs(l_spd));
    Serial.print(" R SPD: ");
    Serial.print(abs(r_spd));
    Serial.print(" DIR: ");
    Serial.println(direction);

    radio_send_tankbot(tank_packet);
    controller_previous = controller_previous;
  }
}
