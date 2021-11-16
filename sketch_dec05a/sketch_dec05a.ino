#include <Servo.h>

Servo myservo;  // create servo object to control a servo
//add more for more servos

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int previousVal = 0;
int saveButtonState = 0; //state of button
int saveButtonStateLast = 0;
int saveButton = 12; //digital pin used to read button state
int motorIndexButton = 4;
int motorIndexButtonState = 0;
int motorIndexButtonStateLast = 0;
int motorIndex = 0;
int savedPos = 0;
int pinSwitch = 7;
int pinSwitchState = 0;
int pinLED = 2;

int signs_data[100][5]; //100 signs storage, 5 servo values per sign
int signs_data_size = 0;
int current_sign = 0;
//int current_motors_pos[5]; //stores current positions of the servos

void setup() {
  myservo.attach(9, 771, 2740);  // attaches the servo on pin 9 to the servo object
  //add more for more servos
  pinMode(saveButton, INPUT);
  pinMode(motorIndexButton, INPUT);
  pinMode(pinSwitch, INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  pinSwitchState = digitalRead(pinSwitch);
  if (pinSwitchState == HIGH)
  {
    digitalWrite(pinLED, LOW);
    saveButtonState = digitalRead(saveButton);
    if (saveButtonState != saveButtonStateLast)
    {
      if (saveButtonState == HIGH)
      {
        signs_data[signs_data_size][0] = myservo.read();
        if (signs_data_size < 99)
           signs_data_size++;
        else
          Serial.println("Sign language memory is full, please manually increase");
        //need to add more for every servo
      }
    }
    saveButtonStateLast = saveButtonState;
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    motorIndexButtonState = digitalRead(motorIndexButton);
    if (motorIndexButtonState != motorIndexButtonStateLast)
    {
      if (motorIndexButtonState == HIGH)
      {
        motorIndex++;
        if (motorIndex > 4) {  motorIndex = 0; }
      }
    }
    if (abs(val - previousVal) > 2)
    {
      //need to change which servo to write to based on motorIndex
      myservo.write(val); // sets the servo position according to the scaled value if change in pos is greater than two
      previousVal = val;
    }
  }
  else
  {
    digitalWrite(pinLED, HIGH);
    motorIndexButtonState = digitalRead(motorIndexButton);
    if (motorIndexButtonState != motorIndexButtonStateLast)
    {
      if (motorIndexButtonState == HIGH)
      {
        if (current_sign < signs_data_size - 1)
          current_sign++;
        else
          current_sign = 0;
      }
    }
    myservo.write(signs_data[current_sign][0]);
    //need to add for every servo
  }
    
}
