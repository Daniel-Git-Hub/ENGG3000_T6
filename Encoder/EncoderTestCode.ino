#define MOTOR_TS 100 //Time step

int countEncoder1 = 0;

void externalISR(){
  countEncoder1++;
}

void setup() {

  attachInterrupt(digitalPinToInterrupt(2), externalISR, CHANGE); //everytime there is a change to eiter interrupt we increase the count
  attachInterrupt(digitalPinToInterrupt(3), externalISR, CHANGE); 
}

unsigned long encoderNextMillis = 0;

void loop() {
  if((millis()-nextMillis) >= TS){ //every time step we run this code
    //calculate speed from distance (countEncoder) and time (millis()-nextMillis)

    //Input speed into PID controller 

    //Write new desired speed to motor
    
    countEncoder = 0; //we reset the count, if we had more lab time we would create a smoothing factor so that the speed would be less stuttery 
    nextMillis = millis(); //sets the next time for a reading to be current time + delay
  }
}
