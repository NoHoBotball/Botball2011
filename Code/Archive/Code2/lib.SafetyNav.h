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
void safetyCheck();
void safetyCheck2();
void safetyCheck3();
void safetyCheck4();
void safetyCheck5();


// Main:

void SafetyNav() {
	//safetySetup();
	//safetyCheck();
	positionNav(); // move to middle of runway.
	safetyCheck2();
	CenterCamera(); // find blocks.
	safetyCheck3();
	safetyStack(); // stack blocks.
	safetyCheck4();
	moveToDefense(); // move to defensive position.
	safetyCheck5();
}


// Functions:

void safetySetup() {
	create_connect();
	enable_servos();
	create_start();
	create_full();
	// ArmUp();  // uncomment when testing stacking.
	// set_servo_position(1,120);
}

void positionNav() { // moves to middle of runway,
	//drivemm(175,.5);
	TurnRight();
	drivemm(-175, 2.5);
}

void safetyStack() { // stacks?stacks?stacks?stacks?stacks?stacks?
	ArmStack();
	mav(Claw, -400); // release tower.
	sleep(2);
	off(Claw);
}

void moveToDefense() { // moves to defensive position.
	//int process1;
	//int process2;
	
	drivemm(240,1.0);
	TurnRight();
	drivemm(175, 2.65); // must be centered with runway.
	TurnRight(); // turn towards runway.
	
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
	drivemm(240, 2); // moves towards runway.
	//cliffSensingProcess();
	
	//drivemm(-100,1.0); // moves create a tiny bit backwards.  this is the defensive position.
}

void armDownProcess(){
	ArmDown();
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

void safetyCheck() {
	printf("setup complete");
	beep();
}

void safetyCheck2() {
	printf("robot positioning complete");
	beep();
}

void safetyCheck3() {
	printf("'centerCamera' program complete");
	beep();
}

void safetyCheck4() {
	printf("tower stacking complete");
	beep();
}

void safetyCheck5() {
	printf("defensive positioning complete");
	beep();
}
