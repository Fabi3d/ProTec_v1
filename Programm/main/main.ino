#include "motors.h"
#include "SensorReadout.h"

int or_LDR;
int ir_LDR;
int middle_LDR;
int il_LDR;
int ol_LDR;
void setup() {
  // put your setup code here, to run once:
pinMode(40, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readout();
  Serial.println(or_LDR);
  digitalWrite(40, HIGH);
  straight(100);
  delay(10000);
  digitalWrite(40, LOW);
  stop_motors();
  delay(10000);
}
