# Laser Gate

## Endpoints

### Instantiate
```cpp
LaserGate varName(pinNumber);
```
**Notes**
varName is the variables name (arbitary)

**Params**
Pin number: This is the pin that the laser gate sensor is attached to

### Update
```cpp
varName.Update();
```
**Notes**
MUST be called every loop

**Returns**
*Returns a int8_t (signed 8 bit number)*

LG_STATE_EMPTY: if the sensor is unbroken

LG_STATE_UNDECIDED: if the sensor is broken but hasn't been broken long enough to detect as full

LG_STATE_FULL: if the sensor is broken and has been for timeout amount of time

### GetState
```cpp
varName.GetState()
```

**Returns**
Will return the last result from update

### SetTimeout
```cpp
varName.SetTimeout(length);
```

**Notes**
This will set how long the sensor needs to be broken before the reservoir will detect as full.

Does not need to be called, the timeout will default to 2000 milliseconds

**Params**
length: unsigned long, this is the time in milliseconds

##Example
*This code can be seen in examples folder*
```cpp
#include <LaserGateLib.h>

LaserGate lg(5); //defines the varName as 'lg' and to use pin 5

void setup() {
  Serial.begin(115200);
  lg.SetTimeout(4000); //sets the timeout to be 4 seconds
}

void loop() {
  switch (lg.Update()) {
    case LG_STATE_EMPTY:
      Serial.println("Ball collection empty");
      break;
    case LG_STATE_UNDECIDED:
      Serial.println("Ball collection undecided");
      break;
    case LG_STATE_FULL:
      Serial.println("Ball collection full");
      break;
  }

}
```