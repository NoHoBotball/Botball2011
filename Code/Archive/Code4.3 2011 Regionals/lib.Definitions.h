//Library -- Definitions
/*	
/	Description	:
/		-This File contains several Standard and Misc
/		 definitions and inclusions for the Botball Competition

/	Written and Maintained By:
/		-Joseph McGee	02/2011-
/	
*/
#ifndef LIB_DEFINITIONS
#define	DEFINITIONS

#ifndef	LIB_CONVERSIONS
#include "lib.Conversions.h"
#endif
//BLACK IS DOWN ON MOTORS

//Arm is 13 inches
#define CubeLength	    inchestomm(4)
#define CreateArmDist	240			   //in mm, so Create can back off to optimum distance to cubes after touch sensor on bottom of Create activated
#define CreateDiameter	inchestomm(10.375)
#define	CameraOffCenter 33

//ACD from middle position claw

int beepFor(int num_of_beeps);
int beepFor(int num_of_beeps)
{
	int i;
	for(i=0; i < num_of_beeps; i++)	beep();
	return (i+1);
}


#ifdef	CREATE

	
	#define LightPort 7		//SENSORS
	#define TouchSensor 15	
	#define ClawTouch 14
	#define ET 4
	#define CameraR			//camera is facing right with respect to Create
	#define StackValue 300

	#define Claw 3
	#define ClawOpen 0
	#define ClawClose 975

	#define ArmServo1 0
	#define RaiseArm1 1780
	#define LowerArm1 460

	#define ArmServo2 3
	#define RaiseArm2 280
	#define LowerArm2 1500

	#define MiniServo 1
	#define RaiseMini 1200
	#define LowerMini 120


	#define	RunTime 117
	#ifndef	DIRECTIONS
		#define DIRECTIONS
		#define	Front 0
		#define	Right 1
		#define	Back 2
		#define	Left 3
	#endif
	#define	Drop 0
	#define	Stack 1
	
	int tspeed = 200;	
	char side = 2;
	#define DEF_SIDE
	
	
	#include "lib.Movement.h"
	#include "lib.Camera.h"
	#include "lib.Scorer2011ArmClaw.h"
	#include "lib.Lift.h"
	#include "lib.SafetyNav.h"
	#include "lib.ScorerNav.h"
//	#include "lib.Scorer2011Game.h"
	#include "lib.ScorerStart.h"
	

#endif


#endif
