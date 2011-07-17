#include "lib.Movement.h"
#include "lib.Rotation.h"

void Dance_1(int repeat);

void Dance_1(int repeat)
{
	int i;
	for (i = 0; i != repeat; i++)
	{
		claw_up();
		forwardT(1000, 0.5);
		claw_down();
		reverseT(1000, 0.5);
		claw_up();
		forwardT(1000, 0.5);
		claw_down();
		reverseT(1000, 0.5);
		sleep(0.5);
		spinCW_degrees(500, 90);
		spinCCW_degrees(500, 180);
		spinCW_degrees(500, 180);
		spinCCW_degrees(500, 90);
	}
}
