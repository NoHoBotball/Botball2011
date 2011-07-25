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
/		-Trevor Calhoun	02/2011-
/		-Trevor	Frese	02/2011-
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
void TurnCCW();
void TurnCW();
void turnAdjustCW();
void turnAdjustCCW();
void spinCCW(int speed);
void spinCW(int speed);
void turnCCW180();
void turnCW180();
void ForwardTouch ();
void ClearWall();
void TurnLeft();//treat as if turning left on right side (on left side everything is reversed)
void TurnRight();//treat as if turning right on right side (on left side everything is reversed)
void turnHalfRight();
void turnHalfLeft();

void turnCCW_McGee();
void turnCW_McGee();

//Drive Straight Functions
void drivemm(float mmspeed, float seconds)//speed is mm/s
{
	#ifdef CREATE
	create_drive_straight(mmspeed);
	sleep(seconds);
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
	sleep(seconds);
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
/*
void TurnCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn CCW");
	while (get_create_total_angle(.1)-X < 89 || get_create_total_angle(.1)-X > 91)
	{
		printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 90) //CCW ADDS TO TOTAL ANGLE
		{
			int pid = start_process(*turnAdjustCW);
			printf(" to CW");
			while (get_create_total_angle(.1)-X != 90);
			{}
			kill_process(pid);
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 90)
		{
			int pid = start_process(*turnAdjustCCW);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != 90);
			{}
			kill_process(pid);
			create_stop();
		}
	}
	printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+90;
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}
*/

void TurnCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	#endif
	printf("Initial Turn CCW");
	while (get_create_total_angle(.15)-X < 89 || get_create_total_angle(.15)-X > 91)
	{
		//printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(25, -25);
			printf(" to CW");
			while (get_create_total_angle(.15)-X < 89 || get_create_total_angle(.15)-X > 91)
			{
				sleep(.1);
			}
			create_stop();
		}
		
		
		if (get_create_total_angle(.15)-X < 89 || get_create_total_angle(.15)-X > 91)
		{
			create_drive_direct(-25, 25);
			printf(" to CCW");
			while (get_create_total_angle(.15)-X != 90);
			{
				sleep(0.1);
			}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+90;
	
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}

void TurnCW()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int i;
	for (i = 0; (i < 2) && (get_create_total_angle(.15)-X > -89 || get_create_total_angle(.15)-X < -91); i++)
	{
		//printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(25, -25);
			printf(" to CW");
			(get_create_total_angle(.15)-X < 89 || get_create_total_angle(.15)-X > 91);
			{
				sleep(0.1);
			}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -90)
		{
			create_drive_direct(-25, 25);
			printf(" to CCW");
			(get_create_total_angle(.15)-X < 89 || get_create_total_angle(.15)-X > 91);
			{
				sleep(0.1);
			}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
	#endif
	/*
	#ifdef	CREATE
	set_create_total_angle(0);
	create_drive(-101.3,1); 
	sleep(2.057252314);
	create_stop();
	get_create_total_angle(.01);
	printf("Initial Turn CW");
	if (get_create_total_angle(.1) != 90)
	{
	set_create_total_angle(get_create_total_angle(.1) + 90);
	printf("Adjusting");
	if (get_create_total_angle(.1) > 0) //CCW ADDS TO TOTAL ANGLE
	{
	spinCW(50);
	while (get_create_total_angle(.1) < 0);
	{
	printf(" to CW");
	}
	create_stop();
	}
	if (get_create_total_angle(.1) < 0)
	{
	spinCCW(50);
	while (get_create_total_angle(.1) > 0);
	{
	printf(" to CCW");
	}
	create_stop();
	}
	if (get_create_total_angle(.1) == 0)
	{
	printf(" Not needed");
	}
	create_stop();
	printf("%d\n", get_create_total_angle(.1));
	}
	create_stop();
	#endif*/
	#ifdef	CBC
	int tspeed;
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
	#endif
}

void turnAdjustCW()
{
	create_drive_direct(10, -10);
}

void turnAdjustCCW()
{
	create_drive_direct(-10, 10);
}


void turnHalfCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(1.028626157);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn CCW");
	while (get_create_total_angle(.1)-X < 44 || get_create_total_angle(.1)-X > 46)
	{
		printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X > 45) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(-10, 10);
			printf(" to CW");
			while (get_create_total_angle(.1)-X != 45);
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X < 45)
		{
			create_drive_direct(10, -10);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != 45);
			{}
			create_stop();
		}
	}
	printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+45;	
	#endif
} 

