// navigation navigation navigation
// written by ben shukman

void seed();
void seedDR();
void seedFastGrab();
void seedReturn();
void seedStack();
void seedStraight();//JosephMcGee
void seedStraightReturn();//JospehMcGee


// Main:

void seed() { // thus far - only tested on right side
	create_drive(500,-300); // arc turn out of 2nd block stack
	sleep(2);
	create_stop();
	create_drive_straight(500); // drive straight in preparation for arc turn into opponent's side
	sleep(.25);
	create_stop();
	create_drive(500,300); // arc turn into opponent's side
	// sleep(2.25);
	run_for(2.25, armPosBlockStack1); // positions arm for IR detecting while arc turning into runway
	create_stop();
	create_drive_straight(500); // move into the opponent's side - prep for arc into hangar wall
	sleep(.25);
	create_stop();
	// seedDR or seedFastGrab goes here
	seedFastGrab();
	seedReturn();
	seedStack();
}


// Functions:

void seedDR() { // seed dead reckon - orients perfectly at the corner of the pvc next to 3rd tower stack - starts at commented line (on runway)
	turnFast(180); // 180 turn
	create_drive(-500, 230); // arc into hangar wall
	sleep(1.35);
	create_stop();
	detectPVC(); // straighten against pvc
	create_drive_straight(50); // back up from wall - makes space for turning
	msleep(750);
	create_stop();
	turn(-90); // turn towards blocks
	detectPVC(); // align against blocks wall
	create_drive(500,100); // arc turns 45 degrees (NOT TESTED)
	sleep(.5);
	create_stop();
	create_drive(500,-100); // arc turns -45 degrees: aligns with blocks perfectly (NOT TESTED)
	sleep(.5);
	create_stop();
}

void seedFastGrab() { // arc turns twice from runway position into a tower grabbing position - used to save time for seeding round (an alternative strategy)
	create_drive(500,-200); // EVERYTHING HERE NEEDS TO BE TESTED AND REDONE ONCE FINAL STACKING IS FINISHED
	sleep(.5);				// INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE
	create_stop();
	create_drive_straight(500);
	sleep(.6);
	create_stop();
	create_drive(500,200);
	sleep(.5);
	create_stop();
	create_drive_straight(-500);
	sleep(.5);
	create_stop();
	grabBlocks();
}

void seedReturn() {
	/*create_drive_straight(500); // drive away from -grabbed- towers
	sleep(.5);
	create_stop();
	create_drive(500,-200); // inverse of seedFastGrab - NOT FINISHED NEEDS VALUE TESTING
	sleep(.5);				// INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE
	create_stop();  
	create_drive_straight(500);
	sleep(.6);
	create_stop();
	create_drive(500,200);
	sleep(.5);
	create_stop(); */
	create_drive(-500,300); // inverse arc turn towards home side
	run_for(2.25, armPosBlockStack2); // set arm to seeding stack position
	create_stop();
	create_drive_straight(-500); // drive towards home starting wall
	sleep(1); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST 
	create_stop();
	detectPVC(); // straighten against pvc
	create_drive_straight(50); // back up from wall - makes space for turning
	msleep(750);
	create_stop();
	turn(90);
	create_drive_straight(-400);
	sleep(1); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST 
	create_stop();
	// transitions into seeding stack function
}

void seedStack() {
	blockStack3();
}

void seedStraight(){
	driveAtMmFor(500,.5);//drive bd away from blocks1 in sb
	turnForLeft(-135);//turn at an angle pointing towards the runway
	driveAtMm(-500);
	run_for(1,armPosBlockStack1);
	run_for(.5,clawOpen);
	create_stop();
	turnForLeft(135);
	driveAtMmFor(-500,.5);
	detectBlock();
	grabBlocks();
	clawSB();
}

void seedStraightReturn(){
	driveAtMmFor(-500,.5);
	turnForLeft(45);
	driveAtMmFor(-500,1.5);
	turnForLeft(135);
	armPosBlockStack2();
	driveAtMmFor(-500,.5);
	detectPVC();
	turnForLeft(-90);
	blockStack3();
}
	
	
	//driveAtMmFor(-500,1.5);//after getting to the runway, stop...
	//turnForLeft(-45);//...and turn to proper 90 deg angle
	//driveAtMmFor(-500,.5);//cross runway
	//turnForLeft(-45);//turn CCW 90 towards blocks
