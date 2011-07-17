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
/	
*/

//#include "lib.Definitions.h"

/*	you must include
/		CreateCenterCamera, CreateArmClaw
/	and define
/		CREATE
/	in the file from which this funcition is called
*/

void GotoBox(int DropOrStack);		//does commenting out declaration create error?  	Ask Ross after competion
void Cubes();
void Position();

void Cubes()
{
	//start with Create facing Botguy (drives backwards), inside SBox, camera facing right of botguy (so facing left since driving backwards)
	//Move our first 2 blocks to Outer starting box
	{
		ArmUp();
		Release();
		drivemm(-200,1); 	//until it hits luggage
		TurnRight();
		drivemm(-200,1);	//drive till cubes in view
		CenterCamera();		//fd until camera centered on blocks	//turn left
		Lift();				//Grab cubes
		//GrabComplex();				//bd ArmCreateDist	//ArmDown	//Grab blocks	//ArmUp
		GotoBox(Drop);				//Go from blocks to outer starting box and release
	}
	//Position in Center of side(past luggage bins) facing AirplaneSide
	{
		drivemm(200,1);		//bd to center of side									CHECK THIS
		TurnRight();		//Turn Right
		drivemm(-300,1);	//fd past luggage bins									CHECK THIS
		TurnRight();		//Turn Right
		drivemm(-500,2);	//rough positioning to other cubes 						CHECK THIS
		
	}
	//Move our last 2 blocks to outer starting box and stack on last 2 blocks	
	{
		CenterCamera();			//fd until camera centered on blocks	//fd till touch blocks
		Lift();
		//GrabComplex();			//bd ArmCreateDist	//ArmDown	//Grab blocks	//ArmUp
		TurnLeft();				//turn Left -- now facing AirplaneSide
		drivemm(-500,2.2352);	//fd past luggage bins 
		TurnRight();			//Turn Right
		GotoBox(Stack);			//Go from second blocks to outer starting box and stack on other blocks
	}
}


void GotoBox(int DropOrStack) // 0 is drop, 1 is stack
{
	drive(300); 
	while (get_create_lbump(.1) == 0 && get_create_rbump(.1) == 0)//drive bd until hit pvc w/ bumper
	{
		
	}
	stop();
	TurnLeft();		//turn towards outer starting box -- now facing our outer starting box w/ blocks in claw
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
