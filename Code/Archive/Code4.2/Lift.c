// tests Lift() function
// written by Ben Shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */
#define CREATE
#include "lib.Definitions.h"

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

int main()
{
	create_connect();
	enable_servos();
	set_create_total_angle(0);
	set_create_distance(0);	
	
	whichSide();
	CenterCamera();
	Lift();
}
