//SCORER
/*	This is the Scorer Robot it will score points for our team by
*/
#define Create

#define LightPort 0		//Analog Sensor Definitions
#define IRSensor 1
#define TouchSensor 9	//Digital Sensor Definitions

#define RightMotor 0	//Motor Ports
#define LeftMotor 1

//#ifndef LIB_CONVERSIONS_H
	#include "lib.Conversions.h"
	//#endif
//#ifndef LIB_DEFINITONS_H
	#include "lib.Definitions.h"
	//#endif
//#ifndef LIB_MOVEMENT_H
	#include "lib.Movement.h" 
	//#endif


char Side;
void WhichSide();
void Start();
void Cubes();
void GotoBox();
void Grab();
void Release();
void ForwardTouch();
void ClearWall();
void CenterCamera();

int main()
{
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	WhichSide();
	Start();
	Cubes();	
}

void WhichSide ()//to specify whether create is on right or left
{
	printf ("press and hold button for 1 second");
	while (!a_button() && !b_button())
	{
		sleep(1);
		printf ("try again");
	}
	if (a_button())
	{
		Side = RIGHT;//press a if create is on the right side
		printf ("set up lights\n");
	}
	if (b_button())
	{
		Side = LEFT;//press b if create is on the left side
		printf ("set up lights\n");
	}
}

void Start()
{
	create_connect();
	set_create_total_angle(0);
	wait_for_light(LightPort);
	shut_down_in(RunTime); //TEST THIS	
}

void Cubes()
{
	if (Side == RIGHT)
	{
		// of Botguy
		//keep offense in box until scorer gets into position
		//start with claw facing out of front and camera facing left of create
		ForwardTouch(); //until it hits luggage? -- DOES BAR TOUCH SENSOR REGISTER LUGGAGE TOUCH?
		TurnCCW();		//turn left -- now facing airplanes
		CenterCamera();	//move forwards until camera is centered on blocks
		TurnCCW();		//turn left to face blocks with claw -- now in front of and facing blocks
		ForwardTouch();	//move forward until touch blocks
		drivemm(ClawLength,1); //move backwards length of claw
		Grab();				//grab blocks
		/*create_drive_straight(100);
		sleep(2);//to avoid crashing with our luggage carts
		create_stop();
		TurnCCW();*/
		//OFFENSE SHOULD BE OUT OF STARTING BOX BY NOW
		//FORWARD BAR SENSOR SHOULD NOT BE OBSTRUCTED
		//CREATE SHOULD DRIVE BACKWARDS
		GotoBox();		//Go from blocks to outer starting box and release
		//blocks now in starting box
		drivemm(200,1);
		TurnCW();
		drivemm(-300,1);
		TurnCW();
		CenterCamera(); 
		TurnCCW();
		ForwardTouch();
		Grab();
		TurnCCW();
		drivemm(-500,2.2352);
		GotoBox();
		Release();
		//at this point there are two tower boxes stacked in the starting box
		//we now need to get the other 2 tower boxes, track and orient the robot to the first 2 boxes, and stack 
		them
		//Turns around 180
		TurnCW();
		TurnCW();
		drivemm(XXXXX VALUES TEST AND FIND OUT)
		//Drive to some Distance XXXXX that we find by testing, then turn and track the boxes/pick em up
		TurnCW();
		CenterCamera();
		ForwardTouch();
		Grab();

	}
	if (Side == LEFT) //Left of Botguy. START WITH CREATE FACING OUT
	{
		ForwardTouch(); //Switch to distance
		TurnCW();
		ForwardTouch();
		drivemm(50,1);
		TurnCW();
		CenterCamera();
		TurnCCW();
		ForwardTouch();
		Grab();
		TurnCCW();
		/*create_drive_straight(100);
		sleep(1);
		create_stop();
		TurnCW();*/
		while (!get_create_lbump(.1) && !get_create_rbump(.1))
		{
			create_drive_straight(200); //unless arm is strong enough to hold
		}
		ClearWall();
		TurnCW();
		ForwardTouch();
		drivemm((CubeLength + 5),1);  //one cube length + 5 mm safety // drive backwards
		drivemm(-75,1);
		Release();
		
	}
}

void GotoBox()
{
	while (!get_create_lbump(.1) && !get_create_rbump(.1))//drive backwards until hit pvc w/ bumper
	{
		create_drive_straight(200); //unless arm is strong enough to hold
	}
	create_stop();
	ClearWall();	//move away from pvc to turn
	if(Side == 0)	//turn towards outer starting box -- now facing our outer starting box w/ blocks in claw
	{
		TurnCCW();
	}
	if(Side == 1)
	{
		TurnCW();
	}
	create_stop();
	ForwardTouch();	//forward till front touch sensor ==1
	drivemm((CubeLength + 5),1); //one cube length (5 inches) + 5 mm safety // drive backwards
	Release();		//realease claw w/ 2 blocks -- blocks now in starting box
	drivemm(-75,1);	//make sure cubes are touching pvc
}

void ClearWall()
{
	if(get_create_lbump(.1) || get_create_rbump(.1))
	{
		drivemm(-(CubeLength + 5),1);  //one cube length (5 inches) + 5 mm safety
	}
	if(digital(TouchSensor) == 1)
	{
		drivemm((CubeLength + 5),1);  //one cube length (5 inches) + 5 mm safety // drive backwards
	}
}

void CenterCamera() //CAMERA MUST BE AT CENTER OF CREATE, POINTING RIGHT RESPECT TO CREATE
{
	create_drive_straight(-200);
	while (track_x (0,0) > 84)	//WHAT TRACK # IS RED? MAKE SURE IT DOESNT DETECT BOTGUY
	{
		track_update();
	}
	create_stop();
	if (track_x (0,0) < 75)
	{
		create_drive_straight(200);
		while (track_x (0,0) < 75)
		{
			track_update();
		}
		create_stop();
	}
}


void ForwardTouch ()
{
	while (!analog(TouchSensor))
	{
		create_drive_straight(-500);
	}
	create_stop();
}

	/*void SlowTape (void)
	{
	while (analog IRSensor 
}*/
void Grab ()
{
	mav(TowerClaw, 500);  //ideal: claw on "elevator" (duckrobot) with touch sensor at bottom of claw
	
	
}

void Release ()
{
	mav(TowerClaw, -500);  
}
void camera()
{
  int threshold=512;     // set threshold for light conditions
  int high=600,low=400;  // set wheel speeds for high, low
     while (analog10(1) < threshold) { // continue until dark  
// insert jaes color tracking code
While (touch sensor== 0) // while the robot has not hit the pipe at the other side of the field
// we could also say if the color that its tracking is big enough, it turns.
{
If( colortracked is at center of camera)
{ mav(0,high); mav(3,high);
}

If( colortracked is at right of camera of camera)
{ mav(0,high); mav(3,low);
}
If( colortracked is at left of camera)
{ mav(0,low); mav(3,high);
}
}
