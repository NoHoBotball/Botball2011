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
	while(right_button() ==0)
	{
		char Side = Left;
		if (a_button() ==1)
		{
			create_connect();
			enable_servos();
			ArmUp();
			while (black_button() == 0)
			{
				track_update();
				printf("%d\n", track_x(0,0));
			}
			TurnCW();
			ForwardTouch(-200);
		}
		if (b_button() ==1)
		{
			initialize();
			CenterCamera();
			Lift();
		}
	}
}
/*Function definitions go below.*/
