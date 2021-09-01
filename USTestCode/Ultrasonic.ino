
#include "Ultrasonic.h"

unsigned long prevTime = 0;
uint8_t distance[4];
char wallForward;
char wallBehind;
char ballDetect1;
char ballDetect2;

inline void setPin(char pin){
  pinMode(pin+TRIGGER_OFFSET, OUTPUT);
  pinMode(pin+ECHO_OFFSET, INPUT);
}

void Ultrasonic(char f, char b, char b1, char b2){
    for(char i = 0; i < 8; i++){
        distance[i] = 0;
    }
    ballDetect1 = b1;
    ballDetect2 = b2;
    wallForward = f;
    wallBehind = b;

    setPin(f);
    setPin(b);
    setPin(b1);
    setPin(b2);
    
}

uint8_t calcDistance(char pin){
    digitalWrite(pin+TRIGGER_OFFSET, 1);
    delayMicroseconds(10);
    digitalWrite(pin+TRIGGER_OFFSET, 0);
    return pulseIn(pin+ECHO_OFFSET, 1)/29/2;
}

int8_t pollUS(){
  if((millis() - prevTime) > MS_TIME_OUT){ //Timeout delay
    distance[0] = calcDistance(wallForward);
    distance[1] = calcDistance(wallBehind);
    distance[2] = calcDistance(ballDetect1);
    distance[3] = calcDistance(ballDetect2);
    prevTime = millis();
  }
}

uint8_t getResponse(uint8_t pin){
    return distance[pin];
}


uint8_t getRotation(){
    if(distance[wallForward] && distance[wallBehind]){
        int16_t difference = ((int16_t)distance[wallForward]) - distance[wallBehind];
        uint8_t absDif = (difference > 0) ? difference : difference*-1;
        if(absDif < ROTATION_ERROR_MARGIN){
            return ROTATION_CORRECT;
        }else if(difference < 0){
            return ROTATION_CLOCKWISE;
        }
        return ROTATION_ANTICLOCKWISE;
    }
    return ROTATION_INVALID; //invalid distances
}
