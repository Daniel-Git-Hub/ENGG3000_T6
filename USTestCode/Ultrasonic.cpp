
#include "Ultrasonic.h"
#include <avr/io>

ISR(PCINT0_vect){
    statusUS |= STATUS_FLAG;
};


void Ultrasonic(char f, char b, uint8_t d){
    for(char i = 0; i < 8; i++){
        distance[i] = 0;
    }
    ballDetect = b;
    wallForward = f;
    wallBehind = b;

    DDRB = 0x00;
    PCICR = 0x01;
    
    //we do this mask a lot so it is handy to save it as a mask;
    readingPins = (pins | (1 << wallForward) | (1 << wallBehind)) & US_POSSIBLE;
    PCMSK0 = readingPins;
    
    DDRD = pins << TRIGGER_OFFSET;
    PORTD = 0xff; //enable all pullups;
    startRead();
}

int8_t pollUS(){
    unsigned long differenceTime = micros() - startTime;

    if(statusUS & STATUS_FLAG){
        uint8_t difference = hasRead & PORTB;
        for(char i = 0; i < 8; i++){
            if(difference & (1<<i)){
                distance[i] = differenceTime*SPEED_SOUND;
            }
        }
        hasRead ^= difference;
        statusUS ^= STATUS_FLAG;
        lastPinValue = PORTB;
    }

    if(differenceTime >= US_TIME_OUT){ //Timeout delay
        for(char i = 0; i < 8; i++){
            if(hasRead & (1<<i)){
                distance[i] = 0;
            }
        }
        startRead();
        return 1;
    }
    return 0;
}


int8_t startRead(){
    hasRead = readingPins;
    PORTD |= readingPins << TRIGGER_OFFSET;
    delayMicroseconds(10);
    PORTD ^= readingPins << TRIGGER_OFFSET;
    lastPinValue = PORTB;
    return 0;
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