
#include <UltrasonicLib.h>

//All params pin placement on the board. 
//Currently using port B for trigger and port D for echo
Ultrasonic US (2,3,4,5);
//Example lists the phyiscal pins
//Forward sensor:    ECHO: PD2; TRIGGER: PB2
//Back sensor:       ECHO: PD3; TRIGGER: PB3
//Ball detect 1:     ECHO: PD4; TRIGGER: PB4
//Ball detect 2:     ECHO: PD5; TRIGGER: PB5

void setup() {
    Serial.begin(115200);
}

void loop() {
	if(US.PollUS()){
      Serial.print("Distance For : ");
      Serial.println(US.GetResponse(0));
      Serial.print("Distance Back : ");
      Serial.println(US.GetResponse(1));
      Serial.print("Ball Detect 1: ");
      Serial.println(US.GetResponse(2));
      Serial.print("Ball Detect 2: ");
      Serial.println(US.GetResponse(4));
      Serial.print("Suggestyed rotation");
      switch(US.GetRotation()){
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
