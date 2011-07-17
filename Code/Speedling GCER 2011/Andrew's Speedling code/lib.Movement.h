//#include "lib.Assignments.h"

void forward(int speed);
void reverse(int speed);
void forwardT(int speed, float seconds);
void reverseT(int speed, float seconds);
void stop();
void claw_up();
void claw_down();
void wheelie();
void onlyLeft(int speed);
void onlyRight(int speed);
void forwardT2(int speed, float seconds);

void forward(int speed)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
}

void forwardT2(int speed, float seconds){
	mav(motorLT, speed - 260);
	mav(motorLB, speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
	sleep(seconds);
	freeze(motorLT);
	freeze(motorLB);
	freeze(motorRT);
	freeze(motorRB);
	}
	
void reverse(int speed)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
}

void forwardT(int speed, float seconds)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
	sleep(seconds);
	freeze(motorLT);
	freeze(motorLB);
	freeze(motorRT);
	freeze(motorRB);
}
void reverseT(int speed, float seconds)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
	sleep(seconds);
	freeze(motorLT);
	freeze(motorLB);
	freeze(motorRT);
	freeze(motorRB);
}

void stop()
{
	freeze(motorLT);
	freeze(motorLB);
	freeze(motorRT);
	freeze(motorRB);
}

void wheelie()
{
	reverseT(1000,0.5);
	forwardT(1000,1);
}

void onlyLeft(int speed)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
}

void onlyRight(int speed)
{
	mav(motorRT, speed);
	mav(motorRB, speed);
}

void claw_up()
{
	set_servo_position(2, 800);
}

void claw_down()
{
	set_servo_position(2, 60);
}
