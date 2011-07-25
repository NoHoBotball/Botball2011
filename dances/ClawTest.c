#define CREATE
#include "lib.Definitions.h"
int main()
{
	armUp();
	sleep(2);
	armDown();
	set_servo_position(0,1900);
	set_servo_position(3,0);
}
