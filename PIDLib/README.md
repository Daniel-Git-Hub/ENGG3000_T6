# PID library

## Note

This library extends the SpeedEncoder class and allows for it's output to be feed into a PID closed loop controller

## Endpoints

### Instantiate
```cpp
PID varName(motorPin, encoderPin1, encoderPin2);
```


**Parameters**

motorPin: uint8_t, The pin this motor is connected to, This must be a PWM enabled pin

encoderPin1: uint8_t, the pin the encoder channel 1 is connected to, this must be a hardware interrupt pin, see [valid pins](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

encoderPin2: uint8_t, ditto from encoderPin1


### SetGains
```cpp
varName.SetGains(pGain,iGain,dGain);
```


**Notes**

Should be called once in setup using the values motion team gives, which they will find expermentially


**Parameters**

pGain: float, proportionally gain

iGain: float, intergral gain

dGain: float, derivative gain

**Returns**

void



### Update
```cpp
int8_t update = varName.Update();
```


**Notes**

MUST BE CALLED EVERY LOOP


**Parameters**

void


**Returns**

*Return a int8_t datatype*

| value | meaning |
| --- | --- |
| 0 | No new speed has been computed, as a result the motor's speed was not changed |
| 1 | A new speed from the encoder has been found and the motor's speed has been updated per the PID controller |
| -1 | Motor has been forced off, as a result it has not changed the motors speed |



### SetSpeed
```cpp
uint16_t realSpeed = varName.SetSpeed(newSpeed);
```


**Parameters**

newSpeed: int16_t, uses the full range 

Example

| value | result |
| --- | --- |
| −32,768 | Full speed reverse |
| -16,384 | Half speed reverse |
| 0 | Motor stopped |
| 16384 | Half speed forward |
| 32,767 | Full. speed forward |

Obviously any number in the range −32,768 to 32,767 can be used

**Returns**

*Return a int16_t datatype*

This is the mapped speed of parameter mapped to encoder pulses per millisecond (an arbitary unit)
This is propably useless to any user


### ForceOff
```cpp
varName.ForceOff();
```


**Notes**

The emergancy off for the motor, this will make this class NOT be able to turn back on the motor until ResetForceOff is called


**Parameters**

void


**Returns**

void



### ResetForceOff
```cpp
int8_t result = varName.ResetForceOff();
```

**Notes**

Allows the motor to be controlled again, used after emergancy off is called

**Parameters**

void


**Returns**

*Return a int8_t datatype*

| value | meaning |
| --- | --- | 
| 0 | The motor was not in a force off state, so no change occured |
| 1 | The motor was in the force off state and has now been removed from it |


### The following are most likely not going to be ever used, but they expose internal variables and might be useful for debugging

### GetSpeed
```cpp
uint16_t speed = varName.GetSpeed();
```



### GetError
```cpp
uint16_t error = varName.GetError();
```



### GetPos
```cpp
uint32_t pos = varName.GetPos();
```
