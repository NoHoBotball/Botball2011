/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#include "lib.Scorer2011ArmClaw.h"
#include "lib.Definitions.h"
#define LightPort 7
int main()
{
	create_connect();
	enable_servos();
	set_create_total_angle(0);
	wait_for_light(LightPort);
	ArmUp();
	Release();
	set_servo_position(MiniServo, RaiseMini);
	shut_down_in(RunTime); //TEST THIS	
}

/*Function definitions go below.*/
