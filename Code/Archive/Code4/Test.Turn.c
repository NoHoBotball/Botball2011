/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
#include "lib.Definitions.h"

int main()
{
	X=0;
	create_connect();
	set_create_total_angle(0);
	printf("X\tAngle");
	cbc_display_clear();
		printf("A to turn CCW 90deg.\tB to turn CW 90deg.\n");
		printf("Left to turn CCW 45deg.\tRight to turn CW 45deg.\n");
		printf("Down to force angle readjustment.\n");
	while(black_button()==0)
	{
		if (a_button()==1)
		{
			turnHalfCCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (b_button()==1)
		{
			turnHalfCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (left_button()==1)
		{
			turnCCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (right_button() == 1)
		{
			turnCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (down_button() == 1)
		{
			turnAdjust();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
	}
}

/*Function definitions go below.*/
