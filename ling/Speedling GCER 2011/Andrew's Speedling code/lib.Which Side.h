//#include "lib.Assignments.h"
void whichSide();

void whichSide() 
{
	printf("Select orientation of the Speedling compared to botguy.\nPress <- for left of bot guy.\nPress -> for right of bot guy.\n");
	while (left_button() == 0 && right_button() == 0)
	{
		
	}

	if (left_button() == 1)
	{
		side = left;
		motorLT = 3; //Write all programs with the Zergling on left side of board!
		motorLB = 2;
		motorRT = 1;
		motorRB = 0;
		cbc_display_clear();
		printf("Zergling is on left of botguy.\n");
		sleep(1);
	}
	if (right_button() == 1)
	{
		side = right;
		motorLT = 1; //Will mirror movement so it works on both sides of the board
		motorLB = 0;
		motorRT = 2;
		motorRB = 3;
		cbc_display_clear();
		printf ("Robot is on right of botguy.\n");
		sleep(1);
	}
}
