#include "line.h"
#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"
#include <Arduino.h>

int or_treshold = 500;
int ir_treshold = 500;
int m_treshold = 500;
int il_treshold = 500;
int ol_treshold = 500;

void follow_line(){

  readout();
 if((middle_LDR < m_treshold) && ((ol_LDR > ol_treshold && il_LDR > il_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) || (ol_LDR > ol_treshold && or_LDR > or_treshold))) {      //if statement for all straight cases
    straight(v1);
    Serial.println("straight");
  }
  readout(); 
  
  if((ir_LDR < ir_treshold && or_LDR > or_treshold && il_LDR > il_treshold && ol_LDR > ol_treshold) || (or_LDR > or_treshold && ir_LDR < ir_treshold && il_LDR > il_treshold && ol_LDR > ol_treshold && middle_LDR < m_treshold)){    //if statement for a little correction to the right (00?10) or (00110)
    readout();
    while(middle_LDR > m_treshold){
      turn_right(v2+22, v1+5);
      readout();  
    }
  }
  
  if((il_LDR < il_treshold && or_LDR > or_treshold && ir_LDR > ir_treshold && ol_LDR > ol_treshold) || (or_LDR > or_treshold && ir_LDR > ir_treshold && il_LDR < ol_treshold && ol_LDR > ol_treshold && middle_LDR < m_treshold)){      //if statement for a little correction to the left (01?00) or (01100)
    readout();
    while(middle_LDR > m_treshold){
      turn_left(v1+35, v2+15);
      readout();
    }
  }

  if((ol_LDR < ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) || (ol_LDR < ol_treshold && il_LDR < il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold)){     //(11000) or (10000)
    while(middle_LDR > m_treshold){
      turn_left(v1+35, v2+15);
      readout();
    }
  }
  readout();
  
 if((ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR < or_treshold) || (ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR < ir_treshold && or_LDR < or_treshold)){    //(00011) or (00001)
    while(middle_LDR > m_treshold){
      turn_right(v2+22, v1+5);
      readout();
    }
  } 
  readout();
  
  if(ol_LDR < ol_treshold && il_LDR < il_treshold && middle_LDR < m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold){    //90° turn to the left
    straight(v1);
    delay(150);
    turn_left(v1+5, v1+22);
    delay(150);
    readout();
    while(middle_LDR > m_treshold){
      turn_left(v1+5, v1+22);
      readout();
    }
  }
  if(ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR < m_treshold && ir_LDR < ir_treshold && or_LDR < or_treshold){    //90° turn to the right
    straight(v1);
    delay(150);
    turn_right(v1+22, v1+5);
    delay(150);
    readout();
    while(middle_LDR > m_treshold){
      turn_right(v1+22, v1+5);
      readout();
    }
  }
  readout();
  
  if((ol_LDR > ol_treshold) && (il_LDR > il_treshold) && (middle_LDR > m_treshold) && (ir_LDR > ir_treshold) && (or_LDR > or_treshold)){
    Serial.println("start millis");
    unsigned long nowtime = millis();
    while((ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold)&&millis() - nowtime <= 1500){
      readout();
      straight(v1);
      
    }
    while(ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold){
          back(v1);
          readout();
          delay(10);
      }
    }
  
  }
  
