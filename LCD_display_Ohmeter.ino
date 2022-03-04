/*
 LCD + ohmeter

 This program demonstrates how to use the Arduino to receive data and calculate an uknown value
 (in this case the resistance of R2) by coding logic (in this case OHMS law). The value is then printed unto the LCD screen
 with symbols, in order to understand what the value is.

 "warning: This doesn't replace an actual ohmeter. The value displayed will always have a percent of accuracy."

 You will need:
 -breadboard
 -220 ohm resistor
 -1 K ohm resistor
 -2 k ohm resistor (the value to be calculated)
 -potentiometer
 -LCD1602 Module
 -wire X18

 wiring:
-connect a wire from ground of the arduino to the "-" part of the breadboard.
-connect a wire from 5V of the arduino to the "+" part of the breadboard.
-connect the 1K ohm resistor from the "+" part of the breadboard to the 2K ohm resistor.
-connect a wire from A0 of the arduino to both the 1k and 2k ohm resistors.
-connect a wire from the 2K ohm resistor to the "-" part of the breadboard.
-connect a wire from the "-" part of the breadboard to the left leg of the potentiometer.
-connect a wire from the "+" part of the breadboard to the right leg of the potentiometer.
-connect a wire from the middle leg of the potentiometer to the VO pin on the LCD.
-connect a wire from the "-" part of the breadboard to the VSS pin on the LCD.
-connect a wire from the "-" part of the breadboard to the RW pin on the LCD.
-connect a wire from the "-" part of the breadboard to the K pin on the LCD.
-connect a wire from the "+" part of the breadboard to the VDD pin on the LCD.
-connect a wire from pin 12 of the arduino to the RS pin on the LCD.
-connect a wire from pin 11 of the arduino to the E pin on the LCD.
-connect a wire from pin 5 of the arduino to the D4 pin on the LCD.
-connect a wire from pin 4 of the arduino to the D5 pin on the LCD.
-connect a wire from pin 3 of the arduino to the D6 pin on the LCD.
-connect a wire from pin 2 of the arduino to the D7 pin on the LCD.
-connect a wire from the A pin on the LCD to the 220 ohm resistor.
-connect the 220 ohm resistor to the "+" part of the breadboard.







 
 */




// include the library code:
#include <LiquidCrystal.h> //using preprogramed codes inside the arduino uno in order for the LCD to work as intended.

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte OHM[8] = { //creating the symbol of Ohm to display on the LCD screen.
  0b00000,
  0b00100,
  0b01110,
  0b01010,
  0b11011,
  0b00000,
  0b00000,
  0b00000
};

byte K[8] = { //creating the symbol of K to display on the LCD screen.
  0b00000,
  0b01001,
  0b01010,
  0b01100,
  0b01010,
  0b01001,
  0b00000,
  0b00000
};

float R1 = 1.0; //the resistance of resitor 1 in K ohms.

void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);//A0 acts as a Voltmeter
Serial.begin(9600); //allows printing values

// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Resistor 2");

  lcd.createChar(2,K); // create the K symbol
  lcd.createChar(1,OHM); // create the OHM symbol
  // set the cursor to the bottom row, 5th position:
  lcd.setCursor(4, 1);
  // draw the K symbol:
  lcd.write(2);
  // set the cursor to the bottom row, 6th position:
  lcd.setCursor(5, 1);
  // draw the OHM symbol:
  lcd.write(1);
}

void loop() {
  // put your main code here, to run repeatedly:
float sensorvalue =analogRead(A0);// reading the input
float VoltageR2= sensorvalue * (5.0/1023.0) ;//turning the input into a voltage value in V
float Current=((5.0-VoltageR2)/R1); //calculating Current in mA
float R2=(VoltageR2/Current); //calculating resistance in k ohm acccross resistor 2





// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the resistance value on the LCD screen:
  lcd.print(R2);
  delay(1000); //stops it from rapidly changing the decimal point.

}
