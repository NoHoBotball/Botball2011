../***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#include "lib.Conversions.h"
#define ET 1
int main()
{
	create_connect();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	create_drive_straight(300);
	while (analog10(ET) < 950)
	{
	}
	create_stop();
	while(analog10(ET) > 600)
	{
		create_drive_straight(300 - analog10(ET)/3);
	}
	create_drive_straight(100);
	while(digital(8)==0)
	{
	}
	create_stop();
}
