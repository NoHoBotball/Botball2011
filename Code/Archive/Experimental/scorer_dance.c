// 'scorer' dance program
// code written by ben shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */
#define CREATE
#include "config.Definitions.h"

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/


// main:

void dance();
int danceFor (int time);


int main()
{
	danceFor(15);
} 
void dance()
{
	int tspeed = 200;
	create_connect();
	/*printf("How many times do I repeat? Up is +1, Down is -1, B to start");
	while(b_button() == 0)
	{
		if (up_button() == 1)
		{
			counter ++;
			printf("%d\n", counter);
		}
		if (down_button() ==1)
		{
			counter --;
			printf("%d\n", counter);
		}
		if (a_button() == 1)
		{
			armUp();
		}
		if (b_button() == 1)
		{
			armDown();
		}
	}*/
		create_spin_CCW(tspeed);
		armUp();
		while (get_servo_position(SERVO_ARM_LEFT_PORT) != SERVO_ARM_LEFT_UP)
		{}
		create_stop();
		create_spin_CW(tspeed);
		armDown();
		while (get_servo_position(SERVO_ARM_LEFT_PORT) != SERVO_ARM_LEFT_DOWN)
		{}
		create_stop();
		//counter --;
}

int danceFor(int time)
{
	run_for(time, dance);
}
