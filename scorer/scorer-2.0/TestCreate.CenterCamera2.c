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
//void whichSide();

int main()
{
	initialize();
	CenterCamera();
}

/*Function definitions go below.*/
/*
void whichSide() {
	printf ("select orientation of the robot compared to botguy.\n(make sure camera is facing right way)\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (b_button() == 0 && a_button() == 0){
	}
	if (b_button()){
		Side = Right;
		cbc_display_clear();
		printf ("robot is on right of botguy.\n");
		sleep(1);
	}
	if (a_button()){
		Side = Left;
		cbc_display_clear();
		printf ("robot is on left of botguy.\n");
		sleep(1);
	}
}
*/
