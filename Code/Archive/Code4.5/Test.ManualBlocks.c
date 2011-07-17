#define CREATE
#include "config.Definitions.h"

int main()
{
	create_connect();
	eable_servos();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	side == LEFT;
	armPosBlockGrab();
	clawGrab();
	clawOpen();
	while (black_button () == 0) {}
	clawClose();
	while (black_button () == 0) {}
	driveAtMmFor(inToMm(2.5), 1);
	
