#ifndef _DEF_ULTRA_HEADER
#define _DEF_ULTRA_HEADER

#include <Arduino.h>

#define STATUS_FLAG 0x01


#define US_TIME_OUT 2000 //about 500cm

#define TRIGGER_OFFSET 0
#define ECHO_OFFSET 8

#define TRIGGER_PIN _SFR_IO8(0x18) //PORTB
#define TRIGGER_DDR _SFR_IO8(0x04) //DDRB

#define ECHO_PORT _SFR_IO8(0x10) //PIND
#define ECHO_DDR _SFR_IO8(0x11) //DDRD

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
        uint8_t pins[4];
        uint8_t pinMask;
        uint8_t found;
        unsigned long distance[4];

    public:
        Ultrasonic(uint8_t,uint8_t,uint8_t,uint8_t);
        int8_t PollUS();
        uint8_t GetResponse(uint8_t);
        int8_t GetRotation();
        void StartPulse();
        int8_t IsBall();
};

#endif
