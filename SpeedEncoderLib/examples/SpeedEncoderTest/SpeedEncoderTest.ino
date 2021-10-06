#include <SpeedEncoderLib.h>

SpeedEncoder motor1(2,3); //instantiate class

void setup() {
    Serial.begin(115200);
}

void loop() {
    if(motor1.Update()) { //will return true everytime the desired timestep has passed
        Serial.println(motor1.GetSpeed()); //print speed
    }

}
