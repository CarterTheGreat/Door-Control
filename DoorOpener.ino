#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor = AFMS.getMotor(1);
Servo servo;

void setup() {
  Serial.begin(9600);  

  AFMS.begin();  //1.6KHz
 
  //speed from 0 to 255
  motor->setSpeed(0);
  motor->run(RELEASE);
  
  servo.attach(9);
  servo.write(map(0,0,255,0,180));
  delay(2000);
  
}

void loop() {


  Serial.println("Start");
  
  openDoor();
  delay(10000);

  closeDoor();
  delay(10000);
  Serial.println("End");

}



void openDoor(){
  Serial.println("Open");
  lowerMotor();
  openMotor();
  raiseMotor();
}

void closeDoor(){
  Serial.println("Close");
  lowerMotor();
  closeMotor();
  raiseMotor();
}

void lowerMotor(){

  
  Serial.println("Lower");
  
  for (int i=0; i<=35; i++) {
    servo.write(map(i, 0, 255, 0, 180));
    delay(1);
  }
}

void raiseMotor(){
  
  Serial.println("Raise");
  
  for (int i=35; i>=0; i--) {
    servo.write(map(i, 0, 255, 0, 180));
    delay(1);
  }
}

void openMotor(){
  uint8_t i;
  Serial.println("Motor Open");
  
  motor->run(FORWARD);
  motor->setSpeed(i); 
  for (i=0; i<155; i++) {
    motor->setSpeed(i);  
    delay(10);
  }
  delay(1000);
  
  
  motor->run(RELEASE);
  
}

void closeMotor(){
  uint8_t i;
  Serial.println("Motor Close");

  motor->run(BACKWARD);
  for (i=0; i<155; i++) {
    motor->setSpeed(i);  
    delay(10);
  }
  delay(1000);
  
  motor->run(RELEASE);
}
