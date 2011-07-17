
// ScorerStart - initializes robot and all peripherals, then lifts first tower blocks.
// ends at lifting of first tower stack.
// code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/
int scorerStrategy;

/*Function prototypes below*/
void ScorerStart();
void initialize();
void initialPosition();
void whichSide();
void strategySelect();
//void countdown();


// Main:

void ScorerStart()
{
	initialize();
	printf("initialization complete");
	cbc_display_clear();
	if(scorerStrategy == 1)
	{
		printf("SCORER\n");
		if(Side == Right)	printf("RIGHT SIDE");
		if (Side == Left)	printf("LEFT SIDE");
	}
	if(scorerStrategy == 2)
	{
		printf("SAFETY\n");
		if(Side == Right)	printf("RIGHT SIDE");
		if(Side == Left)	printf("LEFT SIDE");
	}
	initialPosition(); // leaves sb + moves into position for CenterCamera.
	CenterCamera();
	Lift();
	if(scorerStrategy == 1)	ScorerNav();
	if(scorerStrategy == 2)	SafetyNav();
}


// Functions:

void initialize()
{
	printf("initializing. please wait.\n");
	
	//enable and position arm and claw
	enable_servos();	msleep(250);
	mav(Claw,100);		msleep(1000);	off(Claw);
	enableServoDown();	msleep(500);	release();
	printf("servos initalized.\n");
	
	
	//initialize create and sensors
	create_connect();
	create_full();
	set_create_total_angle(0);
	set_each_analog_state(0,0,0,1,0,0,0,0);
	printf("create initialized.\n");
	
	//select side and strategy
	whichSide();
	strategySelect();
	
	//draw claw and MiniServo back into starting box while waiting for light
	mav(Claw, -50);
	set_servo_position(MiniServo, RaiseMini);	// mini servo up.
	wait_for_light(LightPort);					// light port is #7.
	freeze(Claw);
	set_servo_position(MiniServo,LowerMini);	// mini servo down.
	shut_down_in(119);
//	start_process(*countdown);
}

void initialPosition() 
{
	drivemm(-500, CreateArmDist/500);// test values. leaves starting box, middle of boxes.
	turnRight();
	drivemm(-500, .75);//(500 * .75 =375) test values. moves forward tiny bit, transitions into CenterCamera
}

void whichSide()
{
	printf ("select orientation of the robot compared to botguy.\n(make sure camera is facing right way)\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (b_button() == 0 && a_button() == 0){}
	if (b_button())
	{
		Side = Right;
		cbc_display_clear();
		printf ("robot is on right of botguy.\n");
		msleep(500);
	}
	if (a_button())
	{
		Side = Left;
		cbc_display_clear();
		printf ("robot is on left of botguy.\n");
		msleep(500);
	}
}

void strategySelect()
{
	printf("please select a strategy.\n\n");
	printf("standard tower stack: press 'A'\nsafe tower stack: press 'B'\n\n");
	while (b_button() == 0 || a_button() == 0)
	{
		if (a_button())
		{
			printf("you have selected standard tower stacking.\n");
			scorerStrategy = 1;
			msleep(500);
			break;
		}
		if (b_button())
		{
			printf("you have selected safe tower stacking.\n");
			scorerStrategy = 2;
			msleep(500);
			break;
		}
	}
}
/*
void countdown()
{
	float timeBegin = seconds();
	while (120 - (seconds() - timeBegin) > 20){}
	printf("Shut down in:\n");
	while(1)
	{
		printf("%2.0f\t", (120 - (seconds() - timeBegin)));
		sleep(0.950);
	}
} */

	
