#include <PIDLib.h>

PID motorLeft(9,2,3);
PID motorRight(10,4,5);

void setup() {

  motorLeft.SetGains(1.0, 9.1, 10.9);
  motorRight.SetGains(1.0, 9.1, 10.9);
  
}

unsigned long lastTime = 0;

int16_t currentSpeed = 32767; //start at max speed


void loop() {

  motorLeft.Update(); //call this every loop
  motorRight.Update();

  if((millis()-lastTime) >= 4000){ //every 4 seconds
    currentSpeed = currentSpeed/2; //half the speed
    motorLeft.SetSpeed(currentSpeed);
    motorRight.SetSpeed(currentSpeed*-1);
    lastTime = millis();
  }

}
