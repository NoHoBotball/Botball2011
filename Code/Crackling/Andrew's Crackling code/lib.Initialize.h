#include "lib.Advanced movement.h"

void initialize();

void initialize()
{
	atexit(disable_servos); //Disables servos at end of program
	enable_servos();
	claw_up();
	drop_airplanes();
	printf("Hey you! Pick me up, then press A\n");
	while (a_button() == 0)
	{
		
	}
	forwardT(1000, 0.5);
	stop();
	sleep(0.5);
	forwardT(100, 0.5);
	sleep(0.5);
	printf("Alright, now put the airplane in, then press A\n");
	while (a_button() == 0)
	{
		
	}
	hold_airplanes();
	sleep(0.5);
	printf("Finally, press A to lower my claws\n");
	while (a_button() == 0)
	{
		
	}
	claw_down();
	sleep(0.5);
	while (a_button() == 0 )
	{
		printf("Press A to continue\n");
		printf("Left IR is %d, right IR is %d\nThreshold is %d\n", leftIR, rightIR, threshold);
		sleep(0.1);
		cbc_display_clear();
	}
	while (a_button() == 1)
	{
	
	}
	cbc_display_clear();
}
