#include "Arduino.h"
#include"Helper.h"
#include "utility/Adafruit_MS_PWMServoDriver.h"


#include<Servo.h>
#include <Adafruit_MotorShield.h>
//#include <Process.h>

void setup () {
  // start serial communication.
  AFMStop.begin();
  AFMSbot.begin();

//  Bridge.begin();  // Initialize the Bridge
//  Bridge.end();

  Serial.begin (9600);

  head.attach(12);
  arm1.attach(9);
  arm2.attach(11);
  legs.attach(10);

  rotate->setSpeed(150);
  gantry->setSpeed(10);

}

void loop () {
  
//  Process p;
  restPos();
  
//  moveRight(100);
  moveLeft(100);  //needs debugging once the belt is re-tensioned
  
  sensorOneValue = analogRead(sens_oneIn);

//Uncommenting the following three lines will allow for versatility in actions
//  while(Serial.available()>0) {
//    readInput();
//  }

  if (sensorOneValue > 230 or sensorTwoValue > 230) {
    openCurtains(105);
    delay(10);
    index = 2;
    commands[0] = "walk";
    commands[1] = "sword";
    commands[2] = "bow";
    durations[0] = 10;
    durations[1] = 10;
    durations[2] = 3;

  }

//  closeCurtains(105);
//  delay(5);
  
//  openCurtains(100);
//  delay(5);

  Serial.println("hi");


  for (int i = 0; i < index; i++) {
    if (commands[i] == "sword") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        swordFight(arm1, arm2, legs);
      }
      commands[i] = "";
    } else if (commands[i] == "walk") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        walk(arm1, arm2, legs);
      }
      commands[i] = "";
    } else if (commands[i] == "bow") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        bow(head);
        head.write(65);    //return to upright position
      }
      commands[i] = "";
    } else if (commands[i] == "turnRight") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        turnRight(durations[i]);
      }
      commands[i] = "";
    } else if (commands[i] == "turnLeft") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        turnLeft(durations[i]);
      }
      commands[i] = "";
    } else if (commands[i] == "moveRight") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        moveRight(100); //calibrate
      }
      commands[i] = "";
    } else if (commands[i] == "moveLeft") {
      startTime = millis();
      Serial.print("wagao");
      while (millis() < startTime + durations[i].toInt() * 1000) {
        moveLeft(100); //calibrate
      }
      commands[i] = "";
    } 
  }
//  closeCurtains(105);


}


