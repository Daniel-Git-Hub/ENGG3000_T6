#include "Ultrasonic.h"

unsigned long prevTime = 0;
uint8_t distance[4];
char pins[4];


Ultrasonic::Ultrasonic(uint8_t f, uint8_t b, uint8_t b1, uint8_t b2){
    for(uint8_t i = 0; i < 4; i++){
        distance[i] = 0;
    }
    pins[0] = f;
    pins[1] = b;
    pins[2] = b1;
    pins[3] = b2;
    pinMask = (1 << f) | (1 << b) | (1 << b1) | (1 << b2); 
    
    TRIGGER_DDR |= pinMask; //make sure trigger pins are output
    ECHO_DDR &= ~pinMask;   //make sure echo pins are input

    StartPulse()
}

void Ultrasonic::StartPulse(){
        TRIGGER_PIN |= pinMask;
        delayMicroseconds(10);
        TRIGGER_PIN &= ~pinMask;

        startTime = micros();
        found = 0;
}

int8_t Ultrasonic::PollUS(){
    if((micros() - startTime) > US_TIME_OUT){ //Timeout delay
        for(uint8_t i = 0; i < 4; i++){
            if(!((1 << pins[i]) & found)){
                distance[i] = 0;
            }
        }
        StartPulse();
    }
    for(uint8_t i = 0; i < 4; i++){
        if(!((1 << pins[i]) & found) && ((1 << pins[i]) & ECHO_PORT)){
            found |= 1 << pins[i];
            distance[i] = (micros() - startTime)*10/29/2;
        }
    }
}

uint8_t Ultrasonic::GetResponse(uint8_t pos){
    return distance[pos];
}


uint8_t Ultrasonic::GetRotation(){
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
