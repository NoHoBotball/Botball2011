#include "lib.Assignments.h"
void whichSide();

void whichSide() 
{
	printf("Select orientation of the Zergling compared to botguy.\nPress <- for left of bot guy.\nPress -> for right of bot guy.\n");
	while (left_button() == 0 && right_button() == 0)
	{
		
	}

	if (left_button() == 1)
	{
		side = left;
		cbc_display_clear();
		printf("Zerling is on left of botguy.\n");
		sleep(1);
	}
	if (right_button() == 1)
	{
		side = right;
		cbc_display_clear();
		printf ("Robot is on right of botguy.\n");
		sleep(1);
	}
}
