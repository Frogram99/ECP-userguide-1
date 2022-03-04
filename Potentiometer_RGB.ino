/*
Potentiometer + RGB

Use a potentiometer to change the colour of an RGB LED.
 A potentiometer can change it's resistance, which changes the voltage drop acrross it.
  The voltage drop is then picked by the arduino and converted into a bit value. 
  Using the change in bit value, we can change which pin will output a voltage for the RGB in order to change it's Colour.
  When the potentiometer is turned 1/3rd of the way, it goes from 0-341.
  When the potentiometer is turned 2/3rd of the way, it goes from 342-682.
  When the potentiometer is turned 3/3rd of the way, it goes from 683-1023.

You will need:
-breadboard
-220 ohm resistor
-wire X7
-RGB LED
-Potentiometer

Wiring:
 -connect a wire from the 5V power on the arduino to the left leg of the potentiometer.
 -conect a wire from the middle leg of the potentiometer to AO of the arduino.
 -connect a wire from ground of the arduino to the "-" part of the breadboard.
 -connect a wire from the "-" to the right leg of the potentiometer.
 -connect a wire from pin 9 of the arduino to the red leg of the RGB LED.
 -connect a wire from pin 10 of the arduino to the green leg of the RGB LED.
 -connect a wire from pin 11 of the arduino to the Blue leg of the RGB LED.
 -connect the cathode (last leg) of the RGB LED to a 220 ohm resistor.
 -connect the 220 ohm resistor to the "-".


*/

int Blue= 11; //identifying that the colour blue is powered by pin 11
int GREEN= 10; //identifying that the colour Green is powered by pin 10
int RED= 9; //identifying that the colour Red is powered by pin 9

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //begin serial communication
//set colour pins to outputs:
pinMode (Blue,OUTPUT); 
pinMode (RED,OUTPUT);
pinMode (GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   // read the input on analog pin 0:
  int knobturned = analogRead(A0);


Serial.println(analogRead(A0)); //show the value of the pentiometer
//if the value of the pentiometer is less than 341, the RGB LED turns blue:
if (knobturned<=341) { 
  analogWrite (Blue, 255); //make the RGB turn blue
  Serial.println ("1/3rd turned"); //lets you know that the Knob has been turned up to 1/3rd.
   delay(1);        // delay in between reads for stability
   //set the other colours as 0 to prevent 2 colours from being on at the same time.
   analogWrite (GREEN, 0); 
   analogWrite (RED, 0);
 } 
 //if the value is more than 341, then:
 //if the value of the pentiometer is less than 682, the RGB LED turns green:
 else if (knobturned<=682){
 analogWrite (GREEN, 255); //make the RGB turn green
 Serial.println ("2/3rd turned"); //lets you know that the Knob has been turned up to 2/3rd.
  delay(1);        // delay in between reads for stability
  //set the other colours as 0 to prevent 2 colours from being on at the same time.
  analogWrite (RED, 0);
  analogWrite (Blue, 0);
 }
 //if the value is more than 682, then:
 //if the value of the pentiometer is less than 1023, the RGB LED turns red:
else if (knobturned<=1023){
 analogWrite (RED, 255); //make the RGB turn red
 Serial.println ("3/3rd turned"); //lets you know that the Knob has been turned up to 3/3rd.
  delay(1);        // delay in between reads for stability
  //set the other colours as 0 to prevent 2 colours from being on at the same time.
  analogWrite (GREEN, 0);
  analogWrite (Blue, 0);

 } 
}
