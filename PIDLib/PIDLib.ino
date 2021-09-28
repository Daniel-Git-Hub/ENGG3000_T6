#include "PID.h"
#include <Servo.h>


PID::PID(uint8_t mPin, uint8_t e1, uint8_t e2){
    speedEncoder = SpeedEncoder(e1,e2);
    motorPin = mPin;
    motor.attach(motorPin);
}

void PID::SetGains(float p, float i, float d){
    kP = p;
    kI = i;
    kD = d;
}

int8_t PID::Update(){
    uint16_t ts = speedEncoder.Update(); //where ts is the time stamp
    if(isForceOff){
        motor.writeMicroseconds(MOTOR_OFF);  
        return -1;
    }
    if(ts){
        float error = setPoint - speedEncoder.GetSpeed();
        cumError += kI * error * ts;
        float der = (kD*(error - lastError))/ts;

        outputSpeed = kP*error + cumError + der;
        mappedOutputSpeed = map(outputSpeed, ENCODER_MIN, ENCODER_MAX, MOTOR_MIN, MOTOR_MAX);

        motor.writeMicroseconds(mappedOutputSpeed);  

        lastError = error;

        return 1;
    }
    return 0;
}

int16_t PID::GetSpeed(){
    return outputSpeed;
}

int16_t PID::GetError(){
    return abs(outputSpeed - speedEncoder.GetSpeed());
}

int32_t PID::GetPos(){ //I doubt this function will ever be used
    return speedEncoder.GetPos();
}

void PID::ForceOff(){
    isForceOff = 1;
    motor.writeMicroseconds(MOTOR_OFFSET);  
}

int8_t PID::ResetForceOff(){
    if(isNotForceOff){
        isNotForceOff = 0;
        return 1;
    }
    return 0;
}