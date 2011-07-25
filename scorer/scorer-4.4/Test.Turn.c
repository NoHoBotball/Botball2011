/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
#include "config.Definitions.h"

int main()
{
	X=0;
	create_connect();
	set_create_total_angle(0);
	printf("X\tAngle");
	cbc_display_clear();
	printf("A to turn CCW 90deg.\tB to turn CW 90deg.\n");
	printf("Left to turn CCW 45deg.\tRight to turn CW 45deg.\n");
	printf("Down to force angle readjustment.\n");
	while(a_button()==0) //black_button
	{
		/*
		if (a_button()==1)
		{
			turn(tspeed,45);
			//turnHalfCCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}*/
		if (b_button()==1)
		{
			int i=0;
			int adjust_speed = 10;
			printf(" %d\n", get_create_total_angle(.1));
			//turn(tspeed,-45);
			//turnHalfCW();
			//printf("%d\t%d\n",X,get_create_total_angle(0.1));
			create_drive(-500,1);
			sleep(.375);
			create_stop();
			//printf("Initial Turn CCW");
			//create_stop();
			//printf("%d\n", get_create_total_angle(.1);
			printf("%d\n", get_create_total_angle(.1));
			create_stop();
			while (get_create_total_angle(.1)-X > -88 || get_create_total_angle(.1)-X < -92)
			{
				printf("Adjusting");
				printf("%d\n", get_create_total_angle(.1));
				if (get_create_total_angle(.1)-X < -90) //CCW ADDS TO TOTAL ANGLE
				{
					create_drive_direct(adjust_speed, -adjust_speed);
					printf("ADJUST 1  %d\n", get_create_total_angle(.1));
					while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
					{}
					create_stop();
				}
				if (get_create_total_angle(.1)-X > -90)
				{
					create_drive_direct(-adjust_speed, adjust_speed);
					printf("ADJUST 2  %d\n", get_create_total_angle(.1));// JUMPS SEVEN DEGRESS SINCE LAST MEASUREMENT. WTF
					while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
					{}
					create_stop();
				}
			}
			printf("%d\n", get_create_total_angle(.1));
			create_stop();
			X=X-90;
		}
		if (left_button()==1)
		{
			//turn(tspeed,90);
			//turnCCW();
			turnCW();
		}
		if (right_button() == 1)
		{
			turn(tspeed,-90);
			//turnCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (down_button() == 1)
		{
			turnAdjust();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
	}
}

/*Function definitions go below.*/
