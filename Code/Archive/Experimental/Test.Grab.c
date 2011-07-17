#define CREATE
#include "config.Definitions.h"
int main()
{
	enable_servos();
	while (black_button() == 0) {}
	armPosBlockGrab();
	while (black_button() == 0) {}
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_GRAB);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_GRAB);
	while (black_button() == 0) {}
	clawClose();
	while (black_button() == 0) {}
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK1);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK1);
	while (black_button() == 0) {}
	armPosBlockStack1();
	while (black_button() == 0) {}
	clawOpen();
}
	
