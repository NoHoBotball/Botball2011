#define CREATE
#include "lib.Definitions.h"
void Wait();
int main()
{
	initialize();
	sleep(1.5);
	Lift();
	drivemm(100,1);
	sleep(1.5);
	ForwardTouch(-100);
	ArmStack();
	while(!black_button()){}
	mav(Claw, -400);
	sleep(2);
	off(Claw);
	drivemm(100,3);
	
}

void Wait()
{
	while (black_button() == 0)
	{}
	sleep(1);
}
