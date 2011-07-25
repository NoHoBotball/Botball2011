// Lift - raises the first stack of towers.
// Code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/
#define BackOff 		inchestomm(3.25)  //inches (from lowered claw to raised claw)

/*Function prototypes below*/
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
	//setup();
	//check();
	ArmUp();
	mav(3,100);
	sleep(1.0);
	off(3);
	moveForward();
	check2();
	positionClaw(); // robot moves backwards + lowers arm until claw is correct distance
	check3();
	grabTowers();
	check4();
	liftArm(); // include robot moving backwards to make space for tower lifting.
	check5();
	// next step: robot goes back to starting box and puts blocks down.
}


// Functions:

void setup() {
	mav(3,100);
	sleep(1.0);
	off(3);
	//ArmFastDown();
	//Release();
	create_start();
	create_full();
	set_servo_position(1,120);
	
}

void check(){
	printf("setup complete\n");
	beep();
}

void check2(){
	printf("move forward complete\n");
	beep();
}

void check3()
{
	printf("claw positioning complete\n");
	beep();
}

void check4()
{
	printf("grabbing towers complete\n");
	beep();
}

void check5()
{
	printf("tower lifting complete\n");
	beep();
}


void moveForward()
{
	// IRTest;  // IR sensor may be broken.  test values to make sure it is working.  make slowing down function (as it gets closer).
	forwardTouchTest(); // move forward until bump is hit.
}


void positionClaw()
{
	drivemm(240, 1.0);  // move backward set distance (until arm can lower)
	ArmDownFast();
	Release();
	drivemm(-75,1.3); // move forward set distance (until mini servo bracket hits block)
}

void grabTowers()
{
	Grab(); // continuous rotation motor closes on blocks.
}

void liftArm()
{
	drivemm(200, 1.0); // move backward set distance (until arm can raise while holding blocks)]
	ArmUp(); // lift arm
	sleep(.5);
}


// Sub-Functions:

int IRTest() 
{
	
}

void forwardTouchTest() 
{
	int speed = -240;   // good value for now - may change later.
	create_drive_straight(speed); 
	while (digital(15) == 0)
	{
		
	}
	create_stop();
}


