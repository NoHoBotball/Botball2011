#include "lib.Assignments.h"

void forward(int speed);
void reverse(int speed);
void forwardT(int speed, float seconds);
void reverseT(int speed, float seconds);
void claw_up();
void claw_down();

void forward(int speed)
{
	
	mav(motorL, speed);
	mav(motorR, speed);
}
void reverse(int speed)
{
	
	mav(motorL, -speed);	
	mav(motorR, -speed);
}

void forwardT(int speed, float seconds)
{
	
	mav(motorL, speed);
	mav(motorR, speed);
	sleep(seconds);
	freeze(motorL);
	freeze(motorR);
}
void reverseT(int speed, float seconds)
{
	
	mav(motorL, -speed);	
	mav(motorR, -speed);
	sleep(seconds);
	freeze(motorL);
	freeze(motorR);
}

void claw_up()
{
	set_servo_position(claw, 120);
}

void claw_down()
{
	set_servo_position(claw, 1200);
}
