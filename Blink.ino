/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. 
  On the UNO it is attached to digital pin 13. 
  LED_BUILTIN is set to that pin.

You will need:
-breadbord
-220 ohm resistor
- 3 wires
-LED

  Wiring:
  -Connect a wire from pin 13 to a 220 ohm resistor.
  -connect a wire from the resistor to an LED.
  -connect a wire from the LED to ground of the arduino.
  
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
