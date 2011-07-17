/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
//#define Drop 0
//#define Stack 1
#define CREATE
#include "lib.Definitions.h"
void WhichSide();
int main()
{
	create_connect();
	WhichSide();
	GotoBox(Drop);
	while (b_button() ==0)
	{}
	GotoBox(Stack);
}


void WhichSide () // For Left/Right of Botguy
{
	printf ("Press and hold button for 1 second.\n\tB button for Right side, A button for Left side.\n");
	while (b_button() == 0 && a_button() == 0)
	{
		sleep(1);
		printf ("Try again.\n");
	}
	if (b_button())
	{
		Side = Right;
		printf ("On Right of Botguy. Set up lights.\n");
		sleep(1);
	}
	if (a_button())
	{
		Side = Left;
		printf ("On Left of Botguy. Set up lights.\n");
		sleep(1);
	}
}

/*
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
		ReleaseComplex();	//bd ArmCreateDist + C?ubeLength + 5	//ArmDown	//Release	//ArmUp
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


/*Function definitions go below.*/
