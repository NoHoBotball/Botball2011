//SCORER
#define SCORER
#define CREATE			//create is the drive train

/*
#define RunTime 117
#define DIRECTIONS
	#define	Front 0
	#define	Right 1
	#define	Back 2
	#define	Left 3
#define Drop 0
#define Stack 1
*/

//Function Prototypes
char Side;
void Start();
void SetArm();
#include "lib.Definitions.h"



int main()
{
	set_each_analog_state(0,0,0,1,0,0,0,0);
	WhichSide();
	SetArm();
	Start();
	Cubes();	
}

void SetArm()
{
	printf ("Positioning claw, please wait.\n");
	enable_servos();
	set_servo_position(MiniServo, LowerMini);
	Release();
	ArmDown();
	printf ("positioning complete\n");
}

void Start() //Misc. set up functions
{
	create_connect();
	set_create_total_angle(0);
	//wait_for_light(LightPort);
	shut_down_in(RunTime); //TEST THIS	
}

