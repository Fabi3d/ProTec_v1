#include "line.h"
#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"
#include <Arduino.h>
#include <Pixy2.h>

int or_treshold = 680;
int ir_treshold = 680;
int m_treshold = 670;
int il_treshold = 680;
int ol_treshold = 650;

int loop_counter=0;

int sw520 = 47;
int led = 40;

void follow_line() {
  loop_counter++;
  readout();
  if(loop_counter>=5){    //This readout is only taken every 5 loops
    ultrasonic_readout();
    if(distance<15){
      stop_motors();
      while(true){
        
      }
    }
    loop_counter=0;
  }
  if ((middle_LDR < m_treshold) && ((ol_LDR > ol_treshold && il_LDR > il_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) || (ol_LDR > ol_treshold && or_LDR > or_treshold))) {     //if statement for all straight cases
    straight(v1 - 10);
    Serial.println("straight");
  }
  readout();

  if ((ir_LDR < ir_treshold && or_LDR > or_treshold && il_LDR > il_treshold && ol_LDR > ol_treshold) || (or_LDR > or_treshold && ir_LDR < ir_treshold && il_LDR > il_treshold && ol_LDR > ol_treshold && middle_LDR < m_treshold)) {  //if statement for a little correction to the right (00?10) or (00110)
    readout();
    // while(middle_LDR > m_treshold){
    turn_right(v2 - 30, v1 + 5);
    readout();
    // }
  }

  if ((il_LDR < il_treshold && or_LDR > or_treshold && ir_LDR > ir_treshold && ol_LDR > ol_treshold) || (or_LDR > or_treshold && ir_LDR > ir_treshold && il_LDR < ol_treshold && ol_LDR > ol_treshold && middle_LDR < m_treshold)) {    //if statement for a little correction to the left (01?00) or (01100)
    readout();
    // while(middle_LDR > m_treshold){
    turn_left(v1 + 10, v2 - 25);
    readout();
    // }
  }

  if ((ol_LDR < ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) || (ol_LDR < ol_treshold && il_LDR < il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold)) {   //(11000) or (10000)
    green();
    while (middle_LDR > m_treshold) {
      turn_left(v1 + 35, v2 + 15);
      readout();
    }
  }
  readout();

  if ((ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR < or_treshold) || (ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR < ir_treshold && or_LDR < or_treshold)) {  //(00011) or (00001)
    green();
    while (middle_LDR > m_treshold) {
      turn_right(v2 + 22, v1 + 5);
      readout();
    }
  }
  readout();

  if (ol_LDR < ol_treshold && il_LDR < il_treshold && middle_LDR < m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) {  //90° turn to the left
    straight(v1);
    delay(120);
    //turn_left(v1+5, v1+22);
    //delay(150);
    readout();
    while (middle_LDR > m_treshold) {
      turn_left(v1 + 5, v1 + 22);
      readout();
    }

  }
  if (ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR < m_treshold && ir_LDR < ir_treshold && or_LDR < or_treshold) {  //90° turn to the right
    straight(v1);
    delay(120);
    // turn_right(v1+22, v1+5);
    //delay(150);
    readout();
    while (middle_LDR > m_treshold) {
      turn_right(v1 + 22, v1 + 5);
      readout();
    }

  }
  readout();

  if ((ol_LDR > ol_treshold) && (il_LDR > il_treshold) && (middle_LDR > m_treshold) && (ir_LDR > ir_treshold) && (or_LDR > or_treshold)) {
    Serial.println("start millis");
    unsigned long nowtime = millis();
    while ((ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) && millis() - nowtime <= 1500) {
      readout();
      straight(v1);

    }
    while (ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) {
      back(v1);
      readout();
      delay(100);
    }

  }

  if (gyro == 0) {        //Rampe
    counter++;
    if (counter > 100) {
      if (middle_LDR < m_treshold) {
        straight(245);
      }
      if (ir_LDR < ir_treshold) {
        turn_right(100, 245);
      }
      if (il_LDR < il_treshold) {
        turn_left(245, 100);
      }
    }
  }
  if (gyro == 1) {
    counter = 0;
  }
}
