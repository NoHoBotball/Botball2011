//
// "ross.Motors.h"
//
// Programmer:    Ross Mead
// Last modified: 15Jul2007
//

// preprocessor directives
#include "ross.Config.h"
#include "ross.Math.h"

#ifndef	 ROSS_MOTORS_OPEN
#define	 ROSS_MOTORS_OPEN
#include "ross.Declarations.h"


// grid debug definitions
//#define DEBUG_MOTORS  1



// motor definitions
int MOTOR_VEL[] = {0, 0, 0, 0};



// brakes the motor with the parameterized port
int brakeMotor(int port)
{
    return setMotorVelocity(port, 0);
}   // brakeMotor(int)



// returns the position of the parameterized motor
long getMotorPosition(int port)
{
    if ((!enabledBackEMF()) || (!isValidMotorPort(port))) return 0L;
    return get_motor_position_counter(port);
}   // getMotorPosition(int)



// returns the velocity of the parameterized motor
int getMotorVelocity(int port)
{
    #ifdef ENABLE_BACK_EMF
      if (get_motor_done(port)) setMotorVelocityArray(port, 0);
    #endif
    
    return getMotorVelocityArray(port);
}   // getMotorVelocity(int)



// returns the velocity of the parameterized motor array index
int getMotorVelocityArray(int port)
{
    if (!isValidMotorPort(port)) return 0;
    return MOTOR_VEL[port];
}   // getMotorVelocityArray(int)



// returns true if the parameterized motor port is valid, false otherwise
int isValidMotorPort(int port)
{
    return isBetween(port, 0, _array_size(MOTOR_VEL) - 1);
}   // isValidMotorPort(int)



// returns the maximum motor speed
int motorMaxSpeed()
{
    return MOTOR_MAX_SPEED;
}   // motorMaxSpeed()



// resets the odometry to the appropriate values
long resetMotorPosition(int port)
{
	clear_motor_position_counter(port);
    return get_motor_position_counter(port);
}   // resetMotorPosition(int)



// sets the position of the parameterized motor(s)
// to the parameterized position
/*
long setMotorPosition(int port, long pos)
{
    if ((!enabledBackEMF()) || (!isValidMotorPort(port))) return 0L;
    set_motor_position_counter(port, pos);
    
    #ifdef DEBUG_MOTORS
      printf("Motor %d, pos. %d\n", port, getMotorPosition(port));
    #endif
    
    return getMotorPosition(port);
}   // setMotorPosition(int, long)
*/


// sets the velocity of the parameterized motor(s)
// to the parameterized velocity
int setMotorVelocity(int port, int vel)
{
    if (!isValidMotorPort(port)) return 0;
    if (vel == 0) {
        if (enabledBackEMF()) freeze(port);
        else                  off(port);
        setMotorVelocityArray(port, vel);
    }
    else if (enabledBackEMF())
      mav(port, setMotorVelocityArray(port, vel));
    else motor(port, setMotorVelocityArray(port, vel));
    
    #ifdef DEBUG_MOTORS
      printf("Motor %d, vel. %d\n", port, getMotorVelocityArray(port));
    #endif
    
    return getMotorVelocityArray(port);
}   // setMotorVelocity(int, int)



// sets the parameterized velocity to the parameterized motor array index
int setMotorVelocityArray(int port, int vel)
{
    if (!isValidMotorPort(port)) return 0;
    return MOTOR_VEL[port] = sign(vel) * min(abs(vel), motorMaxSpeed());
}   // setMotorVelocityArray(int, int)



// sets the speed of the parameterized motor(s) to the
// parameterized speed for the parameterized number of ticks
int setMotorFor(int port, int speed, long ticks)
{
    if ((!enabledBackEMF()) || (!isValidMotorPort(port))) return 0;
    
    #ifdef DEBUG_MOTORS
      printf("Motor %d, speed %d (%l)\n", port, speed, ticks);
    #endif
    
    if ((speed == 0) || (ticks == 0L)) return brakeMotor(port);
    else {
        setMotorVelocityArray(port, (int)lsign(ticks) * speed);
        mrp(port, getMotorVelocityArray(port), ticks);
    }
    return getMotorVelocity(port);
}   // setMotorVelocityFor(int, int, long)



// waits for the parameterized motor to finish moving
void waitForMotorDone(int port)
{
    #ifdef ENABLE_BACK_EMF
      while (getMotorVelocity(port));
    #endif
}   // waitForMotorDone(int)

#endif
