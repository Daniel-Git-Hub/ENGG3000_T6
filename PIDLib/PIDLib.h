#ifndef _PID_HEADER_H
#define _PID_HEADER_H

#include <Arduino.h>
#include <SpeedEncoderLib.h>
#include <Servo.h>

#define MOTOR_OFF 1500 //safely in the dead zone

#define MOTOR_MIN 1000
#define MOTOR_MAX 2000

#define ENCODER_MIN -100 //this 'should' be the negative to ENCODER_MAX
#define ENCODER_MAX 100 //in encoder pulses per millis

#define INPUT_MIN -32768
#define INPUT_MAX 32768


class PID {
    private:

    //PID gains
    float kP;
    float kD;
    float kI;

    uint8_t motorPin;
    
    SpeedEncoder *speedEncoder;

    float cumError = 0; //where the intergral is the cumerlative error
    float lastError = 0; //this is used to calculate the instantnous derivative 

    Servo motor;

    int16_t outputSpeed = 0;
    int16_t mappedOutputSpeed = 0;

    int8_t isForceOff = 0;
    

    public:
    //Desired Speed
    int16_t setPoint;

    PID(uint8_t,uint8_t,uint8_t);
    
    int8_t Update();
    void SetGains(float,float,float); 
    int16_t GetSpeed();
    int16_t GetError();
    int32_t GetPos();
    void ForceOff();
    int8_t ResetForceOff();
    int16_t SetSpeed(int16_t);
};



#endif
