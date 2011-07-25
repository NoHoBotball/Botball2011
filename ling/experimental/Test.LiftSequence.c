#define CREATE
#include "config.Definitions.h"

int main()
{
	enable_servos();
	create_connect();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	//detect block
	printf("%d\n", ET_FRONT);
	drive(-200);
	if (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK1)
	{
		while (ET_FRONT < ET_FRONT_BLOCK && get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK1) {
			set_servo_position(SERVO_ARM_LEFT_PORT, get_servo_position(0)+30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, get_servo_position(3)-30);
			sleep(.01);
		}
	}
	if (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK1)
	{
		while (ET_FRONT < ET_FRONT_BLOCK && get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK1) {
			set_servo_position(SERVO_ARM_LEFT_PORT, get_servo_position(0)-30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, get_servo_position(3)+30);
			sleep(.01);
		}
	}	
	if (ET_FRONT < ET_FRONT_BLOCK) //didnt reach blocks
	{
		detectBlock();
		backFromTouch(0);
		clawGrab();
		armPosBlockGrab();
		scootUp(0);
	}
	if (get_servo_position(SERVO_ARM_LEFT_PORT) != SERVO_ARM_LEFT_STACK1)  //arm not in position
	{
		backFromTouch(0);
		clawGrab();
		armPosBlockGrab();
		scootUp(0);
	}
}
		
