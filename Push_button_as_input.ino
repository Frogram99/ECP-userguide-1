/*
Push button as an input

This program demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 4 and prints the results to the Serial Monitor.
  It also controls the output of Pin 10, in order to turn an LED on when the button is pressed.

You will need:
-breadbord
- 5 wires
-LED
-Pushbutton

  Wiring:
  -Connect a wire from pin 2 to the push button.
  -connect a wire from the push button to "-" of the bread board.
  -connect a wire from pin 10 to an LED.
  -connect a wire from the LED to "-" of the bread board.
  -connect a wire from "-" of the bread board to ground of the arduino.
*/
int pushbutton=4;  //This identifies pin 4 as the input for th epush button.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //start the serial connection.
  pinMode(pushbutton,INPUT_PULLUP); //this sets the pin 4 as an input.
  //INPUT_PULLUP, connects pin 4 to an internal resistor. This way you dont need an external resistor.
  pinMode (10, OUTPUT); // this sets pin 10 as an output.

}

void loop() {
  // put your main code here, to run repeatedly:
int buttonstate=digitalRead(pushbutton); // This identifies the buttonstate as the digital value of the push button.
Serial.println(buttonstate); //print out the value of the buttonstate.
delay(1);
//the button state will be High =1 when the button is not pressed.
//The button state will be low =0 when the button is pressed.
if (buttonstate == HIGH) { //if the button is not pressed
    digitalWrite(10, LOW); //Pin 10 is off and so is the LED.
  } else { //othewise = (if the button is pressed)
    digitalWrite(10, HIGH); // turn on pin 10, whish turns on the LED.
  }
  
}
