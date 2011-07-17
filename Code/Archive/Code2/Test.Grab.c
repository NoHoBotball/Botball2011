#define CREATE
#include "lib.Definitions.h"
void Wait();
int main()
{
	enable_servos();
	ArmDown();
	set_servo_position(MiniServo, LowerMini);
	Release();
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

