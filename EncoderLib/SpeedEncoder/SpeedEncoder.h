#ifndef _SPEED_HEADER_H
#define _SPEED_HEADER_H

//from https://github.com/PaulStoffregen/Encoder
#define ENCODER_USE_INTERRUPTS //these are compiler settings for encoder library
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

//this number needs calibration
#define ENCODER_TIMESTEP 10


//This class effectively extends the default encoder class to return speed instead of position
class SpeedEncoder {
    private:
    Encoder encoder;
    
    //Speed is in encoder pulses per millisecond
    float prevSpeed;
    float finalSpeed;

    //timestamp (millis)
    unsigned long prevRead;

    int32_t posSum;

    public:
    SpeedEncoder(uint8_t, uint8_t);
    uint16_t Update();
    float GetSpeed();
    int32_t GetPos();
}


#endif