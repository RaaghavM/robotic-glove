#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
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
int current_sign = -1;
//int current_motors_pos[5]; //stores current positions of the servos

void setup() {
  Serial.begin(9600);
  
  servo1.attach(5, 771, 2740);  // attaches the servo on pin 5 to the servo object
  servo2.attach(10, 771, 2740);
  servo3.attach(6, 771, 2740);
  servo4.attach(9, 771, 2740);
  servo5.attach(11, 771, 2740);
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
          signs_data[signs_data_size][0] = servo1.read();
          signs_data[signs_data_size][1] = servo2.read();
          signs_data[signs_data_size][2] = servo3.read();
          signs_data[signs_data_size][3] = servo4.read();
          signs_data[signs_data_size][4] = servo5.read();
          //need to add more for every servo
          if (signs_data_size < 99)
            signs_data_size++;
          else
            Serial.println("Sign language memory is full, please manually increase");
      }
    }
    saveButtonStateLast = saveButtonState;
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 100);     // scale it to use it with the servo (value between 0 and 180)
    motorIndexButtonState = digitalRead(motorIndexButton);
    if (motorIndexButtonState != motorIndexButtonStateLast)
    {
      if (motorIndexButtonState == HIGH)
      {
        motorIndex++;
        if (motorIndex > 4) {  motorIndex = 0; }
      }
      motorIndexButtonStateLast = motorIndexButtonState;
    }
    if (abs(val - previousVal) > 2)
    {
      //need to change which servo to write to based on motorIndex
      if(motorIndex == 0)
        servo1.write(val);
      else if (motorIndex == 1)
        servo2.write(val);
      else if (motorIndex == 2)
        servo3.write(val);
      else if (motorIndex == 3)
        servo4.write(val);
      else if (motorIndex == 4)
        servo5.write(val);
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
      servo1.write(signs_data[current_sign][0]);
      delay(50);
      servo2.write(signs_data[current_sign][1]);
      delay(50);
      servo3.write(signs_data[current_sign][2]);
      delay(50);
      servo4.write(signs_data[current_sign][3]);
      delay(50);
      servo5.write(signs_data[current_sign][4]);
      delay(50);
    }
  }
    
}
