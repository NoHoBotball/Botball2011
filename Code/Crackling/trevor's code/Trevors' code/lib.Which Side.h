#include "lib.Assignments.h"
void whichSide();

void whichSide() 
{
	printf("Select orientation of the Crackling compared to botguy.\nPress <- for left of bot guy.\nPress -> for right of bot guy.\n");
	while (left_button() == 0 && right_button() == 0)
	{
		
	}

	if (left_button() == 1)
	{
		side = left;
		motorLT = 2; //Write all programs with the Crackling on left side of board!
		motorLB = 3;
		motorRT = 1;
		motorRB = 0;
		dragLT = drag;
		dragLB = drag;
		dragRT = 1;
		dragRB = 1;
		tdragL = tdrag;
		tdragR = 1;
		lanalog = 6; //IR sensor on left claw
		ranalog = 4;//IR sensor on right claw
		//leftIR = analog10(6) //IR sensor on left claw
		//rightIR = analog10(4) //IR sensor on right claw
		cbc_display_clear();
		printf("Crackling is on left of botguy.\n");
		sleep(1);
	}
	if (right_button() == 1)
	{
		side = right;
		motorLT = 1; //Will mirror movement so it works on both sides of the board
		motorLB = 0;
		motorRT = 2;
		motorRB = 3;
		dragLT = 1;
		dragLB = 1;
		dragRT = drag;
		dragRB = drag;
		tdragL = 1;
		tdragR = tdrag;
		lanalog = 4; //IR sensor on left claw
		ranalog = 6;//IR sensor on right claw
		cbc_display_clear();
		printf ("Crackling is on right of botguy.\n");
		sleep(1);
	}
}
