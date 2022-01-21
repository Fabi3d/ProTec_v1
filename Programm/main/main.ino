#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"
#include "line.h"
#include <Servo.h>
#include <Pixy2.h>
#include <Adafruit_NeoPixel.h>

#define PIN 44
Adafruit_NeoPixel pixels(6, PIN, NEO_GRB + NEO_KHZ800);
Pixy2 pixy;

int or_LDR;     //declare the variables for the light resistors
int ir_LDR;
int middle_LDR;
int il_LDR;
int ol_LDR;
int gyro;

int trigger=48;
int echo=49;

int distance=0;
long duration=0;

float ir_val_right=0;
float ir_val_left=0;

long counter;

Servo pixyServo;

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixyServo.attach(7);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  for (int i = 0; i < 6; i++)
    pixels.setPixelColor(i, pixels.Color(0, 50, 250));
  
  pixels.show();
  pinMode(40, OUTPUT);
  Serial.begin(9600);    //starting a serial communication
  pixy.init();
  // using the color connected components program
  pixy.changeProg("color_connected_components");
  pixy.setLamp(1, 1);         //activate the led´s
  delay(10);
  pixyServo.write(97);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  ir_readout();
 // show_data();
  follow_line();
  green();
}

void green() {
  static int i = 0;
  int j;
  char buf[64];
  int32_t panOffset, tiltOffset;
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks)
  {
    pixy.ccc.getBlocks();
    panOffset = (int32_t)pixy.frameWidth / 2 - (int32_t)pixy.ccc.blocks[0].m_x;
    tiltOffset = (int32_t)pixy.ccc.blocks[0].m_y - (int32_t)pixy.frameHeight / 2;
    pixy.ccc.getBlocks();
    int panOffset2 = (int32_t)pixy.frameWidth / 2 - (int32_t)pixy.ccc.blocks[1].m_x;
    int tiltOffset2 = (int32_t)pixy.ccc.blocks[1].m_y - (int32_t)pixy.frameHeight / 2;
 
    Serial.print(panOffset);
    Serial.print("       ");
    Serial.println(tiltOffset);
    if (panOffset < 0 && tiltOffset > 30)
    {
      Serial.println("right");
      straight(v1);
      delay(10);
      back(v1);
      delay(100);
      stop_motors();
      delay(200);
      readout();

      if (or_LDR < or_treshold && ir_LDR < ir_treshold) {
        straight(v1);
        delay(600);
        readout();
        goto greenend;
      }
      if (pixy.ccc.numBlocks == 2) {
        if (tiltOffset > 0 && tiltOffset2 > 0)
        {
          goto deadend;
        }
      }
      straight(v1);
      delay(400);
      turn_right(v1 + 10, v1 + 10);
      delay(550);
      readout();
      while (middle_LDR > m_treshold && il_LDR > il_treshold && ol_LDR > ol_treshold) {
        readout();
        turn_right(v1 + 10, v1 + 10);
      }
      straight(v1);
      delay(70);
    }
    else if (panOffset > 0 && tiltOffset > 30)
    {
      Serial.println("left");
      straight(v1);
      delay(10);
      back(v1);
      delay(100);
      stop_motors();
      delay(200);
      readout();
      if (ol_LDR < ol_treshold && il_LDR < il_treshold) {
        straight(v1);
        delay(600);
        readout();
        goto greenend;
      }
      if (pixy.ccc.numBlocks == 2) {
        if (tiltOffset > 0 && tiltOffset2 > 0)
        {
          goto deadend;
        }
      }
      straight(v1);
      delay(400);
      turn_left(v1 + 20, v1 + 10);
      delay(550);
      readout();
      while (middle_LDR > m_treshold && ir_LDR > ir_treshold && or_LDR > or_treshold) {
        readout();
        turn_left(v1, v1 + 35);
      }
      straight(v1);
      delay(70);
    }
 deadend:
    if (pixy.ccc.numBlocks == 2)
    {
      // if ((tiltOffset > 0 && tiltOffset2 > 0) && (panOffset > 5 && panOffset2 > 5))
      //{
      digitalWrite(led, HIGH);
      // pixyServo.write(0);
      straight(v1);
      delay(200);
      readout();
      if (or_LDR < or_treshold && ol_LDR < ol_treshold)
      {
        straight(v1);
        delay(600);
        return;
      }
      turn_right(v1 + 100, v1 + 100);
      delay(800);
      readout();
      while (middle_LDR > m_treshold)
      {
        turn_right(v1 + 100, v1 + 100);
        readout();
        digitalWrite(led, LOW);
      }
      //  pixyServo.write(85);
      // }
      //else
      // {
      //return;
      // }
    }
  }
greenend:
  digitalWrite(led, LOW);
  delay(1);
}
