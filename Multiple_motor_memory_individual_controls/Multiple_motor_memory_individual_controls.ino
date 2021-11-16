#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
//add more for more servos

int potpin1 = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;
int potpin3 = 2;
int potpin4 = 3;

int val1;    // variable to read the value from the analog pin
int val2;
int val3;
int val4;
int val5;
int previousVal1 = 0;
int previousVal2 = 0;
int previousVal3 = 0;
int previousVal4 = 0;
int previousVal5 = 0;
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
  
  servo1.attach(9, 771, 2740);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10, 771, 2740);
  servo3.attach(11, 771, 2740);
  servo4.attach(6, 771, 2740);
  //servo5.attach(5, 771, 2740);
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
    val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
    val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
    val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)
    val3 = map(val3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023)
    val4 = map(val4, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    Serial.println(val1);
    Serial.println(val2);
    Serial.println(val3);
    Serial.println(val4);
    //val5 = analogRead(potpin5);            // reads the value of the potentiometer (value between 0 and 1023)
    //val5 = map(val5, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//    motorIndexButtonState = digitalRead(motorIndexButton);
//    if (motorIndexButtonState != motorIndexButtonStateLast)
//    {
//      if (motorIndexButtonState == HIGH)
//      {
//        motorIndex++;
//        if (motorIndex > 4) {  motorIndex = 0; }
//      }
//      motorIndexButtonStateLast = motorIndexButtonState;
//    }
//    if (abs(val - previousVal) > 2)
//    {
//      //need to change which servo to write to based on motorIndex
//      if(motorIndex == 0)
//        servo1.write(val);
//      else if (motorIndex == 1)
//        servo2.write(val);
//      else if (motorIndex == 2)
//        servo3.write(val);
//      else if (motorIndex == 3)
//        servo4.write(val);
//      else if (motorIndex == 4)
//        servo5.write(val);
//      previousVal = val;
//    }
      if(abs(val1-previousVal1) > 2)
      {
          servo1.write(val1);
      }
      delay(15);
      if(abs(val2-previousVal2) > 2)
      {
          servo2.write(val2);
      }
      delay(15);
      if(abs(val3-previousVal3) > 2)
      {
          servo3.write(val3);
      }
      delay(15);
      if(abs(val4-previousVal4) > 2)
      {
          servo4.write(val4);
      }
      delay(15);
      previousVal1 = val1;
      previousVal2 = val2;
      previousVal3 = val3;
      previousVal4 = val4;
      //previousVal5 = val5;
//      if(abs(val1-previousVal1) > 2)
//      {
//          servo1.write(val5)
//      }
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
      delay(2000);
      servo2.write(signs_data[current_sign][1]);
      delay(2000);
      servo3.write(signs_data[current_sign][2]);
      delay(2000);
      servo4.write(signs_data[current_sign][3]);
      delay(2000);
      servo5.write(signs_data[current_sign][4]);
      delay(2000);
    }
  }
    
}
