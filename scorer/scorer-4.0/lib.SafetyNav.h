// SafetyNav - moves robot with first tower blocks towards second block stack.
// (transitions into camera centering tower program).
// code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void SafetyNav();
void safetySetup();
void positionNav();
void safetyStack();
void moveToDefense();
void cliffSensingProcess();
void armDownProcess();
void safetyCheck(int i);


// Main:

void SafetyNav()
{
//	safetySetup();		safetyCheck(1);
	positionNav(); 		safetyCheck(2);	// move to middle of runway.
	CenterCamera(); 	safetyCheck(3);	// find blocks.		
	safetyStack();		safetyCheck(4); // stack blocks.
	moveToDefense();	safetyCheck(5); // move to defensive position.
}


// Functions:

void safetySetup() {
	create_connect();
	enable_servos();
	create_start();
	create_full();
	// armUp();  // uncomment when testing stacking.
	// set_servo_position(1,LowerMini);
}

void positionNav() { // moves to middle of runway,
	//drivemm(175,.5);
	turnRight();
	drivemm(-175, 2.5);
}

void safetyStack() { // stacks?stacks?stacks?stacks?stacks?stacks?
	armStack();
	mav(Claw, -400); // release tower.
	sleep(2);
	off(Claw);
}

void moveToDefense() { // moves to defensive position.
	//int process1;
	//int process2;
	
	drivemm(240,1.0);
	turnRight();
	drivemm(175, 2.65); // must be centered with runway.
	turnRight(); // turn towards runway.
	
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
	drivemm(240, 2); // moves towards runway.
	//cliffSensingProcess();
	
	//drivemm(-100,1.0); // moves create a tiny bit backwards.  this is the defensive position.
}

void armDownProcess(){
	armDown();
}

void cliffSensingProcess() {
	int speed = 175; // moves create forward until both front cliff sensors detect black.
	create_drive_straight(speed); 
	while (get_create_lfcliff(.1) == 0 && get_create_rfcliff(.1) == 0) { 
			printf("right sensor: %d. left sensor: %d. \n", get_create_rfcliff(.1), get_create_lfcliff(.1)); // not working.
	}
	printf("right sensor: %d. left sensor: %d\n", get_create_rfcliff(.1), get_create_lfcliff(.1)); // not working.
	create_stop();
}


void safetyCheck(int i)
{
	switch (i)
	{
		case 1:
			printf("setup complete\n");
			beep();
			break;
		case 2:
			printf("robot positioning complete\n");
			beep();
			break;
		case 3:
			printf("'centerCamera' program complete\n");
			beep();
			break;
		case 4:
			printf("tower stacking complete\n");
			beep();
			break;
		case 5:
			printf("defensive positioning complete\n");
			beep();
			break;
		default:
			beep();
			beep();
			beep();
			break;
	}
}
