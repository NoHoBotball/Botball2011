/***************************************************************************/
/*********     This comment should be filled with a description    *********/
/*********         of your program and what it does.               *********/
/***************************************************************************/

/* Includes the Standard IO Library */
#include <stdio.h>
#include <kiss-compat.h>
//#include <kiss-graphics.h>
//#include <kiss-serial.h>
//#include <kiss-create-2011.h>
//#include <kiss-input.h>

/* #defines and constants go here.*/

/*Global variables go here (if you absolutely need them).*/

/*Function prototypes below*/

int main()
{
	int bumpvalue; // this is the value that the accelerometer reads when it goes over the center bump
	while(accelerometer < bumpvalue) {
    mav(0,600); mav(3,600); //this allows the robot to move towards the bump until it hits it;
		}
		mav(0,200); mav(3,200);// move slightly so that the robot is fully over the bump
		sleep(0.5);
		//INSERT CODE HERE this needs to be a 90 degree turn, so the the robot is aligned over the bump
		mav(0,700);mav(3,700);
}

/*Declare functions here as needed.*/
