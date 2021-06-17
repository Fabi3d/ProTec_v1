#include "line.h"
#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"

int or_treshold = 750;
int ir_treshold = 750;
int m_treshold = 750;
int il_treshold = 750;
int ol_treshold = 750;

void follow_line(){
  readout();
  if((ol_LDR > ol_treshold && il_LDR > il_treshold && middle_LDR < m_treshold && ir_LDR > ir_LDR && or_LDR > or_treshold) || (ol_LDR > ol_treshold && il_LDR < il_treshold && middle_LDR < m_treshold && ir_LDR < ir_LDR && or_LDR > or_treshold)){
    straight(v1);
  }
}
