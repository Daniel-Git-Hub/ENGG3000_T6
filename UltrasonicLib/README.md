# Ultrasonic Library

## Notes

Highly customised for our usage in for our robot

It will constantly, in async, poll the ultrasonic sensors every X\* microseconds

Returned values are in millimeters were applicable

*\*This is a defined constant in UltrasonicLib.h, currently 2000*

## Endpoints

### Instantiate
```cpp
Ultrasonic varName(ft, fe, bt, be, d1t, d1e, d2t, d2e);
```


**Parameters**

ft: This is the Arduino pin connected to the **trigger** pin of the forward ultrasonic sensor (of the orientation pair)

fe: This is the Arduino pin connected to the **echo** pin of the forward ultrasonic sensor (of the orientation pair)

bt: Trigger pin for the back US sensor

be: Echo pin for the back US sensor

d1t, d1e: Trigger and Echo pin (respectifully) for the first ball detect sensor

d2t, d2e: Trigger and Echo pin (respectifully) for the second ball detect sensor



### Update
```cpp
int8_t result = varName.Update();
```


**Parameters**

void


**Returns**

*Returns a int8_t data type*

Returns 1 everytime it starts a new pulse, overwise 0



### GetResponse
```cpp
uint16_t distance = varName.GetResponse(index); 
```


**Parameters**

This is the index in the distance array, as this is arbitary there are defined constants to fix this and remove magic numbers from the code

| Constant Name | Value | Sensor |
| --- | --- | --- |
| US_FORWARD | 0 | The forward of the two orientation sensors  |
| US_BACK | 1 | The Backward of the two orientation sensors |
| US_BALL_1 | 2 | The First Ball Detect sensor |
| US_BALL_2 | 3 | The Second Ball Detect sensor |

An example is `varName.GetResponse(US_FORWARD)`

**Returns**

*Returns a int16_t datatype*

An unsigned 16 bit number of the distance in millimeters.

If no distance was found (i.e the pulse timedout without a response) it will return 0 instead



### GetRotation
```cpp
int8_t result = varName.GetRotation();
```


**Parameters**

void


**Returns**

*Returns a int8_t datatype*

| Constant name | Value | Meaning |
| --- | --- | --- |
| ROTATION_INVALID | 0 | One or both of the orientation sensors can not detect a distance |
| ROTATION_CORRECT | 1 | Both orientation sensors are see the same distance (within a small error margin) this means the robot does not need to rotated to correct orientation to the bridge|
| ROTATION_CLOCKWISE | 2 | The robot needs to rotate clockwise to corrent orientation |
| ROTATION_ANTICLOCKWISE | 3 | The robot needs to rotate anti-clockwise to corrent orientation |



### IsBall
```cpp
int8_t result = varName.IsBall();
```


**Parameters**

void


**Returns**

*Returns a int8_t data type*

| Constant name | Value | Meaning |
| --- | --- | --- |
| BALL_NOT_DETECTED | 0 | Neither of the front sensors have detected any object within a specified distance (100mm) |
| BALL_DETECTED | 1 | One or both of the front sensors have detected an object within range |
