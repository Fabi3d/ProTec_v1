#include "SensorReadout.h"
#include "globals.h"
#include <Arduino.h>
void readout() {            //method to read out the sensors
  or_LDR = analogRead(A0);
  ir_LDR = analogRead(A1);
  middle_LDR = analogRead(A2);
  il_LDR = analogRead(A3);
  ol_LDR = analogRead(A4);
  gyro = digitalRead(47);
}

void show_data() {
  while (1) {
    Serial.print(analogRead(A4));
    Serial.print("    ");
    Serial.print(analogRead(A3));
    Serial.print("    ");
    Serial.print(analogRead(A2));
    Serial.print("    ");
    Serial.print(analogRead(A1));
    Serial.print("    ");
    Serial.print(analogRead(A0));
    Serial.print("    ");
    Serial.print(digitalRead(47));
    Serial.println("    ");
    
  }
}

void ultrasonic_readout(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  //Serial.print(duration);
  //Serial.print("      distance 1: ");
  distance = ((duration*pow(10, -6)/2)*343.2)*pow(10, 2);
 // Serial.println(distance);
    
}

void ir_readout(){
  ir_val_left=analogRead(A7);
  ir_val_right=analogRead(A8);
}
