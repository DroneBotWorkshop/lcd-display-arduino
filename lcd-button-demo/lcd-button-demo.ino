/*
  LCD Display Shield with Buttons Demo
  lcd-button-demo.ino
  Use Display Shield with Analog Buttons
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include LiquidCrystal library
#include <LiquidCrystal.h>

// Setup lcd object with display pinouts
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


// Define button constants
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// Define variable to hold current button constant value
int lcd_key = 0;

// Define variable to hold button analog value
int adc_key_in = 0;

// Function to read the buttons
// Returns button constant value
int read_LCD_buttons()
{
  // read the value from the sensor
  adc_key_in = analogRead(0);

  // Approx button values are 0, 144, 329, 504, 741
  // Add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // No button is pressed
  if (adc_key_in < 50)   return btnRIGHT; // Right pressed
  if (adc_key_in < 195)  return btnUP;  // Up presed
  if (adc_key_in < 380)  return btnDOWN;  // Down pressed
  if (adc_key_in < 555)  return btnLEFT;  // Left pressed
  if (adc_key_in < 790)  return btnSELECT; // Select pressed
  return btnNONE;  // If no valid response return No button pressed
}

void setup()
{
  // Setup the LCD display
  lcd.begin(16, 2);
  // Set cursor to top line first position
  lcd.setCursor(0, 0);
  // Print message on first line
  lcd.print("Push a button");
}

void loop()
{
  // Move cursor to second line, 9 spaces over
  lcd.setCursor(9, 1);
  // Display seconds elapsed since reset
  lcd.print(millis() / 1000);

  // Move to the begining of the second line
  lcd.setCursor(0, 1);

  // Call the read buttons function
  lcd_key = read_LCD_buttons();

  // Print button value on second line
  switch (lcd_key)
  {
    case btnRIGHT:
      {
        lcd.print("RIGHT ");
        break;
      }
    case btnLEFT:
      {
        lcd.print("LEFT   ");
        break;
      }
    case btnUP:
      {
        lcd.print("UP    ");
        break;
      }
    case btnDOWN:
      {
        lcd.print("DOWN  ");
        break;
      }
    case btnSELECT:
      {
        lcd.print("SELECT");
        break;
      }
    case btnNONE:
      {
        lcd.print("NONE  ");
        break;
      }
  }

}
