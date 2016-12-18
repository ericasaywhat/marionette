//HelperFunctions.h
 
#ifndef HEADER_HELPERFUNC
  #define HEADER_HELPERFUNC

#include "Arduino.h"
#include<Servo.h>
#include <Adafruit_MotorShield.h>

Servo arm1;
Servo arm2;
Servo legs;
Servo head;

Adafruit_MotorShield AFMSbot(0x61); 
Adafruit_MotorShield AFMStop(0x60); 

Adafruit_DCMotor *rotate = AFMSbot.getMotor(1);
Adafruit_StepperMotor *gantry = AFMStop.getStepper(200,2);
Adafruit_StepperMotor *curtains = AFMSbot.getStepper(200,2);

   


int pos = 0;
int pos2 = 0;
int legPos;
int legPos1;
int index ;
const int numActions = 3;
unsigned long startTime;
unsigned long endTime;
String input;
String commands[numActions];
String durations[numActions];

const int sens_oneIn = A0;
const int sens_twoIn = A1;
int sensorOneValue = 0;
int sensorTwoValue = 0;




void openCurtains(int steps) {
  curtains->step(steps, BACKWARD,DOUBLE); 
  delay(10);
  curtains->release(); 
}

void closeCurtains(int steps) {
  curtains->step(steps, FORWARD,DOUBLE);
  delay(10);
  curtains->release(); 
  
}

void moveRight(int steps) {
  gantry->step(steps,FORWARD,SINGLE);  

}

void moveLeft(int steps) {
  gantry->step(steps,BACKWARD, SINGLE);  
}


void turnRight(int milli){
  startTime = millis();
  rotate->run(FORWARD);  
  while (millis()-startTime< milli*1000) {
    rotate->setSpeed(100);  
  }
}

void turnLeft(int milli){
  startTime = millis();
  rotate->run(BACKWARD);
  while (millis()-startTime<milli*1000) {
    rotate->setSpeed(100);  
    delay(10);
  }
}

void readInput(){
  input = Serial.readString();
  Serial.println("Start");
  while(index < numActions){
    commands[index] = input.substring(0,input.indexOf(','));
    durations[index] = input.substring(input.indexOf(',')+1, input.indexOf(';'));
    index += 1;
    input = input.substring(input.indexOf(';')+1);
 }
}
  

void restPos() {
    arm1.write(170);
    arm2.write(0);
    legs.write(135);
    head.write(65);
}

void walk(Servo servo1, Servo servo2, Servo servo3) {
  legPos = 180;
  legPos1 = 95;

  for (pos = 90; pos <= 180; pos += 2) {       // goes from 0 degrees to 180 degrees
      
      servo1.write(pos);
      servo2.write(pos-90);
      servo3.write(legPos);
      legPos -= 1;
      delay(15); 
  }
    for (pos = 180; pos >= 90; pos -= 2) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      servo2.write(pos-90);
      servo3.write(legPos1);
      legPos1 += 1;
      delay(15);                       // waits 15ms for the servo to reach the position
      
  }
}

void paceRight(Servo servo1, Servo servo2, Servo servo3) {
  legPos = 180;
  legPos1 = 95;

  for (pos = 90; pos <= 180; pos += 2) {       // goes from 0 degrees to 180 degrees
      gantry->onestep(FORWARD,SINGLE);
      servo1.write(pos);
      servo2.write(pos-90);
      servo3.write(legPos);
      legPos -= 1;
      delay(15); 
  }
    for (pos = 180; pos >= 90; pos -= 2) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      servo2.write(pos-90);
      servo3.write(legPos1);
      legPos1 += 1;
      delay(15);                       // waits 15ms for the servo to reach the position 
  };
}

void paceLeft(Servo servo1, Servo servo2, Servo servo3) {
  legPos = 180;
  legPos1 = 95;

  for (pos = 90; pos <= 180; pos += 2) {       // goes from 0 degrees to 180 degrees
      gantry->onestep(BACKWARD,SINGLE);
      servo1.write(pos);
      servo2.write(pos-90);
      servo3.write(legPos);
      legPos -= 1;
      delay(15); 
  }
    for (pos = 180; pos >= 90; pos -= 2) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      servo2.write(pos-90);
      servo3.write(legPos1);
      legPos1 += 1;
      delay(15);                       // waits 15ms for the servo to reach the position 
  };
}

void swordFight (Servo servo1, Servo servo2, Servo servo3) {
  legPos = 180;
  legPos1 = 95;

  for (pos = 125; pos <= 145; pos += 1) {       // goes from 0 degrees to 180 degrees
      
      servo1.write(pos);
      servo2.write(pos-90); 
      servo3.write(140);
      legPos -= 1;

      delay(15);
      servo2.write(legPos);      
  }
    for (pos = 145; pos >= 125; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'

      servo2.write(pos-90);
      servo3.write(130);
      legPos1 += 1;
      servo2.write(legPos1);
      delay(15);                       // waits 15ms for the servo to reach the position 
  }
  
}

void bow(Servo servo1){
  for (pos = 0; pos <= 65; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 65; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void rest(Servo servo1, Servo servo2, Servo servo3) {
  int servo1Pos = servo1.read();
  int servo2Pos = servo2.read();
 
    if (servo1Pos<170) {
      for (servo1Pos; servo1Pos <= 170; pos++) {
        servo1.write(servo1Pos);
        if (servo2Pos != 0) {
          servo2Pos--;
          servo2.write(servo2Pos);
        }
     }
    } else {
          if (servo2Pos != 0) {
            servo2Pos--;
            servo2.write(servo2Pos);
          } 
      }
    servo3.write(135);
   
}




  #endif
