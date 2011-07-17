#define CREATE
#include "config.Definitions.h"

int main()
{
	create_connect();
	enable_servos();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	armPosBlockGrab();
	clawGrab();
	clawOpen();
	while(black_button() == 0) {}
	clawClose();
	armPosBlockStack2();
	blockStack3();
}
