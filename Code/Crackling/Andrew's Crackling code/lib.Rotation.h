#include "lib.Assignments.h"

void stop(); //Stops Crackling
void spinCW(int speed); //Use for loops and if statements
void onlyLeft(int speed);
void spinCW_time(int speed, float time); //Turns for a set time
void spinCW_degrees(int speed, float degrees); //Turn from < 0 to >= 360 degrees
void spinCCW(int speed); //Use for loops and if statements
void onlyRight(int speed);
void spinCCW_time(int speed, float time); //Turns for a set time
void spinCCW_degrees(int speed, float degrees); //Turn from < 0 to >= 360 degrees

void stop()
{
	freeze(motorLT);
	freeze(motorLB);
	freeze(motorRT);
	freeze(motorRB);
	sleep(0.1);
	ao();
}

void spinCW(int speed)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
}

void onlyLeft(int speed)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
}

void spinCW_time(int speed, float time)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
	sleep(time);
	stop();
}

void spinCW_degrees(int speed, float degrees) //DOES NOT WORK WITH VALUES GREATER THAN 360 BECAUSE THAT WOULD BE POINTLESS
{
	if (degrees > 0 && degrees <= 360)
	{
		degrees = degrees * dragTurn; //Used for fine-tuning the turn
		clear_motor_position_counter(motorLT);
		clear_motor_position_counter(motorLB);
		clear_motor_position_counter(motorRT);
		clear_motor_position_counter(motorRB);
		float CCWturn = 360 / degrees;
		float motor_Position = 0;
		motor_Position = get_motor_position_counter(motorLT) + 1; //If I don't add + 1, the simulator will try to divide by 0
		mav(motorLT, speed * tdragL2);
		mav(motorLB, speed * tdragL2);
		mav(motorRT, -speed * tdragL);
		mav(motorRB, -speed * tdragL);
		while (2200 / motor_Position > CCWturn)
		{
			motor_Position = get_motor_position_counter(motorLT);
		}
	}
	else
	{
		beep();
		printf("Please enter a value between 0 and 360 degrees\n");
	}
	stop();
}

void spinCCW(int speed)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
}

void onlyRight(int speed)
{
	mav(motorRT, speed);
	mav(motorRB, speed);
}

void spinCCW_time(int speed, float time)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
	sleep(time);
	stop();
}
void spinCCW_degrees(int speed, float degrees) //DOES NOT WORK WITH VALUES GREATER THAN 360 BECAUSE THAT WOULD BE POINTLESS
{
	if (degrees > 0 && degrees <= 360)
	{
		degrees = degrees * dragTurn; //Used for fine-tuning the turn
		clear_motor_position_counter(motorLT);
		clear_motor_position_counter(motorLB);
		clear_motor_position_counter(motorRT);
		clear_motor_position_counter(motorRB);
		float CWturn = 360 / degrees;
		float motor_Pos = 0;
		motor_Pos = get_motor_position_counter(motorRT) + 1; //If I don't add + 1, the simulator will try to divide by 0
		mav(motorRT, speed * tdragR);
		mav(motorRB, speed * tdragR);
		mav(motorLT, -speed * tdragR2);
		mav(motorLB, -speed * tdragR2);
		while (2200 / motor_Pos > CWturn)
		{
			motor_Pos = get_motor_position_counter(motorRT);
		}
	}
	else
	{
		beep();
		printf("Please enter a value between 0 and 360 degrees\n");
	}
	stop();
}
