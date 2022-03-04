/*
  For Loop Iteration

  Demonstrates the use of a for() loop.
  Lights multiple LEDs in sequence, then in reverse.

  The circuit:
  - LEDs from pins 2 through 7 to ground

  What you need:
  -arduino Board
  -220 ohm resistor X6
  -Led X6
  -wires X13
  -breadbord

  Wiring:
  -connect a wire from pin 7 to a 220 ohm resistor.
  -place the Led in the same row as the resistor. 
  -connect a wire from The LED to ground.
  -repeat for pins: 6,5,4,3,and 2. With the other LED's and 220 ohm resistors.

  (the electricity from a pin should pass through a resistor, then through an LED, 
  then go to ground.)

*/

int timer = 100;           // The higher the number, the slower the timing.

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH); //this turns the active pin on, which powers it's LED.
    delay(timer); // the delay allows the LED to stay on long enough for us to see it.
    // turn the pin off: //this turns the active pin off, which turns off it's LED.
    digitalWrite(thisPin, LOW);
    //this loop turns every LED on then off in sequence, stopping once all LED's have turned on once.
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = 7; thisPin >= 2; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH); //this turns the active pin on, which powers it's LED.
    delay(timer); // the delay allows the LED to stay on long enough for us to see it.
    // turn the pin off:
    digitalWrite(thisPin, LOW); //this turns the active pin off, which turns off it's LED.
    //this loop turns every LED on then off in reverse order, stopping once all LED's have turned on once.
  }
}
