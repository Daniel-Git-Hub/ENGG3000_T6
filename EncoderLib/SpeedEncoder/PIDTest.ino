#include "PID.h"

//first argument is motor pin
//next two are the encoder pins
PID pid(9,2,3); //instantiate class

void setup(){
    Serial.begin(115200);
    pid.SetGains(1,1,1); //in the order of, P I D
    pid.setPoint = 500; //in encoder ticks per millis
}

void loop(){
    int8_t result = pid.Update();
    if(result == -1){
        Serial.println("Has been forced off");
    }else if(result == 1){
        Serial.println("Error " + pid.GetError());
    }

    if(millis() >= 15000){ //example shutoff
        pid.ForceOff();
    }

}