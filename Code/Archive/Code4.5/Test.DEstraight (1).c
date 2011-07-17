#define CREATE
#include "config.Definitions.h"
void part1();
void part2();
void part3();
void part4();
void part5();
void part6();
void part0();

int main()
{
	part0();
	part1();
	part2();
	part3();
	part4();
	part5();
	part6();	
}

	//LEFT
void part0(){
	initialize();  
	
	side == LEFT;
	timeLapse();
}
void part1(){
	turn(45);
	beep();
	driveAtMm(-500); //forward from SB
		run_for(1.0, clawGrab); //while moving claw to Grab positio
		create_stop();
	turn(-90);//turn towards blocks
	clawOpen();
	driveAtMmFor(-500,.9); //move fast towards first stack for .6 sec
	detectBlock(); //then use ET sensor
	grabBlocks();
}

void part2(){
	driveAtMm(500);//400, 1.1 //back off from first stack to make room for turn
		run_for(.75,armPosBlockStack1);
	turnFast(-90);
	armPosBlockStack1();
	driveAtMmFor(-500,1.2);//1.0434806);
	detectPVC();//driveAtMmFor(-100, 1);//1.5); //manual detectPVC
	turn(-90);//turn toward outside sb
	driveAtMmFor(-500,.5);//move to outside sb pvc
	blockStack1();//drop off blocks
	timeLapse();
}

void part3(){
	driveAtMmFor(250,.7); // back away from towers
	turn(-90);//turn towards seconds tower block side of field
	// joseph's form old DE
	driveAtMmFor(-500,3.1); //to the biofuel tower(ish) pvc
	detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
	driveAtMmFor(250,1.0);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
	turn(-90);//turn towards blocks2
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.5);//drive towards blocks
	detectBlock();//detect and slowly approch blocks.
	grabBlocks();//grab blocks procedures
}

void part4(){
	driveAtMm(500); //clear to give space to turn
		run_for(1,clawSB);
	turn(-90);//turn towards sb side of feild
	driveAtMmFor(-500,2.8);//drive to inner sb approx.
	detectPVC();//drive into pvc to set angle to 0
	turn(-90);//turn towards outer starting box
	blockStack2();//stack second blocks
	timeLapse();
}

void part5(){
	//seed, JosephMCgee:
	driveAtMmFor(500,.5);
	turnFast(-90);
	driveAtMmFor(-500,.5);
	create_drive(-500,520);
		run_for(2.6, clawGrab);
	create_drive(-500,-350);
		run_for(1.9,armPosBlockGrab);
		armPosBlockGrab();
	detectPVC();
	timeLapse();
	driveAtMmFor(250,1.00);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks3, while simultaneously lifting arm above blocks
	turn(90);//turn towards blocks3
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.4);//drive towards blocks
	detectBlock();//detect and slowly approch blocks.
	grabBlocks();//grab blocks procedure
}

void part6(){
	driveAtMmFor(500,.5);
	turn(90);
	create_drive(-500,250);
	run_for(1.0,armPosBlockStack1);
	create_drive(-500,-520);
		run_for(.5,clawStack2);
		run_for(2.0,armPosBlockStack2);
	detectPVC();
	turn(-90);
	blockStack3();
	//wtf is this.
	/*create_drive_straight(-500); // move towards pvc
	sleep(2.5);
	create_stop();
	driveAtMmFor(50, 1);*/
}
