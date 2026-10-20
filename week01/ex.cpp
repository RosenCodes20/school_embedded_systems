// C++ code
//
/*
  Button
  Turns on and off a light emitting diode(LED)
  connected to digital  pin 13, when pressing a
  pushbutton attached to pin 2.

   The circuit:
  * LED attached from pin 13 to ground
  * pushbutton attached to pin 2 from +5V
  * 10K resistor attached to pin 2 from ground
  * Note: on most Arduinos there is already an LED
  on the board  attached to pin 13.

  created 2005  by DojoDave <http://www.0j0.org>

  modified 30 Aug 2011  by Tom Igoe

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Button
*/

int buttonState = 0;

int pinOne = 13;
int pinTwo = 8;

int pinThree = 7;
int pinFour = 4;
int pinFive = 12;

int counter = 0;

int lastButtonState = LOW;

void setup()
{
  pinMode(2, INPUT);
  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
  pinMode(pinThree, OUTPUT);
  pinMode(pinFour, OUTPUT);
  pinMode(pinFive, OUTPUT);
}

void loop()
{
 
  buttonState = digitalRead(2);
  
  if (buttonState == HIGH && lastButtonState == LOW) {
 
        if (counter == 0) {
          digitalWrite(pinOne, HIGH);
        }

        else if (counter == 1) {
          digitalWrite(pinTwo, HIGH);
        }

        else if (counter == 2) {
          digitalWrite(pinThree, HIGH);
        }

        else if (counter == 3) {
          digitalWrite(pinFour, HIGH);
        }

        else if (counter == 4) {
          digitalWrite(pinFive, HIGH);
        }


          else if (counter == 5) {
          digitalWrite(pinFive, LOW);
          }

          else if (counter == 6) {
            digitalWrite(pinFour, LOW);
          }

          else if (counter == 7) {
            digitalWrite(pinThree, LOW);
          }

          else if (counter == 8) {
            digitalWrite(pinTwo, LOW);
          }

          else if (counter == 9) {
            digitalWrite(pinOne, LOW);
          }
    
    	counter++;
    
        if (counter > 9) {
            counter = 0;    
        }  
  }
  
  lastButtonState = buttonState;
}