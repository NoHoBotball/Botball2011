#define CREATE
#include "config.Definitions.h"
int main()
{
	enable_servos();
	create_connect();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	//armPosSB();
	//clawSB();
	clawOpen();
	armPosBlockStack1();
	clawStack1();
	while(black_button() == 0 ) {}
	detectBlock();
	while(black_button() == 0 ) {}
	grabBlocks();
	while(black_button() == 0 ) {}
	driveAtMmFor(100,1);
	armPosBlockStack1();
	clawStack1();
	blockStack1();
	while(black_button() == 0 ) {}
	armPosBlockStack1();
	detectBlock();
	grabBlocks();
	while(black_button() == 0 ) {}
	blockStack2();
	while(black_button() == 0 ) {}
	armPosBlockStack1();
	detectBlock();
	grabBlocks();
	while(black_button() == 0 ) {}
	blockStack3();
}
