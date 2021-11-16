#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;


void setup() {
  // put your setup code here, to run once:
  servo1.attach(5);
  servo2.attach(10);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(11);

  //initialize position
  servo1.write(0);
  delay(2000);
  servo2.write(0);
  delay(2000);
  servo3.write(0);
  delay(2000);
  servo4.write(0);
  delay(2000);
  servo5.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //start sign
  servo1.write(100);
  delay(25);
  servo3.write(100);
  delay(25);
  servo4.write(100);
  delay(25);
  servo5.write(100);
  delay(25);
  
  delay(2000);
  
  servo3.write(0);
  
  delay(2000);
  
  servo1.write(0);
  
  delay(2000);
  
  servo1.write(100);
  delay(25);
  servo4.write(0);
  delay(25);
  servo5.write(0);
  delay(25);

  delay(2000);

  servo1.write(0);

  delay(2000);

  servo5.write(100);
  delay(25);
  servo1.write(100);
  delay(25);

  delay(2000);

  servo5.write(0);
  delay(25);
  servo4.write(100);
  delay(25);

  delay(2000);

  servo4.write(0);
  delay(25);
  servo3.write(100);
  delay(25);

  delay(2000);

  servo3.write(0);
  delay(25);
  servo2.write(100);
  delay(25);

  delay(2000);

  

  

  
  
  
}
