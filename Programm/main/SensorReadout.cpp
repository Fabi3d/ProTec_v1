#include "SensorReadout.h"
#include "globals.h"
#include <Arduino.h>
void readout(){             //method to read out the sensors
  or_LDR = analogRead(A0);
  ir_LDR = analogRead(A1);
  middle_LDR = analogRead(A2);
  il_LDR = analogRead(A3);
  ol_LDR = analogRead(A4);
}

void show_data(){
  while(1){
  Serial.print(analogRead(A4));
  Serial.print("    ");
  Serial.print(analogRead(A3));
  Serial.print("    ");
  Serial.print(analogRead(A2));
  Serial.print("    ");
  Serial.print(analogRead(A1));
  Serial.print("    ");
  Serial.println(analogRead(A0));
  delay(500);
  }
}
