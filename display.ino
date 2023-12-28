// https://github.com/johnrickman/LiquidCrystal_I2C?tab=readme-ov-file
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "datatypes.h"

LiquidCrystal_I2C controller_lcd(0x27, 20, 4);

void display_clear() {

  controller_lcd.setCursor(0, 0);
  for (int i = 0; i < 16; i++) {
    controller_lcd.print(" ");
  }

  controller_lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    controller_lcd.print(" ");
  }
}

void display_clear_row(int row) {
  controller_lcd.setCursor(0, row);
  for (int i = 0; i < 16; i++) {
    controller_lcd.print(" ");
  }
}

void display_init() {
  controller_lcd.init();
  controller_lcd.backlight();
  controller_lcd.setCursor(0, 0);
  display_clear();
}

void display_test() {
  controller_lcd.setCursor(0, 0);
  controller_lcd.print("0123456789ABCDEF");
  controller_lcd.setCursor(0, 1);
  controller_lcd.print("GHIJKLMNOPQRSTUV");
}

void display_text(int row, int col, String text) {
  // display_clear_row(row);
  controller_lcd.setCursor(col, row);
  controller_lcd.print(text);
}

void display_number(int row, int col, int number) {

  controller_lcd.setCursor(col, row);

  // 0 Case
  if (number == 0) {
    controller_lcd.print("   0");
    return;
  }

  String number_string = String(number);
  String whitespace_buffer = "";

  // Get the number of digits in number
  int digits_ = 0;
  while (number != 0) {
    number = number / 10;
    digits_ += 1;
  }

  // Add a whitespace depending on the digits.
  for (int i = digits_; i < 4; i++) {
    whitespace_buffer += " ";
  }

  String display_string_ = whitespace_buffer + number_string;
  controller_lcd.print(display_string_);
}

void display_joysticks(struct JoyStickValues &values) {

  int lx = values.left_x;
  int ly = values.left_y;

  int rx = values.right_x;
  int ry = values.right_y;

  display_text(0, 0, "LX:");
  display_number(0, 3, lx);
  display_text(0, 8, "LY:");
  display_number(0, 11, ly);

  display_text(1, 0, "RX:");
  display_number(1, 3, rx);
  display_text(1, 8, "RY:");
  display_number(1, 11, ry);

  // String top_string = "";
  // String bottom_string = "";
  // if (lx < 1000) {
  //   top_string += "LX: ";
  // } else {
  //   top_string += "LX:";
  // }
  // top_string += String(lx);
  // top_string += " ";
  // if (ly < 1000) {
  // top_string += "LY: ";
  // } else {
  // top_string += "LY:";
  // }
  // top_string += String(ly);
  // controller_lcd.print(top_string);
  // //Bottom Row
  // controller_lcd.setCursor(0, 1);
  // if (rx < 1000) {
  //   bottom_string += "RX: ";
  // } else {
  //   bottom_string += "RX:";
  // }
  // bottom_string += String(rx);
  // bottom_string += " ";
  // if (ry < 1000) {
  //   bottom_string += "RY: ";
  // } else {
  //   bottom_string += "RY:";
  // }
  // bottom_string += String(ry);
  // bottom_string += " ";
  // controller_lcd.print(bottom_string);
}
