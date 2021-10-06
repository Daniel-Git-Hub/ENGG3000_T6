# PID library

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

Should be called once in setup using the values motions gives, which they will find expermentially


**Parameters**

pGain: float, proportionally gain
iGain: float, intergral gain
dGain: float, derivative gain

**Returns**

void



### Update
```cpp
int8_t update varName.Update();
```


**Notes**

MUST BE CALLED EVERY LOOP


**Parameters**

void


**Returns**

Return type: int8_t

| value | meaning |
| --- | --- |
| 0 | No new speed has been computed, as a result the motor's speed was not changed |
| 1 | A new speed from the encoder has been found and the motor's speed has been updated per the PID controller |
| -1 | Motor has been forced off, as a result it has not changed the motors speed |



### SetSpeed
```cpp
uint16_t realSpeed = varName.SetSpeed(newSpeed);
```





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
