#define CREATE
#include "config.Definitions.h"

int main()
{
	enable_servos();
	create_connect();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	/*
	while(up_button()==0)
	{
	while(black_button() ==0) {}
	clawSB();
	armPosSB();
	while(black_button() ==0) {}
	clawGrab();
	clawOpen();
	armPosBlockGrab();
	while(black_button() ==0) {}
	clawClose();
	while(black_button() ==0) {}
	armPosBlockStack1();
	clawStack1();
	while(black_button() ==0) {}
	clawOpen();
	while(black_button() ==0) {}
	clawGrab();
	armPosBlockGrab();
	while(black_button() ==0) {}
	clawClose();
	while(black_button() ==0) {}
	/*set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK2);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK2);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK2);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK2);
	sleep(2);
	armPosBlockStack2();
	clawStack2();
	while(black_button() ==0) {}
	clawOpen();
	}*/

	//reach first blocks
	armPosBlockStack1();
	clawStack1();
	clawOpen();
	detectBlock();
	//back up
	backFromTouch(0);
	//arm to correct pos
	armPosBlockGrab();
	clawGrab();
	//scoot up and grab
	scootUp(0);
	clawClose();  
	while(black_button() == 0) {}
	driveAtMmFor(200, 2);
	//drive with arm a bit up, place first pair of cubes
	armPosBlockStack1();
	clawStack1();
	detectPVC();
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_GRAB+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_GRAB-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_GRAB+100);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_GRAB-100);
	backFromTouch(1);
	//correct pos
	armPosBlockGrab();
	clawGrab();
	//scoot up
	scootUp(1);
	clawOpen();
	driveAtMmFor(200, 2);
	while(black_button() == 0) {}
	clawClose();
	//drive with arm a bit up, place second pair on top of first
	armPosBlockStack1();
	clawStack1();
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK1+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK1-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK1+200);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK1-200);
	detectBlock();
	backFromTouch(2);
	//correct pos
	clawStack1();
	armPosBlockStack1();
	clawOpen();
	driveAtMmFor(200, 2);
	armPosBlockGrab();
	clawGrab();
	while(black_button() == 0) {}
	clawClose();
	armPosBlockStack2();
	clawStack2();
	detectPVC();
	backFromTouch(3);
	clawOpen();
	driveAtMmFor(200, 2);
}
