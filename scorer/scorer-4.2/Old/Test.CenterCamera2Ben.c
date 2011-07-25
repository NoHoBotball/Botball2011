//Test -- Scorer -- CenterCamera2 (Ben's request)
//CenterCamera2Ben

/*	
/	Description	:
/		-This File contains a program to center the create 
/		 onto the blocks as it drives towards them
/		-Written by Ben's request

/	Written and Maintained By:
/		-Joseph McGee	03/2011-
/	
*/
#define TouchSensor 8
#include "lib.Movement.h"
/*Function prototypes below*/
void CenterCamera2();
int main()
{
	int i;
	TurnCCW();//don't know what turn function we're using
	for(i=0; i < 5; i++)
	{
		create_drive_straight(100);
		sleep(2);
		CenterCamera2();
	}
	for(create_drive_straight(-200); !digital(TouchSensor);){}
}
/*Function definitions go below.*/
void CenterCamera2() //CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE
{
	if (track_x(0,0) > 81)			//if blocks are bd
	{
		for(create_spin_CCW(100); track_x(0,0) > 81; track_update()){}	//WHAT TRACK # IS RED? MAKE SURE IT DOESNT DETECT BOTGUY -- remember to calibrate CBC to  blocks
		create_stop();
	}
	if (track_x(0,0) < 78)			//if blocks are fd
	{
		for(create_spin_CW(100); track_x(0,0) < 78; track_update()){}	//WHAT TRACK # IS RED? MAKE SURE IT DOESNT DETECT BOTGUY -- remember to calibrate CBC to  blocks
		create_stop();
	}
}
