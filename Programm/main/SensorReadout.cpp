#include "SensorReadout.h"
#include "globals.h"
#include <Arduino.h>
void readout(){             //method to read out the sensors
  or_LDR = analogRead(A4);
  ir_LDR = analogRead(A3);
  middle_LDR = analogRead(A2);
  il_LDR = analogRead(A1);
  ol_LDR = analogRead(A0);
}
