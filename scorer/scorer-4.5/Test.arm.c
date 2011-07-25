#define CREATE
#include "config.Definitions.h"
int main()
{	
	enable_servos();
	if(black_button() ==1)
	{
		while(a_button()==0)
		{
			if(up_button() == 1)
			{
				set_servo_position(SERVO_ARM_LEFT_PORT, get_servo_position(0)+30);
				set_servo_position(SERVO_ARM_RIGHT_PORT, get_servo_position(3)-30);
				printf("%d, %d\n", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
			}
			if(down_button() == 1)
			{
				set_servo_position(SERVO_ARM_LEFT_PORT, get_servo_position(0)-30);
				set_servo_position(SERVO_ARM_RIGHT_PORT, get_servo_position(3)+30);
				printf("%d, %d\n", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
			}
			if(left_button() == 1)
			{
				set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)+30);
				set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)-30);
				printf("%d, %d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
			}
			if(right_button() == 1)
			{
				set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)-30);
				set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)+30);
				printf("%d, %d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
			}
		}
	}
	while (black_button() == 0) {}
	armPosSB();
	clawSB();
	while (black_button() == 0) {}
	armPosBlockGrab();
	clawGrab();
	clawAdjust();
	clawOpen();
	sleep(1);
	clawClose();
	while (black_button() == 0) {}
	armPosBlockStack1();
	clawStack1();
	clawAdjust();
	clawOpen();
	while (black_button() == 0) {}
	armPosBlockGrab();
	clawGrab();
	clawAdjust();
	clawOpen();
	sleep(1);
	clawClose();
	while (black_button() == 0) {}
	armPosBlockStack2();
	clawStack2();
	clawAdjust();
	while (black_button() == 0) {}
}

void clawAdjust()
{	
	while (right_button() == 0) {
		if(up_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)+30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)-30);
			printf("%d,%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
		if(down_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)-30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)+30);
			printf("%d,%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
	}
}
