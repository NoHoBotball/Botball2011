//
// "ross.Config.h"
//
// Programmer:    Ross Mead
// Last modified: 31Jan2008
//

// preprocessor directives
#ifdef	 CREATE
#include "ross.Boolean.h"

#ifndef	 CREATE_CONFIG
#define	 CREATE_CONFIG
#include "config.Declarations.h"


// debug flag definition
// - DEBUG: enables/disables debugging mode
//#define DEBUG                  1


// robot definitions
// - ROBOT_DIAMETER: the measured diameter (in inches) of the robot
#define ARM_VERSION           2011
#define CLAW_VERSION          2011
#define DRIVE                 2

#define ROBOT_DIAMETER        10.375
#define CREATE_ARM_DIST       240			   //in mm, so Create can back off to optimum distance to cubes after touch sensor on bottom of Create activated
#define CREATE_DIAMETER       inToMm(10.375)
#define	CAMERA_OFF_CENTER     33

// wheel (differential drive) definitions
// - WHEEL_DIAMETER:        the measured diameter (in inches) of the wheel
// - WHEEL_OFFSET_DIAMETER: the measured distance (in inches) between the centers of the wheels
#define WHEEL_DIAMETER         2.625	//needs to filled with accurate values
#define WHEEL_OFFSET_DIAMETER  6.0		//needs to filled with accurate values

// motor definitions
// - MOTOR_MAX_SPEED:   the maximum speed of a motor
// - MOTOR_BRAKE_SLEEP: the time that the motor should sleep for braking
// - MOTOR_CLAW_PORT:   the motor used for the claw
// - MOTOR_CLAW_OPEN:   the open  claw motor position
// - MOTOR_CLAW_CLOSE:  the close claw motor position
#define MOTOR_MAX_SPEED        1000
//#define MOTOR_BRAKE_SLEEP      0.06	//needs to filled with accurate values
#define	MOTOR_CLAW_PORT        3
#define MOTOR_CLAW_OPEN		     0
#define MOTOR_CLAW_CLOSE       975








// light port defintions
// - LIGHT_PORT:          the port number of the "wait_for_light" sensor
#define LIGHT_PORT             7

// touch sensor port definitions
// - TOUCH_NUM:              the number of touch sensors being used
// - TOUCH_FRONT:            the front       touch sensor port
#define TOUCH_NUM              2
#define TOUCH_FRONT_PORT       15
#define TOUCH_CLAW_PORT        14

// servo definitions
// - SERVO_LEFT:       the servo on the left side that raises and lowers the arm
// - SERVO_RIGHT:      the servo on the right side that raises and lowers the arm
#define SERVO_ARM_LEFT_PORT		0
#define SERVO_ARM_RIGHT_PORT	3
#define SERVO_MINI_PORT			1
//servo positions
#define SERVO_ARM_LEFT_UP     1780
#define SERVO_ARM_LEFT_DOWN   460
#define SERVO_ARM_RIGHT_UP    280
#define SERVO_ARM_RIGHT_DOWN  1500	
#define STACK_VALUE           300
#define SERVO_MINI_UP         1200
#define SERVO_MINI_DOWN       120


#endif

// back-EMF definitions
// - ENABLE_BACK_EMF:  enables/disables back-EMF
// - enabledBackEMF(): returns TRUE if back-EMF is enabled, FALSE otherwise
#define ENABLE_BACK_EMF       1
BOOL enabledBackEMF()
{
    #ifdef ENABLE_BACK_EMF
      return TRUE;
    #endif
    return FALSE;
}   // enabledBackEMF()

// odometry definitions
// - TICKS_PER_REV:       the measured number of ticks per revolution (long integer)
// - TURN_90_SLEEP:       the amount of time to sleep (in seconds) for an approximate 90 degree turn
// - SLEEP_TIME_PER_INCH: the amount of time to sleep (in seconds) per an approximate inch
#define TICKS_PER_REV          1100L
//#define TURN_90_SLEEP          0.6125	//needs to filled with accurate values
//#define SLEEP_TIME_PER_INCH    (4.0 * TURN_90_SLEEP / (WHEEL_OFFSET_DIAMETER * PI))	//needs to filled with accurate values
#endif


