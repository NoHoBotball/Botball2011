// Lift - raises the first stack of towers.
// Code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/
void Lift();
void setup();
void check();
void check2();
void check3();
void check4();
void check5();
void moveForward();
void forwardTouchTest();
void positionClaw();
void grabTowers();
void liftArm();

/* Global variables go below (if you absolutely need them).*/


// Main:

void Lift() { 
	setup(); // only temp. comment out when 'Lift' is added to rest of program.
	check();
	moveForward();
	check2();
	positionClaw(); // robot moves backwards + lowers arm until claw is correct distance
	check3();
	/*grabTowers();
	check4();
	liftArm(); // include robot moving backwards to make space for tower lifting.
	check5();*/
	// next step: robot goes back to starting box and puts blocks down.
}


// Functions:

void setup() {
	create_connect();
	enable_servos();
	create_start();
	create_safe();
	ArmUp();
}

void check(){
	printf("setup complete\n");
}

void check2(){
	printf("move forward complete\n");
}

void check3(){
	printf("claw positioning complete\n");
}

void check4(){
	printf("grabbing towers complete\n");
}

void check5(){
	printf("tower lifting complete\n");
}


void moveForward() {
	// IRTest;  // IR sensor may be broken.  test values to make sure it is working.  make slowing down function (as it gets closer).
	forwardTouchTest(); // move forward until bump is hit.
}


void positionClaw() {
	drivemm(50,1); // move backward set distance (until arm can lower)
	ArmDown();
	drivemm(-50,1); // move forward set distance (until mini servo bracket hits block)
}

void grabTowers() {
	Grab(); // continuous rotation motor closes on blocks.
}

void liftArm() {
	drivemm(50,1);	// move backward set distance (until arm can raise while holding blocks)]
	ArmUp(); // lift arm
}


// Sub-Functions:

int IRTest() {
}

void forwardTouchTest() {
	int speed = -50;
	create_drive_straight(speed); 
	while (digital(TouchSensor) == 0) {
	}
	create_stop();
}


