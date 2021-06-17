#include "motors.h"
#include "SensorReadout.h"
#include "globals.h"
#include "line.h"

#include <Adafruit_NeoPixel.h>

#define PIN 44
Adafruit_NeoPixel pixels(6, PIN, NEO_GRB + NEO_KHZ800);

int or_LDR;     //deklare the variables for the light resistors  
int ir_LDR;
int middle_LDR;
int il_LDR;
int ol_LDR;




void setup() {
  // put your setup code he re, to run once:
  pixels.begin();
Serial.begin(9600);
for(int i = 0; i < 6; i++)   
  pixels.setPixelColor(i, pixels.Color(0, 0, 250));
  pixels.show();
pinMode(40, OUTPUT);
Serial.begin(9600);    //starting a serial communication


}

void loop() {
  // put your main code here, to run repeatedly:
  //show_data();
  follow_line();
}
