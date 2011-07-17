#include "lib.Assignments.h"

void forward(int speed);
void reverse(int speed);
void forwardT(int speed, float seconds);
void reverseT(int speed, float seconds);
void claw_up();
void claw_mid();
void hold_airplanes();
void claw_down();
void hold_airplanes();
void drop_airplanes();

void forward(int speed)
{
	mav(motorLT, speed * dragLT);
	mav(motorLB, speed * dragLB);
	mav(motorRT, speed);
	mav(motorRB, speed);
}
void reverse(int speed)
{
	mav(motorLT, -speed * dragLT);
	mav(motorLB, -speed * dragLB);
	mav(motorRT, -speed * dragRT);
	mav(motorRB, -speed * dragRB);
}

void forwardT(int speed, float seconds)
{
	mav(motorLT, speed * dragLT);
	mav(motorLB, speed * dragLB);
	mav(motorRT, speed);
	mav(motorRB, speed);
	sleep(seconds);
	ao();
}
void reverseT(int speed, float seconds)
{
	mav(motorLT, -speed * dragLT);
	mav(motorLB, -speed * dragLB);
	mav(motorRT, -speed * dragRT);
	mav(motorRB, -speed * dragRB);
	sleep(seconds);
	ao();
}

void claw_up()
{
	set_servo_position(claw, 900);
}

void claw_mid()
{
	set_servo_position(claw, 200);
}

void claw_down()
{
	set_servo_position(claw, 80);
}

void hold_airplanes()
{
	set_servo_position(0,1900);
}

void drop_airplanes()
{
	set_servo_position(0, 550);
}
