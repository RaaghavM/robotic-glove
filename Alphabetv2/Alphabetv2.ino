/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500// This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  // In theory the internal oscillator is 25MHz but it really isn't
  // that precise. You can 'calibrate' by tweaking this number till
  // you get the frequency you're expecting!
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz  
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);

  //resetAllToStart();

  //moveServo(0, 0, 170, 5);

  delay(500);

  moveServo(5, 0, 85, 30);

  delay(1000);

  moveZFromStart();
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {

  //moveAFromStart();
  
}

void resetAllToStart()
{
  pwm.setPWM(0, 0, SERVOMIN);
  pwm.setPWM(1, 0, SERVOMIN);
  pwm.setPWM(2, 0, SERVOMIN);
  pwm.setPWM(3, 0, SERVOMAX);
  pwm.setPWM(4, 0, SERVOMAX);
}

void moveAFromStart()
{
  moveServo(1, 0, 170, 3);
  moveServo(2, 0, 170, 3);
  moveServo(3, 170, 0, 3);
  moveServo(4, 170, 0, 3);
  //moveServo(5, 0, 85, 20);//abduct thumb to 90
}

void moveBFromStart()
{
  //abduct thumb to 90
  moveServo(0, 0, 100, 1);
}

void moveCFromStart()
{
  moveServo(0, 0, 100, 3);
  moveServo(1, 0, 100, 3);
  moveServo(2, 0, 100, 3);
  moveServo(3, 170, 70, 3);
  moveServo(4, 170, 70, 3);
}

void moveDFromStart()
{
  moveServo(0, 0, 100, 3);
  moveServo(2, 0, 170, 3);
  moveServo(3, 170, 20, 3);
  moveServo(4, 170, 20, 3);
}

void moveEFromStart()
{
  //abduct thumb to 80
  moveServo(0, 0, 170, 3);
  moveServo(1, 0, 150, 3);
  moveServo(2, 0, 150, 3);
  moveServo(3, 170, 20, 3);
  moveServo(4, 170, 20, 3);
}

void moveFFromStart()
{
  moveServo(0, 0, 100, 3);
  moveServo(1, 0, 150, 3);
  moveServo(2, 0, 20, 3);
}

void moveGFromStart()
{
  //abduct thumb to 80
  moveServo(0, 0, 100, 1);
  moveServo(2, 0, 170, 1);
  moveServo(3, 170, 0, 1);
  moveServo(4, 170, 0, 1);
}

void moveHFromStart()
{
  //abduct thumb to 80
  moveServo(0, 0, 20, 3);
  moveServo(3, 170, 0, 3);
  moveServo(4, 170, 0, 3);
}

void moveIFromStart()
{
  moveServo(1, 0, 170, 3);
  moveServo(2, 170, 0, 3);
  moveServo(3, 170, 0, 3);
  //abduct thumb to 30
  moveServo(0, 0, 50, 3);
}

void moveJFromStart()
{
  //in motion
  moveIFromStart();
}

void moveKFromStart()
{
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 0, 5);
  //abduct thumb to 90
  //moveServo(0, 0, 170, 5);
}

void moveLFromStart()
{
  moveServo(2, 0, 170, 5);
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 0, 5);
}

void moveMFromStart()
{
  moveServo(4, 170, 0, 5);
  delay(5);
  moveServo(0, 0, 170, 5);
  delay(5);
  moveServo(1, 0, 170, 5);
  moveServo(2, 0, 170, 5);
  moveServo(3, 170, 0, 5);
  
}

void moveNFromStart()
{
  moveServo(4, 170, 0, 5);
  moveServo(3, 170, 0, 5);
  delay(5);
  moveServo(0, 0, 170, 5);
  delay(5);
  moveServo(1, 0, 170, 5);
  moveServo(2, 0, 170, 5);
}

void moveOFromStart()
{
  moveServo(4, 170, 30, 5);
  moveServo(3, 170, 30, 5);
  moveServo(2, 0, 140, 5);
  moveServo(1, 0, 140, 5);
  moveServo(0, 0, 100, 5);
}

void movePFromStart()
{
  //wrist rotation
  moveKFromStart();
}

void moveQFromStart()
{
  moveServo(4, 170, 0, 5);
  moveServo(3, 170, 0, 5);
  moveServo(2, 0, 170, 5);
  moveServo(0, 0, 50, 5);
  moveServo(1, 0, 80, 5);
}

void moveRFromStart()
{
  moveServo(4, 170, 0, 1);
  moveServo(3, 170, 0, 1);
  moveServo(0, 0, 170, 1);
}

void moveSFromStart()
{
  moveServo(1, 0, 170, 5);
  moveServo(2, 0, 170, 5);
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 0, 5);
  moveServo(0, 0, 150, 5);
}

void moveTFromStart()
{
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 0, 5);
  moveServo(2, 0, 170, 5);
  //abduct thumb to 90
  moveServo(0, 170, 0, 5);
  moveServo(1, 0, 150, 5);
}

void moveUFromStart()
{
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 20, 5);
  moveServo(0, 170, 0, 5);
}

void moveVFromStart()
{
  //same as U but abduct finger 1 and 2
  moveServo(3, 170, 0, 5);
  moveServo(4, 170, 20, 5);
  moveServo(0, 170, 0, 5);
}

void moveWFromStart()
{
  //abduct finger 1, 2, and 3
  moveServo(4, 170, 20, 5);
  moveServo(0, 170, 0, 5);
}

void moveXFromStart()
{
  moveServo(4, 170, 0, 5);
  moveServo(3, 170, 0, 5);
  moveServo(2, 0, 170, 5);
  moveServo(1, 0, 60, 5);
  moveServo(0, 0, 150, 5);
}

void moveYFromStart()
{
  moveServo(3, 170, 0, 5);
  moveServo(2, 0, 170, 5);
  moveServo(1, 0, 170, 5);
}

void moveZFromStart()
{
  //in motion
  moveServo(4, 170, 0, 5);
  moveServo(3, 170, 0, 5);
  moveServo(2, 0, 170, 5);
  moveServo(0, 0, 150, 5);
}

void moveABCD()
{
  //Letter A 
  moveServo(1, 0, 170, 1);
  moveServo(2, 0, 170, 1);
  moveServo(3, 170, 0, 1);
  moveServo(4, 170, 0, 1);

  delay(1000);

  //Letter B
  moveServo(0, 170, 100, 1);
  moveServo(1, 170, 0, 1);
  moveServo(2, 170, 0, 1);
  moveServo(3, 0, 170, 1);
  moveServo(4, 0, 170, 1);
  
  delay(1000);

  //Letter C
  moveServo(0, 100, 50, 1);
  moveServo(1, 0, 100, 1);
  moveServo(2, 0, 100, 1);
  moveServo(3, 170, 70, 1);
  moveServo(4, 170, 70, 1);

  delay(1000);

  //Letter D
  moveServo(1, 100, 0, 1);
  moveServo(2, 100, 170, 1);
  moveServo(3, 70, 0, 1);
  moveServo(4, 70, 0, 1);

  delay(1000);
}

void moveServo(int servonum, int fromAngle, int toAngle, int rate)
{
  if (fromAngle > toAngle)
  {
    for (int i = fromAngle; i >= toAngle; i--)
    {
      pwm.setPWM(servonum, 0, map(i, 0, 170, SERVOMIN, SERVOMAX));
      delay(rate);
    }
  }
  else
  {
    for (int i = fromAngle; i <= toAngle; i++)
    {
      pwm.setPWM(servonum, 0, map(i, 0, 170, SERVOMIN, SERVOMAX));
      delay(rate);
    }
  }
}
