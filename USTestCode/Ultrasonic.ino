
#include "Ultrasonic.h"

unsigned long prevTime = 0;
uint8_t distance[4];
char pins[4];

inline void setPin(char pin){
  pinMode(pin+TRIGGER_OFFSET, OUTPUT);
  pinMode(pin+ECHO_OFFSET, INPUT);
}

void Ultrasonic(char f, char b, char b1, char b2){
    for(char i = 0; i < 4; i++){
        distance[i] = 0;
    }
    pins[0] = b1;
    pins[1] = b2;
    pins[2] = f;
    pins[3] = b;

    setPin(f);
    setPin(b);
    setPin(b1);
    setPin(b2);
    
}

uint8_t calcDistance(char pin){
    digitalWrite(pin+TRIGGER_OFFSET, 1);
    delayMicroseconds(10);
    digitalWrite(pin+TRIGGER_OFFSET, 0);
    unsigned long pIn = pulseIn(pin+ECHO_OFFSET, 1, 1000000UL);
    if(pIn > 900000UL){
        return 0;
    }
    return pIn/29/2;
}

char count = 0;
int8_t pollUS(){
  if((millis() - prevTime) > MS_TIME_OUT){ //Timeout delay

    for(char i = 0; i < 4; i++){
        digitalWrite(pins[i]+TRIGGER_OFFSET, 1);
    }
    delayMicroseconds(10);
    for(char i = 0; i < 4; i++){
        digitalWrite(pins[i]+TRIGGER_OFFSET, 0);
    }
    unsigned char count = 0;
    unsigned long start= micros();
    unsigned long dif = 0;
    while(count != 0x0f){
        dif = micros()-start;
        for(char i = 0; i < 4; i++){
            if(!(count & (1<<i)) && digitalRead(pins[i]+ECHO_OFFSET)){
                distance[i] = dif/29/2;
                count |= 1<<i;
            }
        }
        if(dif > 900000UL){
            for(char i = 0; i < 4; i++){
                if(!(count & (1<<i))){
                    distance[i] = 0;
                }
            }
            break;
        }
    }

    // distance[0] = calcDistance(pins[0]);
    // distance[1] = calcDistance(pins[1]);
    // distance[2] = calcDistance(pins[2]);
    // distance[3] = calcDistance(pins[3]);
    prevTime = millis();
  }
}

uint8_t getResponse(uint8_t pin){
    return distance[pin];
}


uint8_t getRotation(){
    if(distance[0] && distance[1]){
        int16_t difference = ((int16_t)distance[0]) - distance[1];
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
