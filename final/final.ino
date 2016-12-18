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
  curtains->setSpeed(30);


}

void loop () {
  restPos();

//paceLeft,5;turnRight,2;paceRight,5;turnLeft,2;paceLeft,15

//  Uncommenting the following three lines will allow for versatility in actions
//  while(Serial.available()>0) {
//    readInput();
//  }
  sensorOneValue = analogRead(sens_oneIn);
  if (sensorOneValue > 250 or sensorTwoValue > 250) {
    openCurtains(1350);
    //hardcoded actions
    commands[0] = "paceLeft";
    commands[1] = "turnRight";
    commands[2] = "paceRight";
    commands[3] = "sword";
    commands[4] = "turnLeft";
    commands[5] = "paceLeft";

    durations[0] = 8;
    durations[1] = 2;
    durations[2] = 5;
    durations[3] = 30;
    durations[4] = 2;
    durations[5] = 5;
    
    

      
    for (int i = 0; i < numActions+1; i++) {
        Serial.println(commands[0]);

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
      } else if (commands[i] == "paceRight") {
        startTime = millis();
        Serial.print("wagao");
        while (millis() < startTime + durations[i].toInt() * 1000) {
          paceRight(arm1, arm2, legs);
        }
        commands[i] = "";
      } else if (commands[i].equals("paceLeft")) {
        startTime = millis();
        Serial.print("wagao");
        while (millis() < startTime + durations[i].toInt() * 1000) {
          paceLeft(arm1, arm2, legs);
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
          turnRight(durations[i].toInt());
        }
        commands[i] = "";
      } else if (commands[i] == "turnLeft") {
        startTime = millis();
        Serial.print("wagao");
        while (millis() < startTime + durations[i].toInt() * 1000) {
          turnLeft(durations[i].toInt());
        }
        commands[i] = "";
      } else if (commands[i] == "moveRight") {
        startTime = millis();
        Serial.print("wagao");
        while (millis() < startTime + durations[i].toInt() * 1000) {
          moveRight(80); //calibrate
        }
        commands[i] = "";
      } else if (commands[i] == "moveLeft") {
          startTime = millis();
          Serial.print("wagao");
          while (millis() < startTime + durations[i].toInt() * 1000) {
            moveLeft(80); //calibrate
          }
        commands[i] = "";
        }
      }
      closeCurtains(1250);        
      
      

    }
}


