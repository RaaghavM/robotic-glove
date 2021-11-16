#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int previousVal = 0;
int pinButtonState = 0; //state of button
int pinButtonStateLast = 0;
int pinButton = 12; //digital pin used to read button state
int savedPos = 0;
int pinSwitch = 7;
int pinSwitchState = 0;
int pinLED = 2;


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pinButton, INPUT);
  pinMode(pinSwitch, INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  pinSwitchState = digitalRead(pinSwitch);
  if (pinSwitchState == HIGH)
  {
    digitalWrite(pinLED, LOW);
    pinButtonState = digitalRead(pinButton);
    if (pinButtonState != pinButtonStateLast)
    {
      if(pinButtonState == HIGH)
      {
        savedPos = myservo.read();
      }
    }
    pinButtonStateLast = pinButtonState;
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    if (abs(val - previousVal) > 2)
    {
      myservo.write(val); // sets the servo position according to the scaled value if change in pos is greater than two
      previousVal = val;
    }
  }
  else
  {
    digitalWrite(pinLED, HIGH);
    myservo.write(savedPos);
  }
    
}
