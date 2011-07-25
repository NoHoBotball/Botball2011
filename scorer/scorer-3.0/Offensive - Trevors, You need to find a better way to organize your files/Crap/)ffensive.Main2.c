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
//analog(0) is the front proximity sensor, analog(1) is center line detector, analog(2) is the back line sensor, analog(3) is the side line sensor

int main()
{
	float linethreshold; // this is the value for the line sensor that says that it is over a line
	float frontthreshold; //this is the value for the front sensor(sonar/ir) that says that the robot is close to bumping into something
    
	//robot waits for light
	wait_for_light(port_number);
	
	run_for(118, function_name);//replace num_secs with the amount of time to run and function_name with your function's name
	//move until the line of the starting box is detected
	while(analog(1) < linethreshold) {
		mav(0,300); mav(3,300);
	}
	//rotate until the robot is positioned parallel over the line
	While (analog10(2) <threshold) {
	mav(0,-300); mav(3,300);
}
	//move forward, either to bump or to pipe
	while(analog(0) < frontthreshold) {//while the front is clear move forward
	mav(0,800); mav(3,800);
}
//
}

/*Declare functions here as needed.*/
