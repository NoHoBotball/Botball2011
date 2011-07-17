#define CREATE   //EXPERIMENTAL

#include "config.Definitions.h"

void main()
{
	create_connect();
	enable_servos();
	set_each_analog_state(1,1,0,0,0,0,0,0);
	initialize();
	armPosBlockStack2();
	clawStack2();
	clawOpen();
	create_drive_straight(300);
	run_for(3, clawGrab);
	create_stop();
	clawGrab();
}
 //open claw while 45
//arcturn while moving arm up
//claw in the right angle while detect block
//moving back arm down (not immediately)
