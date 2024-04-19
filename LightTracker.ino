#include <Servo.h>

#define SERVO_PIN 12

Servo trackerServo ;
uint8_t leftLDR = 0;
uint8_t rightLDR = 1;
int LEFT = 0;
int RIGHT = 0;
int ERROR = 0;
int calibration = 600;
uint8_t trackerServoposition = 90;


void setup(){
  pinMode(SERVO_PIN,OUTPUT);
  Serial.begin(9600);
  trackerServo.attach(SERVO_PIN);
}

void loop(){

trackerFunction();

}

void trackerFunction(){
  LEFT = analogRead(leftLDR);
  RIGHT = analogRead(rightLDR);
  if (LEFT < 350 && RIGHT < 350)
  {
    while (trackerServoposition <= 150)
    {
      trackerServoposition++;
      trackerServo.write(trackerServoposition);
      delay(100);
    }
  }
  ERROR = LEFT - RIGHT;

  if (ERROR > 15)
  {
    if (trackerServoposition <= 150)
    {
      trackerServoposition++;
      trackerServo.write(trackerServoposition);
    }
  }
  else if (ERROR < -15)
  {
    if (trackerServoposition > 20)
    {
      trackerServoposition--;
      trackerServo.write(trackerServoposition);
    }
  }
}