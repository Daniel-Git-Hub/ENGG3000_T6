
#include "../LaserGateLib/LaserGateLib.h"

LaserGate lg(5);

void setup(){
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(lg.Update() == LG_STATE_FULL){
    Serial.println("Ball collection full");
  }

}
