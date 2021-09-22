
#include "SpeedEncoder.h"


#include <Encoder.h>

SpeedEncoder::SpeedEncoder(uint8_t pin1, uint8_t pin2){
    encoder = Encoder(pin1, pin2);
    posSum = 0;
    prevSpeed = 0;
    finalSpeed = 0;
}

uint8_t SpeedEncoder::Update(){
    unsigned long timeStep = (millis()-prevRead);
    if(timeStep >= ENCODER_TIMESTEP){
        int32_t pos = encoder.readAndReset();
        float newSpeed = (1.0 * pos)/timeStep;
        finalSpeed = (newSpeed+prevSpeed)/2;

        prevSpeed = newSpeed;
        posSum += pos;
        prevRead = micros();
        return 1;
    }
    return 0;
}

float SpeedEncoder::GetSpeed(){
    return finalSpeed;
}

int32_t SpeedEncoder::GetPos(){
    return posSum;
}