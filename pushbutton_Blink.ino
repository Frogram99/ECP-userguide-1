/*
Push button LED + blink without delay

This program demonstrates how you can do multiple things at once in a program despite delays.
The push button sends a signal to pin 4, which then sends a signal through pin 10 in order to turn an LED on and off.
Simultaneously, Pin 13 is sending a signal to another LED, which makes it turn on and off without the use of delays.




You will need:
-breadboard
-220 ohm resistor X2
-wire X5
-LED X2
-push button

wiring:
-connect a wire from ground of the arduino to the "-" part of the breadboard.
-connect a wire from the "-" to a leg of the push button.
-conect a wire from the other leg of the push button to pin 4 of the arduino.
-connect a wire from pin 10 of the arduino to the 1st 220 ohm resistor.
-connect the 1st 220 ohm resistor to the 1st LED.
-connect the 1st LED to the "-" of the breadboard.
-connect a wire from pin 13 of the arduino to the 2nd 220 ohm resistor.
-connect the 2nd 220 ohm resistor to the 2nd LED.
-connect the 2nd LED to the "-" of the breadboard.


*/

int pushbutton = 4; //the value of the push button will be read at pin 4

// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // put your setup code here, to run once:
pinMode (pushbutton,INPUT_PULLUP); //use the internal resistance inside the arduino for pin 4
pinMode (ledPin, OUTPUT); // set pin 13 as an output, so that the LED can blink.
pinMode (10, OUTPUT); // set pin 10 as an output, so it can turn on and off.
Serial.begin(9600); //start serial communications.

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonstate=digitalRead (pushbutton); //button state is the digital value of pin 4.
  if (buttonstate == LOW) { //if the button is pressed:
    digitalWrite (10,HIGH); //turn LED on.
  }
  else {
    digitalWrite(10,LOW); //if the button isn't pressed, turn LED off.
  }
 
  Serial.println(buttonstate); //print value of buttonstate.
  delay(1); //give time to read it

   // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  }
