//Library -- Movement
//Movement Functions

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
/		TouchSensor and either Create 
/		or CBC, motorR, motorL 
/		in the file from which this funcition is called
*/

int X;//ideal turn correction factor

void drivemm(float mmspeed, float seconds);//speed is mm/s
void drivein(float inspeed, float seconds);//speed is in/s
void drive(int speed);
void stop();
void turnCCW();
void turnCW();
void turnCCWFinal();
void turnCCWFinal();
void turnAdjust();
void turnAdjustSlow();
void spinCCW(int speed);
void spinCW(int speed);
void turnCCW180();
void turnCW180();
void forwardTouch();
void clearWall();

void turnLeft();//treat as if turning left on right side (on left side everything is reversed)
void turnRight();//treat as if turning right on right side (on left side everything is reversed)
void turnRightFinal();
void turnLeftFinal();
void turnHalfLeft();
void turnHalfRight();

//Drive Straight Functions
void drivemm(float mmspeed, float seconds)//speed is mm/s
{
	#ifdef CREATE
	create_drive_straight(mmspeed);
	msleep(seconds*1000);
	create_stop();
	printf("%d mm/s * %d seconds = %d mm.\n", mmspeed, seconds, mmspeed*seconds);
	#endif
	#ifdef CBC
	mav(motorR,mmspeed);//doesn't actually go at 'mmspeed' mm/s
	mav(motorL,mmspeed);
	sleep(seconds);
	freeze(motorR);
	freeze(motorL);
	#endif
	
}


void drivein(float inspeed, float seconds)//speed is in/s
{
	#ifdef CREATE
	int mmspeed;
	mmspeed = inchestomm(inspeed);
	printf("%f in/s = %f mm/s \n", inspeed, inchestomm(inspeed));
	printf("%d mm/s * %f seconds = %f mm.\n", mmspeed, seconds, mmspeed*seconds);
	create_drive_straight(mmspeed);
	msleep(seconds*1000);
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

void stop()
{
	#ifdef CREATE
	create_stop();
	#endif
	#ifdef CBC
	freeze(motorR);
	freeze(motorL);
	#endif
}


//Turn Functions
void turnCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
	//printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X < 89 || get_create_total_angle(.1)-X > 91)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X < 89 || get_create_total_angle(.1)-X > 91)
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 90)
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X < 89 || get_create_total_angle(.1)-X > 91)
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+90;
	turnAdjust();
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}

void turnCW()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
	//printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -90)
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X > -89 || get_create_total_angle(.1)-X < -91)
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
	turnAdjust();
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
	#endif
}

void turnCCWFinal()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
	//printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X < 87 || get_create_total_angle(.1)-X > 89)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 88) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X < 87 || get_create_total_angle(.1)-X > 89)
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 88)
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X < 87 || get_create_total_angle(.1)-X > 89)
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	X=X+90;
	turnAdjust();
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}

void turnCWFinal()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
	//printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X > -87 || get_create_total_angle(.1)-X < -89)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -88) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X > -87 || get_create_total_angle(.1)-X < -89)
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -88)
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X > -87 || get_create_total_angle(.1)-X < -89)
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
	turnAdjust();
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
	#endif
}

void turnHalfCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	sleep(1.028626157);
	create_stop();
	printf("Initial Half Turn CCW");
	int adjust_speed = 10;
//	printf("\n%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X < 44 || get_create_total_angle(.1)-X > 46)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 45) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X != 45);
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 45)
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != 45);
			{}
			create_stop();
		}
	}
//	printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+45;
	turnAdjust();
	#endif
} 

void turnHalfCW()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	sleep(1.028626157);
	create_stop();
	printf("Initial Turn CCW");
	int adjust_speed = 10;
//	printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X > -44 || get_create_total_angle(.1)-X < -46)
	{
		
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -45) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != -45);
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -45)
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X != -45);
			{}
			create_stop();
		}
	}
//	printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-45;
	turnAdjust();
	#endif
	
}


void turnAdjust()
{
	int adjust_speed = 10;
//	printf("%d\n", get_create_total_angle(.1));
	while (get_create_total_angle(.1)-X != 0)//< -1 || get_create_total_angle(.1)-X > 1)
	{
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 0) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-adjust_speed, adjust_speed);
			printf(" to CW");
			while (get_create_total_angle(.1)-X !=0)
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 0)
		{
			create_drive_direct(adjust_speed, -adjust_speed);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != 0)
			{}
			create_stop();
		}
	}
//	printf("%d\n", get_create_total_angle(.1));
}


void spinCCW(int speed)
{
	#ifdef CREATE			//for CREATE speed is in mm/CreateDiameter rads/s
	create_spin_CCW(speed);  
	#endif
	#ifdef CBC				//for CBC speed is in ticks/WheelSpan rads/s
	#endif
}

void spinCW(int speed)
{
	#ifdef CREATE			//for CREATE speed is in mm/CreateDiameter rads/s
	create_spin_CW(speed);  
	#endif
	#ifdef CBC				//for CBC speed is in ticks/WheelSpan rads/s
	#endif
}

void turnCW180()
{
	turnCW();
	turnCW();
}

void turnCCW180()
{
	turnCCW();
	turnCCW();
}

//Miscellaneous
#ifdef	TouchSensor
void forwardTouch (int speed)
{
	drive(speed);
	while (digital(TouchSensor) == 0)
	{}
	create_stop();
}
#endif

#ifdef	CREATE
#ifdef	TouchSensor
void clearWall()
{
	if(get_create_lbump(.1) || get_create_rbump(.1))
	{
		drivemm(-(CubeLength + 5),1);	//drive Cubelength + 5 mm safety fd
	}
	if(digital(TouchSensor) == 1)
	{
		drivemm((CubeLength + 5),1);	//drive Cubelength + 5 mm safety bd
	}
}
#endif
#endif

#ifdef DefSide
void turnLeft()//treat as if turning left on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnCCW();
	if (Side == Left)
	turnCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void turnRight()//treat as if turning right on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnCW();
	if (Side == Left)
	turnCCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}



void turnLeftFinal()//treat as if turning left on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnCCWFinal();
	if (Side == Left)
	turnCWFinal();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void turnRightFinal()//treat as if turning right on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnCWFinal();
	if (Side == Left)
	turnCCWFinal();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void turnHalfLeft()//treat as if turning left on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnHalfCCW();
	if (Side == Left)
	turnHalfCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void turnHalfRight()//treat as if turning right on right side (on left side everything is reversed)
{
	if (Side == Right)
	turnHalfCW();
	if (Side == Left)
	turnHalfCCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

#endif

//Experimental
