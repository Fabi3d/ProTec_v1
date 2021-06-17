#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"

#include <Adafruit_NeoPixel.h>

#define PIN 44
Adafruit_NeoPixel pixels(6, PIN, NEO_GRB + NEO_KHZ800);

int or_LDR;     //deklare the variables for the light resistors
int ir_LDR;
int middle_LDR;
int il_LDR;
int ol_LDR;

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
Serial.begin(9600);
for(int i = 0; i < 6; i++)
  pixels.setPixelColor(i, pixels.Color(0, 0, 250));
  pixels.show();
pinMode(40, OUTPUT);
Serial.begin(9600);       //starting a serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  readout();                //command to read out the light resistors
  if(or_LDR < 750 || ir_LDR < 750){
    turn_right(150, 150);
    delay(2);
  }
  if(ol_LDR < 750 || il_LDR < 750){
    turn_left(150, 150);
    delay(2);
  }
  if(middle_LDR < 750){
    straight(150);
    delay(2);
  }
  
}
