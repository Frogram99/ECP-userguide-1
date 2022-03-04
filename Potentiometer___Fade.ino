/*
  Pentiometer + Fade

  Use a potentiometer to change the brightness in an LED.
  A potentiometer can change it's resistance, which changes the voltage drop acrross it.
  The voltage drop is then picked by the arduino and converted into a bit value. 
  Using the change in bit value, we can change the output for an LED in order to change it's brightness.

  You will need:
  -breadboard
  -220 ohm resistor
  -wire x6
  -LED
  -potentiometer

  Wiring:
  -connect a wire from the 5V power on the arduino to the left leg of the potentiometer.
  -conect a wire from the middle leg of the potentiometer to AO of the arduino.
  -connect a wire from ground of the arduino to the "-" part of the breadboard.
  -connect a wire from the "-" to the right leg of the potentiometer.
  -connect a wire from pin 9 of the arduino to the 220 ohm resistor.
  -connect a LED to the resistor then connect a wire from the LED to the "-".
  
*/

int led = 9;           // the pin the LED is attached to
int brightness = 0;    // how bright the LED is

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(brightness);
  delay(1);        // delay in between reads for stability
  
    // set the brightness of pin 9:
  analogWrite(led, brightness);
  //to convert pot value to brightness: conversion value= max brightness/max pot 
  //conversion value = 255/1023 = 0.2493.
  // The brightness becomes the voltage accross the pot * the conversion value:
  brightness = sensorValue *0.2493; //now the brighness is changed based on the value of the POT.
}
