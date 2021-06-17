#include "motors.h"
//here are all methods for the motors to drive
#define M1FWD  29
#define M1BWD 30
#define M2FWD 27
#define M2BWD 28
#define EN_M1 9
#define EN_M2 8

int v1 = 143;
int v2 = 110;
void straight(int m_Speed)
{
  digitalWrite(M1FWD, HIGH);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, HIGH);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, m_Speed+20);
  analogWrite(EN_M2, m_Speed);
  delay(1);
}

void stop_motors(){
  digitalWrite(M1FWD, LOW);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, LOW);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, 0);
  analogWrite(EN_M2, 0);
  delay(1);
}

void turn_left(int m_Speed_right, int m_Speed_left){
  digitalWrite(M1FWD, HIGH);
  digitalWrite(M1BWD, LOW);
  digitalWrite(M2FWD, LOW);
  digitalWrite(M2BWD, HIGH);
  analogWrite(EN_M1, m_Speed_right);
  analogWrite(EN_M2, m_Speed_left);
  delay(1);
}

void turn_right(int m_Speed_right, int m_Speed_left){
  digitalWrite(M1FWD, LOW);
  digitalWrite(M1BWD, HIGH);
  digitalWrite(M2FWD, HIGH);
  digitalWrite(M2BWD, LOW);
  analogWrite(EN_M1, m_Speed_right);
  analogWrite(EN_M2, m_Speed_left);
  delay(1);
}
