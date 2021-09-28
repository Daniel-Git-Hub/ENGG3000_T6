
#include "LaserGateLib.h"

LaserGate::LaserGate(uint8_t pin){
    laserPin = pin;
    startTime = 0;
    pinMode(pin, INPUT);
}

int8_t LaserGate::Update(){
  if(digitalRead(laserPin)){
    if(!startTime){
      startTime = millis();
      state = LG_STATE_UNDECIDED;
    }else if((millis()-startTime) >= LG_TIMEOUT){
      state = LG_STATE_FULL;
    }
  }else{
    startTime = 0;
    state = LG_STATE_EMPTY;
  }
  return state;
}

int8_t LaserGate::GetState(){
    return state;
}
