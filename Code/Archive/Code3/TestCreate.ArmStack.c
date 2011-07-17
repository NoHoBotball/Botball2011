#define CREATE
#include "lib.Definitions.h"

int main()
{
	enable_servos();
	set_servo_position(MiniServo, LowerMini);
	ArmDown();
	Release();
	while(b_button() ==0)
	{}
	Grab();
	sleep(1);
	ArmUp();
	int X = 0;
	while (black_button() == 0)
	{
		set_servo_position(ArmServo1, RaiseArm1-X);
		set_servo_position(ArmServo2, RaiseArm2+X);
		if(a_button() ==1)
		{
			X=X+20;
			sleep(1);
		}
		printf("%d, %d \n", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
	}
}
