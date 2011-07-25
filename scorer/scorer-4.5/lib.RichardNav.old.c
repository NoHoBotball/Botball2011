//GCER SCORER CODE
//-Jae


#ifndef  LIB_RICH_NAV
#define  LIB_RICH_NAV
void botguyGrab();
void cubeStack();
void approachFirstCubes();
void returnFirstCubes();
void approachSecondCubes();
void returnSecondCubes();


void approachFirstCubes()
{
	armPosBlockStack2();
	if (side==RIGHT) //forward
	{
		create_drive(-500, -800);  //create's left 800
	}
	if (side==LEFT) 
	{
		create_drive(-500, 800);  //create's left
	}
	sleep(1.74);   //2.9
	forwardTouch(200);
	backFromTouch(1);
	//clawClose();
}

void returnFirstCubes()
{
	if  (side==RIGHT)
	{
		create_drive(300, -279.4);
	}
	if  (side==LEFT)
	{
		create_drive(300, 279.4);
	}
	sleep(1.27); //1.34
	create_stop();
	sleep(2);
	turnForRight(-1); sleep(2); turnForRight(-1);
	forwardTouch(200);
	clearWall();
	sleep(2);
	turnForRight(1);
	forwardTouch(200);
	//clawOpen();
}	

void approachSecondCubes()
{
	turnForRight(1); turnForRight(1); //180 degree
	if (side==RIGHT) //forward
	{
		create_drive(-300, 279.4);
	}
	if (side==LEFT) 
	{
		create_drive(-300, -279.4);
	}
	armPosBlockStack2();
	sleep(1.35);
	create_drive_straight(-300);
	sleep(2.65);
	if (side==RIGHT)
	{
		create_drive(-300,-279.4);
	}
	if (side==LEFT)
	{
		create_drive(-300, 279.4);
	}
	sleep(1.45);
	forwardTouch(200);
	backFromTouch(1);
	armPosBlockGrab();
	//clawClose(); //do we have to pause for arm to move to position before grabbing?
}

void returnSecondCubes()
{
	if (side==RIGHT)
	{
		create_drive(300,-279.4);
	}
	if (side==LEFT)
	{
		create_drive(300, 279.4);
	}
	sleep(1.4);
	backwardTouch(200);
	clearWall();
	printf("%d\n",get_create_total_angle(0.1));
	turnForRight(-1);
	armPosBlockStack1();
	forwardTouch(200);
	backFromTouch(2);
	//clawOpen();
}

void botguyGrab()
{
}

void cubeStack()
{
	//START WITH CREATE FORCED BACK
	approachFirstCubes();
	returnFirstCubes();
	approachSecondCubes();
	returnSecondCubes();
}

void richardNav()
{
	if (strategyOrder == 1) //botguyfirst
	{
		botguyGrab();
		cubeStack();
	}
	if (strategyOrder == 2) //cubesfirst
	{
		cubeStack();
		botguyGrab();
	}
}



#endif
