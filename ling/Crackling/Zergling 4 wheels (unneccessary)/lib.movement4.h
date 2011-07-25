//#include "lib.Assignments.h"
//#include "lib.Advanced movement.h"
#define motorLB 3
#define motorLF 2
#define motorRB 1
#define motorRF 0
#define drag 0


void leftwheels(int);
void rightwheels(int speed);
void freezerightwheels();
void freezeleftwheels();
void forward(int speed);
void reverse(int speed);
void forwardT(int speed, float seconds);
void reverseT(int speed, float seconds);
void stop();


void leftwheels(int speed) {
	mav(motorLB, speed);
	mav(motorLF, speed);
}

void rightwheels(int speed)
{
	mav(motorRB, speed - drag);
	mav(motorRF, speed - drag);
}

void freezeleftwheels()
{
	freeze(motorLB);
	freeze(motorLF);
}

void freezerightwheels()
{
	freeze(motorRB);
	freeze(motorRF);
}

void forward(int speed)
{
	leftwheels(speed);
	rightwheels(speed);
}

void reverse(int speed)
{
	leftwheels(-speed);
	rightwheels(-speed);
}
	
void forwardT(int speed, float seconds)
{
	leftwheels(speed);
	rightwheels(speed);
	sleep(seconds);
	freezeleftwheels();
	freezerightwheels();
}

void reverseT(int speed, float seconds)
{
	
	leftwheels(-speed);
	rightwheels(-speed);
	sleep(seconds);
	freezeleftwheels();
	freezerightwheels();
}

void stop()
{
	freezerightwheels();
	freezeleftwheels();
}

