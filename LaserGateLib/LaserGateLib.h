#ifndef _LASER_HEADER_H
#define _LASER_HEADER_H

#define LG_TIMEOUT 2000

#define LG_STATE_EMPTY 0
#define LG_STATE_UNDECIDED 1
#define LG_STATE_FULL 2


class LaserGate {
    private:
    uint8_t laserPin;
    unsigned long startTime;
    int8_t state;

    public:
    LaserGate(uint8_t);
    int8_t Update();
    int8_t GetState();
};



#endif
