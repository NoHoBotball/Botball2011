//SCORER
#define CREATE			//create is the drive train



#include "lib.Definitions.h"

void WhichSide ();
int main()
{
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	create_connect();
	enable_servos();
	enableServoDown();
	setup();
	//Grab();
	//enableServoDown();
	Release();
	ArmUp();
	set_create_total_angle(0);
	set_create_distance(0);	
	WhichSide();
	sleep(2);
	create_drive_straight(-200);
	CenterCamera_Jae();
	Lift();
	while(!black_button())
	{
		sleep(2);
	}
}

void WhichSide () // For Left/Right of Botguy
{
	printf ("Press and hold button for 1 second.\n\tB button for Right side, A button for Left side.\n");
	while (b_button() == 0 && a_button() == 0)
	{
		sleep(1);
		printf ("Try again.\n");
	}
	if (b_button())
	{
		Side = Right;
		printf ("On Right of Botguy. Set up lights.\n");
		sleep(1);
	}
	if (a_button())
	{
		Side = Left;
		printf ("On Left of Botguy. Set up lights.\n");
		sleep(1);
	}
}
/*

void CenterCamera() //CAMERA MUST BE AT CENTER OF CREATE, POINTING Right RESPECT TO CREATE
{
	track_update();
	if (track_x (0,0) > 81)
	{
		create_drive_straight(-200);
		while (track_x (0,0) > 81)	//WHAT TRACK # IS RED? MAKE SURE IT DOESNT DETECT BOTGUY
		{
			track_update();
		}
		create_stop();
		set_create_distance(0);
		drivemm(-inchestomm(6), 1);
		set_create_total_angle(0);
		create_drive(101.3,1);  //uses int. does it round?
		sleep(2.057252314);
		create_stop();
		get_create_total_angle(.1);
		printf("asdb");
		if (get_create_total_angle(.1) != 90)
		{
			set_create_total_angle(get_create_total_angle(.1) - 90);
			printf("%f\n",get_create_total_angle(.1));
			if (get_create_total_angle(.1) > 0) //CCW ADDS TO TOTAL ANGLE
			{
				create_spin_CW(150);
				while (get_create_total_angle(.1) < 0);
				{
					printf("aeqweqw");
				}
			}
			if (get_create_total_angle(.1) < 0)
			{
				create_spin_CCW(150);
				while (get_create_total_angle(.1) > 0);
				{
					printf("BBBB");
				}
			}
			create_stop();
		}
		create_drive_straight(-200);
		while(digital(8 !=0))
		{
		}
		create_stop();		
	}
	
	if (track_x (0,0) < 79)
	{
		create_drive_straight(200);
		while (track_x (0,0) < 79)
		{
			track_update();
		}
		create_stop();
		beep();
		set_create_distance(0);
		drivemm(-inchestomm(5), 1);
		create_drive(206.972051,1);
		sleep(1);
		create_stop();
		create_drive_straight(-200);
		while(digital(8 == 0))
		{
		}
		create_stop();
	}
}*/
