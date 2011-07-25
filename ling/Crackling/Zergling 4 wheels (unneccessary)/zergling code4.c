//#include "lib.Assignments4.h"
//#include "lib.Which Side.h"
//#include "lib.Strategy selection.h"
#include "lib.Movement4.h"
#include "lib.Rotation4.h"


/*
int motorLB; //Left motor back
int motorLF; //Left motor front
int motorRB; //Right motor back
int motorRF; //Right motor front*/

int main()
{
	//whichSide(); //Pick what side the Zergling is on. Code should be written for left side of board, will mirror movement if on right
	forward(1000);
	sleep(10);
	stop();
	/*sleep(2);
	reverseT(500,2);
	sleep(2);
	forwardT(500,2);
	sleep(2);
	reverseT(500,2);
	sleep(2);
	spinCCW(500);
	sleep(1);
	stop();
	spinCW(500);
	sleep(1);
	stop();*/
	
	//strategySelect(); //Choose what our Zergling will do for the game
	//wait_for_light(light); //Waits for light to start
	//runStrategy(); //Runs the strategy that the user selects
	//printf("%d is motorL", motorL);
}
