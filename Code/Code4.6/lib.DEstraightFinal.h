#define CREATE
#include "config.Definitions.h"
void part1();
void part2();
void part3();
void part4();
void part5();
void part6();
void part0();

int main() //THIS IS LEFT SIDE
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
}
void part1(){
	create_stop();
	sleep(.25);
	if (side == LEFT){
		turn(45);
	}
	if (side == RIGHT){
		turn(-45); 
	}
	create_stop();
	sleep(.5);
	beep();
	driveAtMm(-500); //forward from SB
	run_for(1.15, clawGrab); //while moving claw to Grab positio
	create_stop();
	if (side == LEFT) {
		turn (-90);
	}
	if (side == RIGHT) {
		turn (90);
	}
	//turn(-90);//turn towards blocks
	clawOpen();
	driveAtMmFor(-500,.9); //move fast towards first stack for .6 sec
	detectBlock(); //then use ET sensor
	grabBlocks();
}

void part2(){
	driveAtMm(500);//400, 1.1 //back off from first stack to make room for turn
	run_for(.75,armPosBlockStack1);
	if (side == LEFT) {
		turnFast(-90);
	}
	if (side == RIGHT) {
		turnFast(90);
	}
	armPosBlockStack1();
	driveAtMmFor(-500,1.2);//1.0434806);
	detectPVC();//driveAtMmFor(-100, 1);//1.5); //manual detectPVC
	if (side == LEFT) {
		turn(-90);//turn toward outside sb
	}
	if (side == RIGHT) {
		turn(90);
	}
	driveAtMmFor(-500,.5);//move to outside sb pvc
	blockStack1();//drop off blocks
	timeLapse();
}

void part3(){
	driveAtMmFor(250,.7); // back away from towers
	if (side == LEFT) {
		turn(-90);//turn towards seconds tower block side of field
	}
	if (side == RIGHT) {
		turn(90);
	}
	// joseph's form old DE
	driveAtMmFor(-500,3.1); //to the biofuel tower(ish) pvc
	detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
	driveAtMmFor(250,.8);//1.10);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
	if (side == LEFT) {
		turn(-90);//turn towards blocks2
	}
	if (side == RIGHT) {
		turn(90);
	}
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.5);//drive towards blocks
	detectBlock();//detect and slowly approch blocks.
	grabBlocks();//grab blocks procedures
}

void part4(){
	driveAtMm(500); //clear to give space to turn
	run_for(.5,clawSB);
	if (side == LEFT) {
		turn(-90);//turn towards sb side of feild
	}
	if (side == RIGHT) {
		turn(90);
	}
	driveAtMmFor(-500,3);//drive to inner sb approx.
	detectPVC();//drive into pvc to set angle to 0
	if (side == LEFT) {
		turn(-90);//turn towards outer starting box
	}
	if (side == RIGHT) {
		turn(90);
	}
	blockStack2();//stack second blocks
	timeLapse();
}

// timer, too fast push, straighten

void part5(){
	//seed, JosephMCgee:
	driveAtMmFor(500,.5);
	if (side == LEFT) {
		turnFast(-90);
	}
	if (side == RIGHT) {
		turnFast(90);
	}
	driveAtMmFor(-500,.5);
	if (side == LEFT) {
		create_drive(-500,490);
	}
	if (side == RIGHT) {
		create_drive(-500,-490);
	}
	sleep(2.6);
	create_stop();
	//run_for(2.6, clawGrab);
	if (side == LEFT) {
		create_drive(-500,-350);
	}
	if (side == RIGHT) {
		create_drive(-500,350);
	}
	sleep(2.3);
	create_stop();
	armPosBlockGrab();
	//run_for(1.9,armPosBlockGrab);
	detectPVC();
	timeLapse();
	driveAtMmFor(250,1.00);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks3, while simultaneously lifting arm above blocks
	if (side == LEFT) {
		turn(90);//turn towards blocks3
	}
	if (side == RIGHT) {
		turn(-90);
	}
	armPosBlockGrab(); //arm in grab pos
	clawGrab();
	driveAtMmFor(-500,.4);//drive towards blocks
	detectBlock();//detect and slowly approch blocks.
	grabBlocks();//grab blocks procedure
}

void part6(){
	driveAtMmFor(500,.5);
	if (side == LEFT) {
		turn(90);
	}
	if (side == RIGHT) {
		turn(-90);
	}
	if (side == LEFT) {
		create_drive(-500,250);
	}
	if (side == RIGHT) {
		create_drive(-500,250);
	}
	run_for(1.0,armPosBlockStack1);
	if (side == LEFT) {
	create_drive(-500,-520);
	}
	if (side == RIGHT) {
		create_drive(-500, 520);
	}
	run_for(.5,clawStack2);
	run_for(2.0,armPosBlockStack2);
	detectPVC();
	if (side == LEFT) {
	turn(-90);
	}
	if (side == RIGHT) {
		turn(90);
	}
	blockStack3();
	//wtf is this.
	/*create_drive_straight(-500); // move towards pvc
	sleep(2.5);
	create_stop();
	driveAtMmFor(50, 1);*/
}
