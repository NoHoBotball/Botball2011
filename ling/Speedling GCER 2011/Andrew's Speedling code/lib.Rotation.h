//#include "lib.Assignments.h"

void spinCW(int speed); //Use for loops and if statements
void spinCW_time(int speed, float time); //Turns for a set time
void spinCW_degrees(int speed, float degrees); //Turn from < 0 to >= 360 degrees, else turns
void spinCCW(int speed); //Use for loops and if statements
void spinCCW_time(int speed, float time); //Turns for a set time
void spinCCW_degrees(int speed, float degrees); //Turn from < 0 to >= 360 degrees, else turns
void spinCCW_180();
void spinCCW_90();
void spinCW_180();
void spinCW_90();
float turntime = 1.5;// used to be 1.5038912587763;

void spinCCW(int speed)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
}
void spinCCW_time(int speed, float time)
{
	mav(motorLT, speed);
	mav(motorLB, speed);
	mav(motorRT, -speed);
	mav(motorRB, -speed);
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
		float CCWturn = 360 / degrees;
		float motor_Position = 0;
		motor_Position = get_motor_position_counter(motorLT) + 1; //If I don't add + 1, the simulator will try to divide by 0
		while (2048 / motor_Position > CCWturn)
		{
			mav(motorLT, speed);
			mav(motorLB, speed);
			mav(motorRT, -speed);
			mav(motorRB, -speed);
			motor_Position = get_motor_position_counter(motorLT) + 1;
		}
	}
	else
	{
		beep();
		printf("Please enter a value between 0 and 360 degrees\n");
	}

	stop();
}


void spinCCW_90()
{
	mav(motorLT, 500);
	mav(motorLB, 500);
	mav(motorRT, -500);
	mav(motorRB, -500);
	sleep(turntime);
	ao();
}

void spinCCW_180()
{
	mav(motorLT, 500);
	mav(motorLB, 500);
	mav(motorRT, -500);
	mav(motorRB, -500);
	sleep(turntime*2 - 0.3);
	ao();
}

void spinCW_90()
{
	mav(motorLT, -500);
	mav(motorLB, -500);
	mav(motorRT, 500);
	mav(motorRB, 500);
	sleep(turntime);
	ao();
}

void spinCW_180()
{
	mav(motorLT, -500);
	mav(motorLB, -500);
	mav(motorRT, 500);
	mav(motorRB, 500);
	sleep(turntime*2 - 0.3);
	ao();
}

void spinCW(int speed)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
}
void spinCW_time(int speed, float time)
{
	mav(motorLT, -speed);
	mav(motorLB, -speed);
	mav(motorRT, speed);
	mav(motorRB, speed);
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
		float CWturn = 360 / degrees;
		float motor_Pos = 0;
		motor_Pos = get_motor_position_counter(motorRT) + 1; //If I don't add + 1, the simulator will try to divide by 0
		while (2048 / motor_Pos > CWturn)
		{
			mav(motorLT, -speed);
			mav(motorLB, -speed);
			mav(motorRT, speed);
			mav(motorRB, speed);
			motor_Pos = get_motor_position_counter(motorRT) + 1;
		}
	}
	else
	{
		beep();
		printf("Please enter a value between 0 and 360 degrees\n");
	}
	stop();
}
