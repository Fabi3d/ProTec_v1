#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>

void straight(int m_Speed);
void stop_motors();
void turn_left(int m_Speed_right, int m_Speed_left);
void turn_right(int m_Speed_right, int m_Speed_left);
void back(int m_Speed);
void ausweichen();

#endif
