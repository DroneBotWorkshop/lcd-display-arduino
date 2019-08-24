/*
  LCD Display with I2C Interface Demo
  lcd-i2c-demo.ino
  Use NewLiquidCrystal Library
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>

// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x3F;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

void setup()
{

  // Set display type as 16 char, 2 rows
  lcd.begin(16, 2);

  // Print on first row
  lcd.setCursor(0, 0);
  lcd.print("Hello world!");

  // Wait 1 second
  delay(1000);

  // Print on second row
  lcd.setCursor(0, 1);
  lcd.print("How are you?");

  // Wait 8 seconds
  delay(8000);

  // Clear the display
  lcd.clear();

}


void loop()
{

  // Demo 1 - flash backlight
  lcd.setCursor(0, 0);
  lcd.print("Backlight demo");
  lcd.setCursor(0, 1);
  lcd.print("Flash 4 times");

  delay(3000);
  lcd.clear();

  // Flash backlight 4 times
  for (int i = 0; i < 4; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }

  // Turn backlight back on
  lcd.backlight();

  // Demo 2 - scroll
  lcd.setCursor(0, 0);
  lcd.print("Scroll demo - ");
  delay(1500);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen
  lcd.clear();

  //Delay
  delay(1000);

}
