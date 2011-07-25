/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
#include "config.Definitions.h"
void part5();
void part6();

int main()
{
	create_connect();
	enable_servos();
	clawClose();
	armPosBlockStack1();
	part5();
	part6();
}

void part5(){
	//seed, JosephMCgee:
	/*driveAtMmFor(500,.5);
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
	grabBlocks();//grab blocks procedure*/
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
	/*driveAtMmFor(500,.5);
	turn(90);
	create_drive(-500,250);
	run_for(1.0,armPosBlockStack1);
	create_drive(-500,-520);
		run_for(.5,clawStack2);
		run_for(2.0,armPosBlockStack2);
	detectPVC();
	turn(-90);
	blockStack3();*/
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
}
