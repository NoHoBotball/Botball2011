//Library -- Movement
//Movement Functions

#include "ross.Metrics.h"

#ifndef LIB_MOVEMENT
#define LIB_MOVEMENT

/*	
/	Description	:
/		-This File contains all funcions relating to the funcitonality of the 
/		 Drive Trains of all Create or 2wheel-based CBC robots
/
/	Written and Maintained By:
/		-Jae Kim		02/2011-
/		-Joseph McGee	02/2011-
/
/	
*/


/*	you must define
/		TOUCH_FRONT and either Create 
/		or CBC, motorR, motorL 
/		in the file from which this funcition is called
*/

int X;//ideal turn correction factor

void driveMm(float mm_speed, float seconds);//speed is mm/s
void driveIn(float in_speed, float seconds);//speed is in/s
void drive(int speed);

void driveAtMillimeters(float speed);
void driveAtInches(float speed);
void driveAtMillimetersFor(float speed, float seconds);
void driveAtInchesFor(float speed, float seconds);

void driveAtMm(float speed);
void driveAtIn(float speed);
void driveAtMmFor(float speed, float seconds);
void driveAtInFor(float speed, float seconds);

void stop();
void stopIn(float seconds);

void turn(int speed, int angle);
void turnAdjust();

void forwardTouch();
void clearWall();

void turnForRight(int speed, int angle);
void turnForLeft(int speed, int angle);

int beepFor(int num_of_beeps);

//Drive Straight Functions
#ifdef DRIVE
void driveMm(float mm_speed, float seconds)//speed is mm/s
{
	#ifdef CREATE
	printf("%d mm/s * %2.3f seconds = %2.3f mm.\n", mm_speed, seconds, mm_speed*seconds);
	create_drive_straight(mm_speed);
	msleep(seconds*1000);
	create_stop();
	#endif
	#ifdef CBC
	mav(motorR,mm_speed);//doesn't actually go at 'mmspeed' mm/s
	mav(motorL,mm_speed);
	sleep(seconds);
	freeze(motorR);
	freeze(motorL);
	#endif
	
}


void driveIn(float in_speed, float seconds)//speed is in/s
{
	#ifdef CREATE
	int mm_speed = inchesToMillimeters(in_speed);
	printf("%f in/s = %f mm/s \n", in_speed, inchesToMillimeters(in_speed));
	printf("%d mm/s * %2.3f seconds = %2.3f mm.\n", mm_speed, seconds, mm_speed*seconds);
	create_drive_straight(mm_speed);
	msleep((int)(seconds*1000));
	create_stop();
	#endif
	#ifdef CBC
	#endif
}

void drive(int speed)
{
	#ifdef CREATE
	create_drive_straight(speed);//mm/s
	#endif
	#ifdef CBC
	mav(motorL, speed);
	mav(motorR, speed);
	#endif
}

void driveAtMillimeters(float speed)
{
	#ifdef CREATE
	create_drive_straight(speed);
	
	#ifdef defined(DEBUG_MOVEMENT) || defined(DEBUG_ALL)
	printf("driveAtMillimeters(%d)\n",speed);
	printf("  request: (%3.2f, %3.2f) mm/s\n", speed);
	printf("  actual : (%5d, %5d) mm/s\n", stateOfCreate.lspeed, stateOfCreate.rspeed);
	#endif
	
	#endif
}
void driveAtInches(float speed)
{
	#ifdef CREATE
	float mm_speed = inchesToMillimeters(speed);
	create_drive_straight(mm_speed);
	
	#ifdef defined(DEBUG_MOVEMENT) || defined(DEBUG_ALL)
	printf("driveAtInches(%3.2f)\n",speed);
	printf("  request: (%3.2f, %3.2f) in/s\n", speed);
	printf("           (%3.2f, %3.2f) mm/s\n", mm_speed, mm_speed);
	printf("  actual : (%5d, %5d) mm/s\n", stateOfCreate.lspeed, stateOfCreate.rspeed);
	#endif
	
	#endif
}

