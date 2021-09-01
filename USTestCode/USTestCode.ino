
#include "Ultrasonic.h"

void setup() {
    Serial.begin(115200);

    //All params pin placement on the board. The pins will be the triggered pins, for the UNO the echo pins will be shifted right be 8
    //First param is the front of the two sensors for wall detection
    //Second param is the back of the two sensors for wall detection
    //The last two are for the ball detection sensors
    //To note that 
    Ultrasonic(2,3,4,5);
    //Example lists the phyiscal pins
    //Back sensor:    ECHO: 10; TRIGGER: 2
    //Forward sensor: ECHO: 11; TRIGGER: 3
    //Ball detect 1:  ECHO: 12; TRIGGER: 4
    //Ball detect 2:  ECHO: 13; TRIGGER: 5

    
}

void loop() {
	if(pollUS()){
      Serial.print("Distance For : ");
      Serial.println(getResponse(0));
      Serial.print("Distance Back : ");
      Serial.println(getResponse(1));
      Serial.print("Ball Detect 1: ");
      Serial.println(getResponse(2));
      Serial.print("Ball Detect 2: ");
      Serial.println(getResponse(4));
      Serial.print("Suggestyed rotation");
      switch(getRotation()){
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
