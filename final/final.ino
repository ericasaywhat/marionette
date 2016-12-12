#include "Arduino.h"
#include<Servo.h>
#include"Helper.h"
#include <Adafruit_MotorShield.h>




void setup () {
  // start serial communication.
  AFMS.begin();
  Serial.begin (9600);

  head.attach(12);
  arm1.attach(9);
  arm2.attach(11);
  legs.attach(10);

  rotate->setSpeed(150);
  gantry->setSpeed(150);

}

void loop () {

  right(1);
    
  left(2);
  restPos();
  sensorOneValue = analogRead(sens_oneIn);
  if(sensorOneValue > 230) {  
    
    while(Serial.available()>0) { 
      readInput();
    }
  
      for (int i = 0; i < index; i++) {
        Serial.println(commands[i]);
        Serial.println(durations[i]);
        if (commands[i] == "sword"){
          startTime = millis();
          Serial.print("wagao");
          while (millis() < startTime + durations[i].toInt()*1000) {
            swordFight(arm1,arm2,legs);      
          }
        commands[i] = "";
         } else if (commands[i] == "walk") {
            startTime = millis();
            Serial.print("wagao");
            while (millis() < startTime + durations[i].toInt()*1000) {
             walk(arm1,arm2,legs);      
            }
            commands[i] = "";
        } else if (commands[i] == "bow") {
            startTime = millis();
            Serial.print("wagao");
            while (millis() < startTime + durations[i].toInt()*1000) {
             bow(head);
             head.write(65);    //return to upright position      
            }
            commands[i] = "";      
        }
      } 
  }
}


