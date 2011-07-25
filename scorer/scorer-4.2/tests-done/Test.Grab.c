#define CREATE
#include "lib.Definitions.h"
void Wait();
int main()
{
	initialize();
	Wait();
	Grab();
	Wait();
	ArmUp();
	Wait();
	ArmStack();
	Wait();
	mav(Claw,-500);
	sleep(1.5);
	off(Claw);
	Wait();
	ArmDown();
}

void Wait()
{
	while(b_button() != 1)
	{}
	sleep(1);
	beep();
}

