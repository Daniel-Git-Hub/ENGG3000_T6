#ifndef _DEF_ULTRA_HEADER
#define _DEF_ULTRA_HEADER

#include <Arduino.h>

#define STATUS_FLAG 0x01

#define US_TIME_OUT 2000 //about 500cm

#define US_FORWARD 0
#define US_BACK 1
#define US_BALL_1 2
#define US_BALL_2 3

#define ROTATION_INVALID 0
#define ROTATION_CORRECT 1
#define ROTATION_CLOCKWISE 2
#define ROTATION_ANTICLOCKWISE 3
#define ROTATION_ERROR_MARGIN 10

#define BALL_DETECTION_RANGE 10
#define BALL_NOT_DETECTED 0
#define BALL_DETECTED 1

class Ultrasonic {
    private:
        unsigned long startTime;
        uint8_t triggerPin[4];
        uint8_t echoPin[4];
        uint8_t found;
        unsigned long distance[4];

    public:
        Ultrasonic(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);
        int8_t PollUS();
        uint8_t GetResponse(uint8_t);
        int8_t GetRotation();
        void StartPulse();
        int8_t IsBall();
};

#endif
