// tests Lift() function
// written by Ben Shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */
#define CREATE
#include "lib.Definitions.h"

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/
void WhichSide();

int main()
{
	create_connect();
	enable_servos();
	set_create_total_angle(0);
	set_create_distance(0);	
	
	WhichSide();
	CenterCamera();
	Lift();
}

void WhichSide () // For Left/Right of Botguy
{
	printf ("Press and hold button for 1 second.\nA button for Left side, B button for Right side.\n");
	while (b_button() == 0 && a_button() == 0)
	{
	}
	if (b_button())
	{
		Side = Right;
		printf ("On Right of Botguy. Set up lights.\n");
		sleep(1);
	}
	if (a_button())
	{
		Side = Left;
		printf ("On Left of Botguy. Set up lights.\n");
		sleep(1);
	}
}
