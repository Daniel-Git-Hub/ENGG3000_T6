#ifndef _DEF_ULTRA_HEADER
#define _DEF_ULTRA_HEADER

#define STATUS_FLAG 0x01


#define US_TIME_OUT 2000 //about 500cm

#define TRIGGER_OFFSET 0
#define ECHO_OFFSET 8

#define TRIGGER_PIN _SFR_IO8(0x18) //PORTB
#define TRIGGER_DDR _SFR_IO8(0x04) //DDRB

#define ECHO_PORT _SFR_IO8(0x10) //PIND
#define ECHO_DDR _SFR_IO8(0x11) //DDRD

#define ROTATION_INVALID 0
#define ROTATION_CORRECT 1
#define ROTATION_CLOCKWISE 2
#define ROTATION_ANTICLOCKWISE 3
#define ROTATION_ERROR_MARGIN 10

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
        uint8_t GetRotation();
        void StartPulse();
};

#endif
