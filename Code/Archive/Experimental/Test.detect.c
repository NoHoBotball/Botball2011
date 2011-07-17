#define CREATE
#include "config.Definitions.h"

int main()
{
	enable_servos();
	create_connect();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	printf("%d\n", ET_FRONT);
	armPosBlockStack2();
	clawStack2();
	detectBlock(200);
	while (black_button() == 0) {}
	driveAtMmFor(200,1);
	while (black_button() == 0) {}
	detectPVC(400);
}
