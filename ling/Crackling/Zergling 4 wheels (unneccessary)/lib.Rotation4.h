//#include "lib.Assignments.h"
//#include "lib.Advanced movement.h"
#define motorLB 3
#define motorLF 2
#define motorRB 1
#define motorRF 0
#define drag 0



void spinCCW(int speed); //Use for loops and if statements
void spinCCW_time(int speed, float time); //Turns for a set time
void spinCCW_degrees(int speed, float degrees); //Turn from < 0 to >= 360 degrees, else turns

void spinCCW(int speed)
{
	mav(motorLB, -speed);
	mav(motorLF, -speed);
	mav(motorRB, speed);
	mav(motorRF, speed);
}

void spinCW(int speed)
{
		mav(motorLB, -speed);
	mav(motorLF, speed);
	mav(motorLB, speed);
	mav(motorRB, -speed);
	mav(motorRF, -speed);
}

void spinCCW_time(int speed, float time)
{
	mav(motorLB, -speed);
	mav(motorLF, -speed);
	mav(motorRB, speed);
	mav(motorRF, speed);
	sleep(time);
	stop();
}

void spinCW_time(int speed, float time)
{
	mav(motorLB, speed);
	mav(motorLF, speed);
	mav(motorRB, -speed);
	mav(motorRF, -speed);
	sleep(time);
	stop();
}

/*void spinCCW_degrees(int speed, float degrees) //DOES NOT WORK WITH VALUES GREATER THAN 360 BECAUSE THAT WOULD BE POINTLESS
{
	if (degrees > 0 && degrees <= 360)
	{
		degrees = degrees * dragTurn; //This lowers the amount because of the gears we have on the wheels
		clear_motor_position_counter(motorL);
		clear_motor_position_counter(motorR);
		float turn = 360 / degrees;
		float motorR_Pos = get_motor_position_counter(motorR) + 1; //If I don't add + 1, the simulator will try to divide by 0
		while (2048 / motorR_Pos > turn)
		{
			mav(motorL, -speed);
			mav(motorR, speed);
			motorR_Pos = get_motor_position_counter(motorR) + 1;
			printf("motor pos %f\n", motorR_Pos);
		}
	}
	else
	{
		beep();
		printf("Please enter a value between 0 and 360 degrees\n");
	}
	stop();
}
*/
