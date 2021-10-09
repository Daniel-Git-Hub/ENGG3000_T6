#ifndef _BC_HEADER_H
#define _BC_HEADER_H

#include <Arduino.h>

#define BC_DEFAULT_TIMEOUT 2000


class BallCollect {
    private:
    uint8_t collectPin;
    uint8_t disposePin;
    unsigned long startTimeCollect;
    unsigned long startTimeDispose;
    unsigned long timeoutCollect;
    unsigned long timeoutDispose;
    
    public:
    BallCollect(uint8_t, uint8_t);
    
    int8_t Update();

    int8_t StartCollect(unsigned long = BC_DEFAULT_TIMEOUT);
    int8_t StopCollect();

    int8_t StartDispose(unsigned long = BC_DEFAULT_TIMEOUT);
    int8_t StopDispose();
};

#endif