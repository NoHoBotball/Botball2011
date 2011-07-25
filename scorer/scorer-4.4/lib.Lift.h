// Lift - raises the first stack of towers.
// Code written by Ben Shukman.

#include "lib.Movement.h"
#include "lib.Scorer2011ArmClaw.h"

#ifndef  LIB_LIFT
#define  LIB_LIFT
/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/
/*Function prototypes below*/
void Lift();
void liftSetup();
void liftCheck(int i);
void prepareClaw();
void moveForward();
void positionClaw();
void grabTowers();
void liftArm();

/* Global variables go below (if you absolutely need them).*/


// Main:

void Lift() { 
//	liftSetup();	liftCheck(00);
	prepareClaw();	liftCheck(10);	// raise arm and open claw
	moveForward();	liftCheck(20);	// move forward till touch blocks
	positionClaw();	liftCheck(30);	// robot moves backwards + lowers arm until claw is correct distance
	grabTowers();	liftCheck(40);	// continuous rotation motor closes on blocks
	liftArm(); 		liftCheck(50);	// includes robot moving backwards to make space for tower lifting.
	
	// next step: robot goes back to starting box and puts blocks down.
}


// Functions:

void liftSetup()
{
	create_connect();
	mav(MOTOR_CLAW_PORT,100);
	sleep(1.0);
	freeze(MOTOR_CLAW_PORT);
//	ArmFastDown();
//	Release();
	set_servo_position(1,SERVO_MINI_DOWN);
}

void prepareClaw()
{
	armUp();
	mav(MOTOR_CLAW_PORT,100);
	sleep(1.0);
	off(MOTOR_CLAW_PORT);
}

void moveForward()
{
	// IRTest;  // IR sensor may be broken.  test values to make sure it is working.  make slowing down function (as it gets closer).
	forwardTouch(-240); // move forward until bump is hit.
}


void positionClaw()
{
	driveMm(CREATE_ARM_DIST, 1.0);  // move backward set distance (until arm can lower)
	armDownFast();
	release();
	driveMm(-75,1.3); // move forward set distance (until mini servo bracket hits block)
}

void grabTowers()
{
	grab();	// continuous rotation motor closes on blocks
}

void liftArm()
{
	driveMm(200, 1.0); // move backward set distance (until arm can raise while holding blocks)]
	armUp(); // lift arm
	sleep(.5);
}

void liftCheck(int i)
{
	switch (i)
	{
		case 00:
			printf("%d  setup complete\n",i);
			beep();
			break;
		case 10:
			printf("%d  claw preperation complete\n",i);
			beep();
			break;
		case 20:
			printf("%d  move forward complete\n",i);
			beep();
			break;
		case 30:
			printf("%d  claw positioning complete\n",i);
			beep();
			break;
		case 40:
			printf("%d  grabbing towers complete\n",i);
			beep();
			break;
		case 50:
			printf("%d  tower lifting complete\n",i);
			beep();
			break;
		default:
			beepFor(3);
			break;
	}
}

/*/ Sub-Functions:

int IRTest() 
{
	
}
/*/

#endif
