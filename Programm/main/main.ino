#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"


int or_LDR;     //deklare the variables for the light resistors
int ir_LDR;
int middle_LDR;
int il_LDR;
int ol_LDR;

void setup() {
  // put your setup code here, to run once:
pinMode(40, OUTPUT);
Serial.begin(9600);       //starting a serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  readout();                //command to read out the light resistors
  digitalWrite(40, HIGH);
  straight(150);
  delay(2000);
  turn_right(150, 150);
  digitalWrite(40, LOW);
  delay(2000);
  turn_left(150, 150);
  delay(2000);
  stop_motors();
  delay(10000);
}
