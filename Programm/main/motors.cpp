#include "motors.h"
#define M1FWD  30
#define M1BWD 29
#define M2FWD 27
#define M2BWD 28
#define EN_M1 9
#define EN_M2 8
void straight(int m_Speed)
{
  digitalWrite(M1FWD, HIGH);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, HIGH);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, m_Speed);
  analogWrite(EN_M2, m_Speed);
}

void stop_motors(){
  digitalWrite(M1FWD, LOW);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, LOW);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, 0);
  analogWrite(EN_M2, 0);
}

void turn_left(int m_Speed_right, int m_Speed_left){
  digitalWrite(M1FWD, HIGH);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, LOW);
  digitalWrite(M2BWD, HIGH);
  analogWrite(EN_M1, m_Speed_right);
  analogWrite(EN_M2, m_Speed_left);
}

void turn_right(int m_Speed_right, int m_Speed_left){
  digitalWrite(M1FWD, LOW);
  digitalWrite(M1BWD, HIGH);
  digitalWrite(M2FWD, HIGH);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, m_Speed_right);
  analogWrite(EN_M2, m_Speed_left);
}
