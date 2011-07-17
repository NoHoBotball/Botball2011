//SCORER
#define CREATE
#include "lib.Definitions.h"

int main()
{
	set_each_analog_state(0,0,0,1,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	create_connect();
	enable_servos();
	set_create_total_angle(0);
	set_create_distance(0);
	//AUO=start_process(ArmUpOpen);
	ArmUp();
	set_servo_position(
	sleep(3);
	CenterCamera();
	create_drive_straight(-200);
	while(digital(8) != 1)
	{}
	create_stop();
	sleep(1);
	ArmDownClose();
	sleep(3);
	beep();
	create_drive_straight(200);
	sleep(2);
	create_stop();
}
void ArmUpOpen()
{
	set_servo_position(ArmServo, RaiseArm);
	sleep(2);
	set_servo_position(ClawServo, OpenClaw);
	sleep(2);
}

void ArmDownClose()
{
	set_servo_position(ArmServo, LowerArm);
	sleep(2);
	set_servo_position(ClawServo, CloseClaw);
	sleep(2);
}

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
		drivemm(inchestomm(4.9), 1);
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
				create_spin_CW(100);
				while (get_create_total_angle(.1) < 0);
				{
					printf("aeqweqw");
				}
				create_stop();
			}
			if (get_create_total_angle(.1) < 0)
			{
				create_spin_CCW(100);
				while (get_create_total_angle(.1) > 0);
				{
					printf("BBBB");
				}
				create_stop();
			}
		}
	}
	/* (track_x (0,0) < 79)
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
	}*/
}


void TurnCW()
{
	#ifdef CREATE
	while(get_create_total_angle(0.1) > -90)
	{
		create_spin_CW(500);
	}
	create_stop();
	#endif
	#ifdef CBC
	mav(1,500);
	mav(0,-500);
	sleep(2.5900127);
	off(0);
	off(1);
	#endif
	}
	
	
	void ForwardTouch ()
	{
	while (analog(TouchSensor) == 0)
	{
	create_drive_straight(-500);
	}
	create_stop();
	}
	
	void Grab ()
	{
	set_servo_position (ClawServo, CloseClaw);
	}
	
	void Release ()
	{
	set_servo_position (ClawServo, OpenClaw);
	}
	
	void ArmUp ()
	{
	set_servo_position (ArmServo, RaiseArm);
	}
	
	void ArmDown ()
	{
	//drivemm(ArmCreateDist, 1);
	set_servo_position (ArmServo, LowerArm);
	}
	
	
	void drivemm(float mmspeed, float seconds)//speed is mm/s
	{
	#ifdef CREATE
	create_drive_straight(mmspeed);
	sleep(seconds);
	create_stop();
	printf("%d mm/s * %d seconds = %d mm.\n", mmspeed, seconds, mmspeed*seconds);
	#endif
	#ifdef CBC
	mav(0,mmspeed);
	mav(1,mmspeed);
	sleep(seconds);
	off(0);
	off(1);
	#endif
	
	}
	
	float inchestomm(float inches)
	{
	float mm;
	mm = (inches*25.4);
	return mm;
	}
