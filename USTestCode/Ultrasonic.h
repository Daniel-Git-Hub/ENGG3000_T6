#define STATUS_FLAG 0x01


#define MS_TIME_OUT 10

#define TRIGGER_OFFSET 0
#define ECHO_OFFSET 8


#define ROTATION_INVALID 0
#define ROTATION_CORRECT 1
#define ROTATION_CLOCKWISE 2
#define ROTATION_ANTICLOCKWISE 3
#define ROTATION_ERROR_MARGIN 10


void Ultrasonic(char, char, char, char);
int8_t pollUS();
uint8_t getResponse(uint8_t);
uint8_t getRotation();
