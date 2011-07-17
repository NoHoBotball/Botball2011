// navigation navigation navigation - c file
// written by ben shukman

#define CREATE

#include "config.Definitions.h"

int main() {
	set_each_analog_state(0,1,0,0,0,0,0,0);
	create_connect();
	enable_servos();
	armPosSB();
	clawSB();
	//seedReturn();
	seed();
}
