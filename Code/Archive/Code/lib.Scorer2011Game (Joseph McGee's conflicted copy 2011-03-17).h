//Library -- Create -- 2011Game
//2011Game

#define LIB_SCORER2011GAME

/*	
/	Description	:
/		-This File contains all funcions relating to the strategy of the 
/		 Create-based robot called Scorer in the Botball2011 Competition
/
/	Written and Maintained By:
/		-Jae Kim		02/2011-
/		-Joseph McGee	02/2011-
		-Ben Shukman
/	
*/

//#include "lib.Definitions.h"

/*	you must include
/		CreateCenterCamera, CreateArmClaw
/	and define
/		CREATE
/	in the file from which this funcition is called
*/

void GotoBox();
void Cubes();
void Position();
void TurnLeft();//treat as if turning left on right side (on left side everything is reversed)
void TurnRight();//treat as if turning right on right side (on left side everything is reversed)

void Cubes()
{
	//start with Create facing Botguy (drives backwards), inside SBox, camera facing right of botguy (so facing left since driving backwards)
	//Move our first 2 blocks to Outer starting box
	{
		ArmUp();
		Release();
		drivemm(-200,1); 	//until it hits luggage
		TurnRight();
		drivemm(-100,1);
		//TurnLeft();					//turn In(Left on RightSide, Right on LeftSide) -- now facing AirplaneSide
		//CenterCameraR2011(0,200);	//fd until camera centered on blocks	//turn CCW(Left)	//fd until touch blocks
		CenterCamera();
		create_stop();
		while (1)
		{
			printf("A");
		}
		printf("B");
		GrabComplex();				//bd ArmCreateDist	//ArmDown	//Grab blocks	//ArmUp
		GotoBox(Drop);				//Go from blocks to outer starting box and release
	}
	//Position in Center of side(past luggage bins) facing AirplaneSide
	{
		drivemm(200,1);		//bd to center of side
		TurnRight();			//Turn Out(Right on RightSide, Left on LeftSide)
		drivemm(-300,1);	//fd past luggage bins
		TurnRight();			//Turn Out(Right on RightSide, Left on LeftSide)
		Position();			//If on right drive to approx position of last 2 cubes
		
	}
	//Move our last 2 blocks to outer starting box and stack on last 2 blocks	
	{	//CenterCameraR2011(0,200);	//fd or bd until camera centered on blocks	//turn CCW(Left)	//fd until touch blocks
		CenterCamera();
		GrabComplex();			//bd ArmCreateDist	//ArmDown	//Grab blocks	//ArmUp
		TurnLeft();				//turn In(Left on RightSide, Right on LeftSide) -- now facing AirplaneSide
		drivemm(-500,2.2352);	//fd past luggage bins 
		TurnRight();				//Turn Out(Right on RightSide, Left on LeftSide)
		GotoBox(Stack);			//Go from blocks to outer starting box and stack on other blocks
	}
}


void GotoBox(int DropOrStack) // 0 is drop, 1 is stack
{
	
	while (get_create_lbump(.1) == 0 && get_create_rbump(.1) == 0)//drive bd until hit pvc w/ bumper
	{
		drive(200); 
	}
	stop();
	ClearWall();	//move away from pvc to turn
	TurnLeft();		//turn towards outer starting box -- now facing our outer starting box w/ blocks in claw
	stop();
	ForwardTouch(-100);	
	if (DropOrStack==Drop)
	{
		ReleaseComplex();	//bd ArmCreateDist + CubeLength + 5	//ArmDown	//Release	//ArmUp
		drivemm(-50,(ArmCreateDist + 5)/50);//to push Blocks to PVC
		// to move (ArmCreateDist + 1) at 50mm/s
		//	d = r*t
		//	(ArmCreateDist + 1) = 50*t
		//	t = (ArmCreateDist + 1)/50
	}
	if (DropOrStack==Stack)//stacks last2blocks on first2blocks
	{
		drivemm(ArmCreateDist,1);//back dist of Create's Arm
		ArmStack();
		Release();
	}
	drivemm(-100,2);
	ArmUp();
	//make sure cubes are touching pvc
}




void Position()
{
	if(Side == Right)
	drivemm(-500,2);	//rough positioning to other cubes CHECK THIS
}

void TurnLeft()//treat as if turning left on right side (on left side everything is reversed)
{
	if (Side == Right)
	TurnCCW();
	if (Side == Left)
	TurnCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}

void TurnRight()//treat as if turning right on right side (on left side everything is reversed)
{
	if (Side == Right)
	TurnCW();
	if (Side == Left)
	TurnCCW();
	if (Side != Left && Side != Right)
	{
		printf("\nError Side is neither Right nor Left\n");
	}
}
