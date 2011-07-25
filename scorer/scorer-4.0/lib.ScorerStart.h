
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

void ScorerStart() {
	initialize();
	printf("initialization complete");
	cbc_display_clear();
	if(scorerStrategy == 1) {
		printf("SCORER\n");
		if(Side == Right) {
			printf("RIGHT SIDE");
		} else if (Side == Left) {
			printf("LEFT SIDE");
		}
	}
	if(scorerStrategy == 2) {
		printf("SAFETY\n");
		if(Side == Right) {
			printf("RIGHT SIDE");
		} else if (Side == Left) {
			printf("LEFT SIDE");
		}
	}
	initialPosition(); // leaves sb + moves into position for CenterCamera.
	CenterCamera();
	Lift();
	if(scorerStrategy == 1) {
		ScorerNav();
	}
	if(scorerStrategy == 2) {
		SafetyNav();
	}
}


// Functions:

void initialize() {
	printf("initializing. please wait.\n");
	enable_servos();
	sleep(.25);
	mav(Claw,100);
	sleep(1.0);
	off(Claw);
	enableServoDown();
	sleep(.5);
	release();
	set_servo_position(MiniServo, RaiseMini); // mini servo up.
	printf("servos initalized.\n");
	
	create_connect();
	create_full();
	set_create_total_angle(0);
	set_each_analog_state(0,0,0,1,0,0,0,0);
	printf("create initialized.\n");
	
	whichSide();
	strategySelect();
	mav(Claw, -50);
	wait_for_light(LightPort);  // light port is #7.
	freeze(Claw);
	shut_down_in(119);
	//start_process(*countdown);
	set_servo_position(MiniServo,LowerMini); // mini servo down.
	
	
}

void initialPosition() {
	turnHalfLeft();
	drivemm(-240, 1); // test value.  leaves starting box, middle of boxes.
	turnRight();
	drivemm(-375, 1); // test values. moves forward tiny bit, transitions in CenterCamera();
}

void whichSide() {
	printf ("select orientation of the robot compared to botguy.\n(make sure camera is facing right way)\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (b_button() == 0 && a_button() == 0){
	}
	if (b_button()){
		Side = Right;
		cbc_display_clear();
		printf ("robot is on right of botguy.\n");
		sleep(1);
	}
	if (a_button()){
		Side = Left;
		cbc_display_clear();
		printf ("robot is on left of botguy.\n");
		sleep(1);
	}
}

void strategySelect() {
	printf("please select a strategy.\n\n");
	printf("standard tower stack: press 'A'\nsafe tower stack: press 'B'\n\n");
	while (b_button() == 0 || a_button() == 0) {
		if (a_button() == 1) {
			printf("you have selected standard tower stacking.\n");
			scorerStrategy = 1;
			sleep(1);
			break;
		}
		if (b_button() == 1) {
			printf("you have selected safe tower stacking.\n");
			scorerStrategy = 2;
			sleep(1);
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

	
