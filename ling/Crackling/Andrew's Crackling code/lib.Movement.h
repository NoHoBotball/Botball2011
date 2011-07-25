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
	mav(mLT, speed);
	mav(mLB, speed);
	mav(mRT, speed * dragLT);
	mav(mRB, speed * dragLB);
}
void reverse(int speed)
{
	mav(mLT, -speed);
	mav(mLB, -speed);
	mav(mRT, -speed * dragRT);
	mav(mRB, -speed * dragRB);
}

void forwardT(int speed, float seconds)
{
	mav(mLT, speed);
	mav(mLB, speed);
	mav(mRT, speed * dragLT);
	mav(mRB, speed * dragLB);
	sleep(seconds);
	ao();
}

void reverseT(int speed, float seconds)
{
	mav(mLT, -speed);
	mav(mLB, -speed);
	mav(mRT, -speed * dragRT);
	mav(mRB, -speed * dragRB);
	sleep(seconds);
	ao();
}

void claw_up()
{
	set_servo_position(claw, 2000);
}

void claw_mid()
{
	set_servo_position(claw, 1050);
}

void claw_down()
{
	set_servo_position(claw, 700);
}

void hold_airplanes()
{
	set_servo_position(0, 2000);
}

void drop_airplanes()
{
	set_servo_position(0, 650);
}
