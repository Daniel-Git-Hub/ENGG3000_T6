
#include "Ultrasonic.h"

unsigned long lastPrint = 0;

void setup() {
    Serial.begin(115200);

    //All params are the pins for echo pins (inputs) the trigger pins are shifted right by two (to avoid touching RX and TX)
    //First param is the front of the two sensors for wall detection
    //Second param is the back of the two sensors for wall detection
    //The last is the bitmask for the sensor incharge of ball detection
    //To note that 
    Ultrasonic(0, 1, 0b00010100);
    //Example (the lone number is the physical pin on the Uno)
    //Back sensor:    ECHO: PB0, 8; TRIGGER: PD2, 2
    //Forward sensor: ECHO: PB1, 9; TRIGGER: PD3, 3
    //Ball detect 1:  ECHO: PB2, 10; TRIGGER: PD4, 4
    //Ball detect 2:  ECHO: PB4, 12; TRIGGER: PD6, 6
    //Good reference: https://upload.wikimedia.org/wikipedia/commons/c/c9/Pinout_of_ARDUINO_Board_and_ATMega328PU.svg
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
