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
		dragLT = fdrag;
		dragLB = fdrag;
		dragRT = rdrag;
		dragRB = rdrag;
		tdragL = tdrag;
		tdragR = 0.62;
		tdragL2 = 1;
		tdragR2 = 1;
		lanalog = 6; //IR sensor on left claw
		ranalog = 4;//IR sensor on right claw
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
		dragLT = fdrag;
		dragLB = fdrag;
		dragRT = rdrag;
		dragRB = rdrag;
		tdragL = 1;
		tdragR = 1;
		tdragL2 = 0.69;
		tdragR2 = tdrag;
		lanalog = 4; //IR sensor on left claw
		ranalog = 6;//IR sensor on right claw
		cbc_display_clear();
		printf ("Crackling is on right of botguy.\n");
		sleep(1);
	}
}
