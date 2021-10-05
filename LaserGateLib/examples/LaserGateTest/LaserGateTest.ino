#include <LaserGateLib.h>

LaserGate lg(5); //defines the varName as 'lg' and to use pin 5

void setup() {
  Serial.begin(115200);
  lg.SetTimeout(4000); //sets the timeout to be 4 seconds
}

void loop() {
  switch (lg.Update()) {
    case LG_STATE_EMPTY:
      Serial.println("Ball collection empty");
      break;
    case LG_STATE_UNDECIDED:
      Serial.println("Ball collection undecided");
      break;
    case LG_STATE_FULL:
      Serial.println("Ball collection full");
      break;
  }

}