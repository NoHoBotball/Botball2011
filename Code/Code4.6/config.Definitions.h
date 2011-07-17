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



#ifdef	 CREATE

#include "config.Create.h"
//#include "kiss-create-2011.h"

	//SENSORS - ANALOG
	#define LIGHT                analog10(LIGHT_PORT)
	#define TOUCH_CLAW           digital(TOUCH_CLAW_PORT)
	#define TOUCH_FRONT          digital(TOUCH_FRONT_PORT)	
	#define TOUCH_BACK_RIGHT     get_create_lbump(0.1)
	#define TOUCH_BACK_LEFT      get_create_rbump(0.1)
	#define TOUCH_RIGHT_BACK     get_create_lbump(0.1)
	#define TOUCH_LEFT_BACK      get_create_rbump(0.1)
	#define TOUCH_BACK_AND       (TOUCH_BACK_RIGHT && TOUCH_BACK_LEFT)
	#define TOUCH_BACK_OR        (TOUCH_BACK_RIGHT || TOUCH_BACK_LEFT)
	#define ET_FRONT			 analog10(ET_FRONT_PORT)
	#define IR_FRONT 			 analog10(IR_FRONT_PORT)
	
	#define SERVO_ARM_LEFT		get_servo_position(SERVO_ARM_LEFT_PORT)
	#define SERVO_ARM_RIGHT		get_servo_position(SERVO_ARM_RIGHT_PORT)
	#define SERVO_CLAW_LEFT		get_servo_position(SERVO_CLAW_LEFT_PORT)
	#define SERVO_CLAW_RIGHT	get_servo_position(SERVO_CLAW_RIGHT_PORT)
	
	#define CLAW              MOTOR_CLAW_PORT
	#define CLAW_OPEN         MOTOR_CLAW_OPEN
	#define CLAW_CLOSE        MOTOR_CLAW_CLOSE

	#define GRAB_DIST		inToMm(3.5)//4)//(9.5)
	#define STACK1_DIST		inToMm(7) //8.5
	#define	STACK2_DIST		inToMm(7)
	#define	STACK3_DIST		inToMm(3)
	
	#define SCOOT_GRAB		inToMm(-12)//-7.6)//7.7 //-7.25 //-6
	#define SCOOT_STACK1	inToMm(-5)//5) //4.25 -1.25

	#define	RUN_TIME     117
	#define DIRECTIONS   int
		#define	FRONT       0
		#define	RIGHT       1
		#define	BACK        2
		#define	LEFT        3
	#define	DROP        0	
	#define	STACK       1
	
	int strategyOrder;
	int gameStrategy;
	int tspeed = 200;
	int adjust_speed = 20;
	int side = -1;
	float run_time[10];
	int time_num = 0;
	unsigned short margin_of_error = 1;
	#define DEF_SIDE
#endif

#define  LIB_GENERAL_2011
//#include "config.Declarations.h"

	#include "ross.Metrics.h"
	#include "lib.arm.h"
	#include "lib.move.h"
	//#include "lib.Camera.h"
	#include "lib.RichardNav.c"
	#include "lib.seed.h"
	#include "lib.DE.h"
	#include "lib.DEStraight.h"
	#include "lib.Strategies.h"
	#include "lib.initialize.h"
	

#endif