void driveAtMillimetersFor(float speed, float seconds)
{
	driveAtMillimeters(speed);
	stopIn(seconds);
}
void driveAtInchesFor(float speed, float seconds)
{
	driveAtInches(speed);
	stopIn(seconds);
}


void driveAtMm(float speed){
	driveAtMillimeters(speed);
}
void driveAtIn(float speed){
	driveAtIn(speed);
}
void driveAtMmFor(float speed, float seconds){
	driveAtMillimetersFor(speed, seconds);
}
void driveAtInFor(float speed, float seconds){
	driveAtInchesFor(speed, seconds);
}

void stop()
{
	#ifdef CREATE
	create_stop();
	
	#ifdef defined(DEBUG_MOVEMENT) || defined(DEBUG_ALL)
	printf("stop()\tCREATE\n");
	printf("  request: (    0,     0) mm/s\n");  
	printf("  actual : (%5d, %5d) mm/s\n", stateOfCreate.lspeed, stateOfCreate.rspeed);
	#endif
	
	#endif
	#ifdef CBC
	freeze(motorR);
	freeze(motorL);
	#endif
}
void stopIn(float seconds)
{
	sleep(seconds);
	stop();
}


//Turn Functions
//I was rummaging through the provided program libraries to better understand how the functions they give us work
// and I found a provided turn function in "InstallationPath\targets\gcc\include\kiss-create-2011.h"
// -McGee
void turn(int speed, int angle)	//positive angle for CCW and negative angle for CW
{
	#ifdef CREATE
	//create_spin_block(speed, angle);
	create_spin_block( (int)(speed    ), (int)(.60*angle) );
	create_spin_block( (int)(speed*.5 ), (int)(.30*angle) );
	create_spin_block( (int)(speed*.25), (int)(.10*angle) );
	
	#endif
	X += angle;
}

void turnCW()
{
	create_drive(-101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn CCW");
	while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
	{
		//printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(10, -10);
			printf(" to CW");
			while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
			{
				sleep(0.1);
			}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -90)
		{
			create_drive_direct(-10, 10);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
			{
				sleep(0.1);
			}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
}


void turnCCW()
{
	create_drive(400,1);
	sleep(.375);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
	turnAdjust();
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
}

void turnAdjust()
{
	int adjust_speed = 10;
	int angle_offset = X - get_create_total_angle(0.1);
	
	if(angle_offset != 0)   create_spin_block(adjust_speed, angle_offset);
/*
	int adjust_speed = 10;
//	printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X != 0)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 0) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X !=0){}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 0)
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != 0){}
			create_stop();
		}
	}
//	printf("%d\n", get_create_total_angle(.1));
*/
}

//Miscellaneous
#ifdef	TOUCH_FRONT
void forwardTouch(int speed)
{
	drive(speed);
	while(!TOUCH_FRONT);
	create_stop();
}
#endif

#ifdef	TOUCH_FRONT
#ifdef	TOUCH_BACK
void clearWall()
{
	if(TOUCH_BACK)	 driveMm(-5,1);	//drive Cubelength + 5 mm safety fd
	if(TOUCH_FRONT)  driveMm(5,1);	//drive Cubelength + 5 mm safety bd
}
#endif
#endif

#ifdef DEF_SIDE
void turnForRight(int speed, int angle)	// if assuming create is on right side
{
	if(side==LEFT)   turn(speed,-angle);
	if(side==RIGHT)  turn(speed,angle);
}
void turnForLeft(int speed, int angle)	//if assuming create is on left side
{
	if(side==LEFT)   turn(speed,angle);
	if(side==RIGHT)  turn(speed,-angle);
}
#endif

#endif

//Experimental

int beepFor(int num_of_beeps)
{
	int i;
	for(i=0; i < num_of_beeps; i++)	beep();
	return (i+1);
}

#endif
