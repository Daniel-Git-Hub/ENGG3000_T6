
#include "BallCollectLib.h"

BallCollect::BallCollect(uint8_t cPin, uint8_t dPin){
    collectPin = cPin;
    disposePin = dPin;
    pinMode(collectPin, OUTPUT);
    pinMode(disposePin, OUTPUT); 
    digitalWrite(disposePin, HIGH); //the solonoid is closed when this is high
}

int8_t BallCollect::Update(){
    if(timeoutCollect && (millis() - startTimeCollect) >= timeoutCollect){
        timeoutCollect = 0;
        digitalWrite(collectPin, LOW);
    }
    if(timeoutDispose && (millis() - startTimeDispose) >= timeoutDispose){
        timeoutDispose = 0;
        digitalWrite(collectPin, HIGH);
    }
    return 0;
}

int8_t BallCollect::StartCollect(unsigned long to = BC_DEFAULT_TIMEOUT){
    timeoutCollect = to;
    startTimeCollect = millis();
    digitalWrite(collectPin, HIGH);
    return 0;

}

int8_t BallCollect::StartDispose(unsigned long to = BC_DEFAULT_TIMEOUT){
    timeoutDispose = to;
    startTimeDispose = millis();
    digitalWrite(disposePin, LOW);
    return 0;
}

int8_t BallCollect::StopCollect(){
    timeoutCollect = 0;
    digitalWrite(collectPin, LOW);
    return 0;
}

int8_t BallCollect::StopDispose(){
    timeoutDispose = 0;
    digitalWrite(disposePin, HIGH);
    return 0;
}