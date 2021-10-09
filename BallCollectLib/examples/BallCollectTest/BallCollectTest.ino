
#include <BallCollectLib.h>

//first param is the motor pin, the second is the dispose solonoid pin
BallCollect bc(2,3);

void setup(){
    bc.StartCollect(); //Start the ball collection motor on with a default timeout (2 seconds)
    bc.StartCollect(1500); //For a manual timeout (1.5 seconds)
    bc.StartCollect(0); //This will make the ball collection run forever (until stop is called)
    bc.StopCollect(); //Force the ball collection motor off

    bc.StartDispose(); //This will open the ball disposal with a default timeout (2 seconds)
    bc.StartDispose(1500); //For a manual timeout (1.5 seconds)
    bc.StartDispose(0); //This will make the solonoid open forever (until stop is called)
    bc.StopDispose(); //Force the disposal unit closed
}

void loop(){
    bc.Update(); //Must be called every loop for the timeout to work
}