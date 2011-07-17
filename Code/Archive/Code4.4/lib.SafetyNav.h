// SafetyNav - moves robot with first tower blocks towards second block stack.
// (transitions into camera centering tower program).
// code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/
#include "lib.Movement.h"
#include "lib.Camera.h"
#include "lib.Scorer2011ArmClaw.h"

#ifndef  LIB_SAFETY_NAV
#define  LIB_SAFETY_NAV
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
//	safetySetup();		safetyCheck(00);
	positionNav(); 		safetyCheck(10);	// move to middle of runway.
	CenterCamera(); 	safetyCheck(20);	// find blocks.		
	safetyStack();		safetyCheck(30); // stack blocks.
	moveToDefense();	safetyCheck(40); // move to defensive position.
}

// Functions:

void safetySetup() {
	create_connect();
	enable_servos();
	set_servo_position(SERVO_MINI_PORT,SERVO_MINI_DOWN);
}

void positionNav() // moves to middle of runway,
{
//	drivemm(500,.175);(500*.175=87.5)
	turnForRight(tspeed,-90);
	driveMm(-500, 0.875);
}

void safetyStack() // stacks?stacks?stacks?stacks?stacks?stacks?
{
	armStack();
	mav(CLAW, -400); // release tower.
	msleep(2000);
	off(CLAW);
}

void moveToDefense() // moves to defensive position.
{
//	int process1, process2;
	
	driveMm(500, CREATE_ARM_DIST/500.0);//(500 * .48 = 240)
	turnForRight(tspeed,-90);					//turn towards ballcup
	driveMm(500, 0.9275);		//(500*.9275=463.75) must be centered with runway.
	turnForRight(tspeed,-90);					// turn towards runway.
	
	set_servo_position (SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN);
	set_servo_position (SERVO_ARM_RIGHT_PORT, SERVO_ARM_LEFT_DOWN);
	driveMm(500, 0.96); // moves towards runway.
//	cliffSensingProcess();
	
//	drivemm(-100,1.0); // moves create a tiny bit backwards.  this is the defensive position.
}

void cliffSensingProcess()
{
	int speed = 175; // moves create forward until both front cliff sensors detect black.
	create_drive_straight(speed); 
	while (!get_create_lfcliff(.1) && !get_create_rfcliff(.1))
	printf("right sensor: %d. left sensor: %d.\n", get_create_rfcliff(.1), get_create_lfcliff(.1)); // not working.
	printf("right sensor: %d. left sensor: %d.\n", get_create_rfcliff(.1), get_create_lfcliff(.1)); // not working.
	create_stop();
}


void safetyCheck(int i)
{
	switch (i)
	{
		case 00:
			printf("setup complete\n");
			beep();
			break;
		case 10:
			printf("robot positioning complete\n");
			beep();
			break;
		case 20:
			printf("'centerCamera' program complete\n");
			beep();
			break;
		case 30:
			printf("tower stacking complete\n");
			beep();
			break;
		case 40:
			printf("defensive positioning complete\n");
			beep();
			break;
		default:
			beepFor(3);
			break;
	}
}

#endif
