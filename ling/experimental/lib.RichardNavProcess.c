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
void approachThirdCubes();
void returnThirdCubes();
void arc(int arc_num);

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

void cubeStack()
{
	//START WITH CREATE FORCED BACK
	armPosBlockStack1();
	clawStack1();
	clawOpen();
	approachFirstCubes();
	returnFirstCubes();
//	stackBlocks1();

	approachSecondCubes();
	returnSecondCubes();
//	stackBlocks2();
}

void approachFirstCubes()
{
	int pid;
	armPosBlockStack1();//halfway point
	pid=start_process(armPosBlockGrab);
	arc(1);//should do arc to blocks
	kill_process(pid);
	//driveAtMmFor(-500,inToMm(21.5)/500.0);//needs to go about 20 inches (27 - radius of create)
	//turnForRight(90);//turn towards blocks
	//driveAtMmFor(-500,inToMm(36.0)/500.0);//drive towards blocks
	
}

void returnFirstCubes()
{
	turnFast(180);//do a sloppy but very quick about face
	arc(2);//arc turn into pvc about between starting boxes
	detectPVC();//ram create into the PVC to straighten it out, also create angle and X to 0
	clearWall();//clear the wall
	turnForRight(90);//turn towards outer starting box
	blockStack1();
	driveAtMmFor(-500,inToMm(15.0)/500.0);//drive into starting box
	//detectPVC();
	blockStack1();
}	

void approachSecondCubes()
{
	clearWall();
	turnForRight(90);//turn towards seconds blocks side of field
	driveAtMmFor(-500,inToMm(74.0)/500.0);//zoom up to PVC on our side, opposite starting boxes (past second blocks)
	detectPVC();
	clearWall();
	driveAtMmFor(200,inToMm(15.0)/200.0);//align create with Blocks2
	turnForRight(-90);//turn towards Blocks2
	driveAtMmFor(-500,inToMm(14.0)/500.0);//drive quickly upto Blocks2
	grabBlocks();
}

void returnSecondCubes()
{
	turnFast(180);//do a sloppy but very quick about face
	arc(3);//arc turn into pvc about between starting boxes
	detectPVC();
	clearWall();
	turnForRight(90);//turn towards outer starting box
	driveAtMmFor(-500,inToMm(15.0)/500.0);//drive into starting box
	blockStack2();
}

void approachThirdCubes(){
	clearWall();
	turnForRight(90);//turn facing N
	arc(4);//arc onto close edge of runaway
	arc(5);//arc (kind of semicircle), stop in front of blocks3
	detectBlock();
	grabBlocks();
}

void returnThirdCubes(){
	turnForRight(-90);
	arc(6);//arc into center of our side facing away from runway
	arc(7);//arc into PVC between starting blocks
	detectPVC();
	clearWall();
	turnForRight(90);//turn towards outer starting box
	driveAtMmFor(-500,inToMm(15.0)/500.0);//drive into starting box
	blockStack3();
}

void botguyGrab()
{
	
}


void arc(int arc_num){
	switch(arc_num){
		case 1:
			if (side==RIGHT) create_drive(-500, -500);  //create's left 800
			if (side==LEFT)  create_drive(-500, 500);  //create's left
			sleep(1.74);   //2.9
			break;
		/*case 2:
			break;
		default:
			break;*/
	}
}
#endif
