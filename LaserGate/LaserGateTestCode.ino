#define LASER_TIMEOUT 4000 //easily changable incase of calibration
#define LASER_PIN 4

unsigned long laserStart = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(LASER_PIN){
    if(!laserStart){
      laserStart = millis();
    }else if((millis()-laserStart) >= LASER_TIMEOUT){
      //BALL RESERVOIR FULL
    }
  }else{
    laserStart = 0;
  }

}