void turnHalfCW()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(1.028626157);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn CCW");
	while (get_create_total_angle(.1)-X > -44 || get_create_total_angle(.1)-X < -46)
	{
		printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.1)-X < -45) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(10, -10);
			printf(" to CW");
			while (get_create_total_angle(.1)-X != -45);
			{}
			create_stop();
		}
		if (get_create_total_angle(.1)-X > -45)
		{
			create_drive_direct(-10, 10);
			printf(" to CCW");
			while (get_create_total_angle(.1)-X != -45);
			{}
			create_stop();
		}
	}
	printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-45;
	#endif
	
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
	TurnCW();
	TurnCW();
}

void turnCCW180()
{
	TurnCCW();
	TurnCCW();
}

//Miscellaneous
#ifdef	TouchSensor
void ForwardTouch (int speed)
{
	drive(speed);
	while (digital(TouchSensor) == 0)
	{}
	create_stop();
}
#endif

#ifdef	CREATE
#ifdef	TouchSensor
void ClearWall()
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

void turnHalfLeft()
{
	if (Side == Right)
	{
		turnHalfCCW();
	}
	if (Side == Left)
	{
		turnHalfCW();
	}
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}
void TurnLeft()//treat as if turning left on right side (on left side everything is reversed)
{
	if (Side == Right)
	TurnCCW();
	if (Side == Left)
	TurnCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void turnHalfRight()
{
	if (Side == Right)
	{
		turnHalfCW();
	}
	if (Side == Left)
	{
		turnHalfCCW();
	}
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void TurnRight()//treat as if turning right on right side (on left side everything is reversed)
{
	if (Side == Right)
	TurnCW();
	if (Side == Left)
	TurnCCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}
#endif
//Experimental

void turnCCW_McGee()
{
	#ifdef	CREATE
	set_create_total_angle(0);
	create_drive(101.3,1); 
	sleep(2.057252314);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn");
	while (get_create_total_angle(.1) != 90)
	{
		int current_angle = (get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (current_angle > 0) //CCW ADDS TO TOTAL ANGLE
		{
			spinCW(50);
			while (get_create_total_angle(.1) > 0);
			{
				printf(" to CW\n");
			}
		}
		if (current_angle < 0)
		{
			spinCCW(50);
			while (get_create_total_angle(.1) < 0);
			{
				printf(" to CCW\n");
			}
		}
		create_stop();
	}
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}

void turnCW_McGee()
{
	#ifdef	CREATE
	set_create_total_angle(0);
	create_drive(-101.3,1); 
	sleep(2.057252314);
	create_stop();
	get_create_total_angle(.1);
	printf("Initial Turn");
	while (get_create_total_angle(.1) != 90)
	{
		int current_angle = (get_create_total_angle(.1) + 90);
		printf("Adjusting");
		if (current_angle < 0)
		{
			spinCW(50);
			while (get_create_total_angle(.1) < 0);
			{
				printf(" to CW\n");
			}
		}
		if (current_angle > 0) //CCW ADDS TO TOTAL ANGLE
		{
			spinCCW(50);
			while (get_create_total_angle(.1) > 0);
			{
				printf(" to CCW\n");
			}
		}
		create_stop();
	}
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
	#endif
}
