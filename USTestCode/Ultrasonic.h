#define STATUS_FLAG 0x01

#define SPEED_SOUND 343/2000

#define US_TIME_OUT 1000

#define US_POSSIBLE 0x3F
#define TRIGGER_OFFSET 2

#define ROTATION_INVALID 0
#define ROTATION_CORRECT 1
#define ROTATION_CLOCKWISE 2
#define ROTATION_ANTICLOCKWISE 3
#define ROTATION_ERROR_MARGIN 10

uint8_t distance[8];
uint8_t readingPins;
uint8_t hasRead;
uint8_t statusUS;
unsigned long startTime;
char wallForward;
char wallBehind;
uint8_t ballDetect;

void Ultrasonic(char, char, uint8_t);
int8_t pollUS();
int8_t startRead(uint8_t);
uint8_t getResponse(uint8_t);
int8_t getRotation();

