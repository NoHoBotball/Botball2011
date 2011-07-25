//Library -- Definitions
/*	
/	Description	:
/		-This File contains several Standard and Misc
/		 definitions and inclusions for the Botball Competition

/	Written and Maintained By:
/		-Joseph McGee	02/2011-
/	
*/
#ifndef DEFINITIONS
#define	DEFINITIONS

//BLACK IS DOWN ON MOTORS
#define  CUBE_LENGTH	    	inchesToMillimeters(4.0)



//ACD from middle position claw

#ifdef	 CREATE

#include "config.Create.h"

	//SENSORS - ANALOG
	#define LIGHT                analog(LIGHT_PORT)
    #define ET                   analog(4)
    #define TOUCH_CLAW           digital(TOUCH_CLAW_PORT)
	#define TOUCH_FRONT          digital(TOUCH_FRONT_PORT)	
	#define TOUCH_BACK_RIGHT     get_create_rbump(0.1)
	#define TOUCH_BACK_LEFT      get_create_lbump(0.1)
	#define TOUCH_RIGHT_BACK     get_create_rbump(0.1)
	#define TOUCH_LEFT_BACK      get_create_lbump(0.1)
	//#define TOUCH_LEFT_OR_RIGHT  (TOUCH_BACK_RIGHT || TOUCH_BACK_LEFT)
	#define TOUCH_BACK           (TOUCH_BACK_RIGHT || TOUCH_BACK_LEFT)
		
	#define CLAW              MOTOR_CLAW_PORT
	#define CLAW_OPEN         MOTOR_CLAW_OPEN
	#define CLAW_CLOSE        MOTOR_CLAW_CLOSE

	#define	RUN_TIME 	117
	#define DIRECTIONS
	#define	FRONT       0
	#define	RIGHT       1
	#define	BACK        2
	#define	LEFT        3
	#define	DROP        0	
	#define	STACK       1
	
	int tspeed = 200;	
	int side = 2;
	#define DEF_SIDE
#endif

#define  LIB_GENERAL_2011
#include "config.Declarations.h"

	#include "ross.Metrics.h"
	#include "lib.Movement.h"
	#include "lib.Camera.h"
	#include "lib.Scorer2011ArmClaw.h"
	
	#include "lib.Lift.h"
	#include "lib.SafetyNav.h"
	#include "lib.ScorerNav.h"
	#include "lib.ScorerStart.h"
	

#endif
