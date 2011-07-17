//
// "ross.Config.h"
//
// Programmer:    Ross Mead
// Last modified: 31Jan2008
//

// preprocessor directives
#include "ross.Boolean.h"

#ifndef	 ROSS_CONFIG_OPEN
#define	 ROSS_CONFIG_OPEN
#include "ross.Declarations.h"


// debug flag definition
// - DEBUG: enables/disables debugging mode
//#define DEBUG                  1



// robot definitions
// - ROBOT_DIAMETER: the measured diameter (in inches) of the robot
#define ROBOT_DIAMETER 7.5



// motor definitions
// - MOTOR_MAX_SPEED:   the maximum speed of a motor
// - MOTOR_BRAKE_SLEEP: the time that the motor should sleep for braking
// - MOTOR_L0_PORT:     primary   left  motor port
// - MOTOR_L1_PORT:     secondary left  motor port
// - MOTOR_R0_PORT:     primary   right motor port
// - MOTOR_R1_PORT:     secondary right motor port
#define MOTOR_MAX_SPEED        1000
//#define MOTOR_BRAKE_SLEEP      0.06
#define MOTOR_L0_PORT          2
//#define MOTOR_L1_PORT          3
#define MOTOR_R0_PORT          0
//#define MOTOR_R1_PORT          1



// wheel (differential drive) definitions
// - WHEEL_DIAMETER:        the measured diameter (in inches) of the wheel
// - WHEEL_OFFSET_DIAMETER: the measured distance (in inches) between the centers of the wheels
#define WHEEL_DIAMETER         2.625
#define WHEEL_OFFSET_DIAMETER  6.0



// back-EMF definitions
// - ENABLE_BACK_EMF:  enables/disables back-EMF
// - enabledBackEMF(): returns TRUE if back-EMF is enabled, FALSE otherwise
#define ENABLE_BACK_EMF        1
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
#define TICKS_PER_REV          1290L
//#define TURN_90_SLEEP          0.6125
//#define SLEEP_TIME_PER_INCH    (4.0 * TURN_90_SLEEP / (WHEEL_OFFSET_DIAMETER * PI))



// infrared (IR) rangefinder port definitions
// - IR_NUM:              the number of IR sensors being used
// - IR_MIN_PORT:         the minimum     IR port
// - IR_MAX_PORT:         the maximum     IR port
// - IR_FRONT_PORT:       the front       IR port
// - IR_LEFT_PORT:        the left        IR port
// - IR_RIGHT_PORT:       the right       IR port
// - IR_REAR_PORT:        the rear        IR port
// - IR_FRONT_LEFT_PORT:  the front left  IR port
// - IR_FRONT_RIGHT_PORT: the front right IR port
// - IR_LEFT_FRONT_PORT:  the left  front IR port
// - IR_LEFT_REAR_PORT:   the left  rear  IR port
// - IR_RIGHT_FRONT_PORT: the right front IR port
// - IR_RIGHT_REAR_PORT:  the right rear  IR port
// - IR_REAR_LEFT_PORT:   the rear  left  IR port
// - IR_REAR_RIGHT_PORT:  the rear  right IR port
//#define IR_NUM                 6
//#define IR_MIN_PORT            0
//#define IR_MAX_PORT            6
//#define IR_FRONT_PORT          0
//#define IR_LEFT_PORT           3
//#define IR_RIGHT_PORT          2
//#define IR_REAR_PORT           6
//#define IR_FRONT_LEFT_PORT     1
//#define IR_FRONT_RIGHT_PORT    0
//#define IR_LEFT_FRONT_PORT     3
//#define IR_LEFT_REAR_PORT      5
//#define IR_RIGHT_FRONT_PORT    2
//#define IR_RIGHT_REAR_PORT     4
//#define IR_REAR_LEFT_PORT      5
//#define IR_REAR_RIGHT_PORT     4



// sonar port definitions
// - SONAR_NUM:        the number of sonar sensors being used
// - SONAR_FRONT_PORT: the front sonar port
// - SONAR_LEFT_PORT:  the left  sonar port
// - SONAR_RIGHT_PORT: the right sonar port
// - SONAR_REAR_PORT:  the rear  sonar port
//#define SONAR_NUM              1
//#define SONAR_FRONT_PORT       8
//#define SONAR_LEFT_PORT        9
//#define SONAR_RIGHT_PORT       10
//#define SONAR_REAR_PORT        11



// touch sensor port definitions
// - TOUCH_NUM:              the number of touch sensors being used
// - TOUCH_FRONT:            the front       touch sensor port
// - TOUCH_LEFT:             the left        touch sensor port
// - TOUCH_RIGHT:            the right       touch sensor port
// - TOUCH_REAR:             the rear        touch sensor port
// - TOUCH_FRONT_LEFT_PORT:  the front left  touch sensor port
// - TOUCH_FRONT_RIGHT_PORT: the front right touch sensor port
// - TOUCH_LEFT_FRONT_PORT:  the left  front touch sensor port
// - TOUCH_LEFT_REAR_PORT:   the left  rear  touch sensor port
// - TOUCH_RIGHT_FRONT_PORT: the right front touch sensor port
// - TOUCH_RIGHT_REAR_PORT:  the right rear  touch sensor port
// - TOUCH_REAR_LEFT_PORT:   the rear  left  touch sensor port
// - TOUCH_REAR_RIGHT_PORT:  the rear  right touch sensor port
//#define TOUCH_NUM              6
//#define TOUCH_FRONT            9
//#define TOUCH_LEFT             10
//#define TOUCH_RIGHT            11
//#define TOUCH_REAR             12
//#define TOUCH_FRONT_LEFT_PORT  9
//#define TOUCH_FRONT_RIGHT_PORT 10
//#define TOUCH_LEFT_FRONT_PORT  9
//#define TOUCH_LEFT_REAR_PORT   11
//#define TOUCH_RIGHT_FRONT_PORT 10
//#define TOUCH_RIGHT_REAR_PORT  12
//#define TOUCH_REAR_LEFT_PORT   11
//#define TOUCH_REAR_RIGHT_PORT  12

#endif
