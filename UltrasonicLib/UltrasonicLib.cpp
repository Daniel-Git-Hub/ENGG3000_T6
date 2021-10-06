#include "UltrasonicLib.h"

Ultrasonic::Ultrasonic(uint8_t f1, uint8_t f2, uint8_t b1, uint8_t b2, uint8_t d11, uint8_t d12, uint8_t d21, uint8_t d22) {
    for(uint8_t i = 0; i < 4; i++) {
        distance[i] = 0;
    }
    triggerPin[US_FORWARD] = f1;
    triggerPin[US_BACK] = b1;
    triggerPin[US_BALL_1] = d11;
    triggerPin[US_BALL_2] = d21;
    echoPin[US_FORWARD] = f2;
    echoPin[US_BACK] = b2;
    echoPin[US_BALL_1] = d12;
    echoPin[US_BALL_2] = d22;
    
    StartPulse();
}

void Ultrasonic::StartPulse() {
    for(uint8_t i = 0; i < 4; i++) {
        digitalWrite(triggerPin[i], HIGH);
    }

    delayMicroseconds(10); //I hate having a delay here
    
    for(uint8_t i = 0; i < 4; i++) {
        digitalWrite(triggerPin[i], LOW);
    }
    
    startTime = micros();
    found = 0;
}

int8_t Ultrasonic::PollUS() {
    for(uint8_t i = 0; i < 4; i++) {
        if(!((1 << i) & found) && digitalRead(echoPin[i])){
            found |= 1 << i;
            distance[i] = (micros() - startTime)*10/29/2;
        }
    }
    if((micros() - startTime) > US_TIME_OUT) { //Timeout delay
        for(uint8_t i = 0; i < 4; i++) {
            if(!((1 << i) & found)) {
                distance[i] = 0;
            }
        }
        StartPulse();
        return 1;
    }
    return 0;
}

uint8_t Ultrasonic::GetResponse(uint8_t pos) {
    return distance[pos];
}


int8_t Ultrasonic::GetRotation() {
    if(distance[US_FORWARD] && distance[US_BACK]) {
        int16_t difference = ((int16_t)distance[US_FORWARD]) - distance[US_BACK];
        uint8_t absDif = (difference > 0) ? difference : difference*-1;
        if(absDif < ROTATION_ERROR_MARGIN) {
            return ROTATION_CORRECT;
        }else if(difference < 0) {
            return ROTATION_CLOCKWISE;
        }
        return ROTATION_ANTICLOCKWISE;
    }
    return ROTATION_INVALID; //invalid distances
}

int8_t Ultrasonic::IsBall(){
    if(distance[US_BALL_1] && distance[US_BALL_1] <= BALL_DETECTION_RANGE){
        return BALL_DETECTED;
    }
    if(distance[US_BALL_2] && distance[US_BALL_2] <= BALL_DETECTION_RANGE){
        return BALL_DETECTED;
    }
    return BALL_NOT_DETECTED;
}