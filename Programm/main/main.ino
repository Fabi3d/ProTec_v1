#include "motors.h"
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  straight(100);
  delay(10000);
  stop_motors();
  delay(10000);
}
