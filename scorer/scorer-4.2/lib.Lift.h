// Lift - raises the first stack of towers.
// Code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/
#define BackOff 		inchestomm(3.25)  	//inches (from lowered claw to raised claw)
#define CreateArmDist	240					//mm
/*Function prototypes below*/
void Lift();
void setup();
void liftCheck(int i);
void moveForward();
void positionClaw();
void grabTowers();
void liftArm();

/* Global variables go below (if you absolutely need them).*/


// Main:

void Lift() { 
	//setup();
	//check();
	armUp();
	mav(Claw,100);
	sleep(1.0);
	off(Claw);
	moveForward();	liftCheck(2);
	positionClaw();	liftCheck(3);	// robot moves backwards + lowers arm until claw is correct distance
	grabTowers();	liftCheck(4);	// continuous rotation motor closes on blocks
	liftArm(); 		liftCheck(5);	// includes robot moving backwards to make space for tower lifting.
	
	// next step: robot goes back to starting box and puts blocks down.
}


// Functions:

void setup() {
	mav(Claw,100);
	sleep(1.0);
	freeze(Claw);
	//ArmFastDown();
	//Release();
	create_connect();
	create_full();
	set_servo_position(1,120);
	
}

void liftCheck(int i)
{
	switch (i)
	{
		case 1:
			printf("setup complete\n");
			beep();
			break;
		case 2:
			printf("move forward complete\n");
			beep();
			break;
		case 3:
			printf("claw positioning complete\n");
			beep();
			break;
		case 4:
			printf("grabbing towers complete\n");
			beep();
			break;
		case 5:
			printf("tower lifting complete\n");
			beep();
			break;
		default:
			beep();
			beep();
			beep();
			break;
	}
}


void moveForward()
{
	// IRTest;  // IR sensor may be broken.  test values to make sure it is working.  make slowing down function (as it gets closer).
	forwardTouch(-240); // move forward until bump is hit.
}


void positionClaw()
{
	drivemm(CreateArmDist, 1.0);  // move backward set distance (until arm can lower)
	armDownFast();
	release();
	drivemm(-75,1.3); // move forward set distance (until mini servo bracket hits block)
}

void grabTowers()
{
	grab();	// continuous rotation motor closes on blocks
}

void liftArm()
{
	drivemm(200, 1.0); // move backward set distance (until arm can raise while holding blocks)]
	armUp(); // lift arm
	sleep(.5);
}


// Sub-Functions:

int IRTest() 
{
	
}
