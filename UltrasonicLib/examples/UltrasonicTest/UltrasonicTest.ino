
#include <UltrasonicLib.h>

//Pin order is Forward Trigger, Forward Echo, Backward Trigger, Backward Echo, Ball detect 1 Trigger, Ball detect 1 Echo, Ball detect 2 Trigger, Ball detect 2 Echo
Ultrasonic US (2,3,4,5,6,7,8,9);

void setup() {
    Serial.begin(115200);
}

void loop() {
	if(US.Update()) {
      Serial.print("Distance For : ");
      Serial.println(US.GetResponse(0));
      Serial.print("Distance Back : ");
      Serial.println(US.GetResponse(1));
      Serial.print("Ball Detect 1: ");
      Serial.println(US.GetResponse(2));
      Serial.print("Ball Detect 2: ");
      Serial.println(US.GetResponse(4));
      Serial.print("Suggestyed rotation");
      switch(US.GetRotation()) {
          case ROTATION_INVALID:
              Serial.println("Distance is not valid");
              break;
          case ROTATION_CORRECT:
              Serial.println("No rotation necessary");
              break;
          case ROTATION_CLOCKWISE:
              Serial.println("Should rotated clockwise");
              break;
          case ROTATION_ANTICLOCKWISE:
              Serial.println("Should rotated anti-clockwise");
              break;
      }
    }
}
