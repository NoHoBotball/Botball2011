// strategy libraries

void DEStrat();
void SeedStrat();
void seedTest();
void part1();
void part2();
void part3();
void part4();
void part5();
void part6();

void DEStrat() {
	part1();
	part2();
	part3();
	part4();
}

void seedStrat() {
	part1();
	part2();
	part3();
	part4();
	part5();
	part6();
}

void seedTest() {
	part5();
	part6();
}

void part1(){
	timeLapse();
	create_stop();
	if (side == LEFT){
		turn(45);
	}
	if (side == RIGHT){
		turn(-45); 
	}
	create_stop();
	sleep(.25);
	beep();
	create_drive_straight(-200);
	sleep(.55);
	driveAtMm(-450); //forward from SB
	sleep(1);
	//run_for(1, clawGrab); //while moving claw to Grab positio
	create_stop();
	sleep(.3);
	if (side == LEFT) {
		turn (-90);
	}
	if (side == RIGHT) {
		turn (90);
	}
	//turn(-90);//turn towards blocks
	clawGrab();
	clawOpen();
	create_drive_straight(-200);
	sleep(.3);
	driveAtMmFor(-450,.85); //move fast towards first stack for .6 sec
	detectBlock(); //then use ET sensor
	grabBlocks();
	timeLapse();
}

void part2(){
	driveAtMm(50);
	sleep(2);
	create_stop();
	driveAtMm(450);//400, 1.1 //back off from first stack to make room for turn
	sleep(.85);
	create_stop();
	sleep(.35);
	if (side == LEFT) {
		turn(-90);
	}
	if (side == RIGHT) {
		turn(90);
	}
	armPosBlockStack1();
	create_drive_straight(-250);
	sleep(.6);
	create_drive_straight(-450);
	sleep(.85);
	//driveAtMmFor(-500,1);//1.0434806);
	detectPVC();//driveAtMmFor(-100, 1);//1.5); //maxnual detectPVC
	if (side == LEFT) {
		turn(-90);//turn toward outside sb
	}
	if (side == RIGHT) {
		turn(90);
	}
	//driveAtMmFor(-500,.5);//move to outside sb pvc
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
	create_drive_straight(-200);
	sleep(.25);
	create_stop();
	driveAtMmFor(-450,3.25); //to the biofuel tower(ish) pvc
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
	create_drive_straight(-200);
	sleep(.25);
	driveAtMmFor(-300,.25);//drive towards blocks
	detectBlock();//detect and slowly approch blocks.
	grabBlocks();//grab blocks procedure
	timeLapse();
}

void part4(){
	driveAtMm(50);
	sleep(2);
	clawSBSlow();
	//armPosBlockStack1();
	create_drive_straight(200);
	sleep(1);
	create_stop();
	if (side == LEFT) {
		turn(-90);//turn towards sb side of feild
	}
	if (side == RIGHT) {
		turn(90);
	}
	create_stop();// doesn't have create_stop, is it more accurate?
	create_drive_straight(-200);
	sleep(1);
	create_drive_straight(-450);
	sleep(1.7);
	armPosBlockStack1();
	detectPVC();//drive into pvc to set angle to 0
	if (side == LEFT) {
		turn(-90);//turn towards outer starting box
	}
	if (side == RIGHT) {
		turn(90);
	}
	//armPosBlockStack1();
	create_drive_straight(-200); // drove towards blocks - before detectblock
	sleep(1.75);
	create_stop();
	blockStack2();//stack second blocks
	create_drive_straight(50);
	sleep(2);
	create_stop();
	timeLapse();
}


void part5() {
	//seed, JosephMCgee:
	sleep(.25);
	if (side == LEFT) {
		turnFast(-90);
	}
	if (side == RIGHT) {
		turnFast(90);
	}
	create_drive_straight(-200);
	sleep(.5);
	create_drive_straight(-500); // move towards opposite side of field
	sleep(1.65);
	create_stop();
	if (side == LEFT) {
		turn(-90);
	} else if ( side == RIGHT) {
		turn(90);
	}
	/*
	driveAtMmFor(-500,.5);
	if (side == LEFT) {
		create_drive(-500,460);
	}
	if (side == RIGHT) {
		create_drive(-500,-460);
	}
	sleep(2.6);
	create_stop(); */
	//run_for(2.6,clawGrab);
	create_drive_straight(-250);
	sleep(.5);
	create_drive_straight(-500); // move into opponent's field
	sleep(2);
	create_stop();
	sleep(.25);
	if (side == LEFT) {
		turn(90);//create_drive(-500,-380); 
	}
	if (side == RIGHT) {
		turn(-90);//create_drive(-500,380);
	}
	//sleep(2.2);
	//create_stop();
	//run_for(2.3, armPosBlockGrab);
	//armPosBlockGrab();
	create_drive_straight(-500); // drive into PVC
	sleep(1);
	create_stop();
	detectPVC();
	driveAtMmFor(250,.9);//run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks3, while simultaneously lifting arm above blocks
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
	create_drive(-500,250);
	if (side == LEFT) {
		turn(-90);
	}
	if (side == RIGHT) {
		turn(90);
	}
	//run_for(1.0,armPosBlockStack1);
	create_drive_straight(500);
	sleep(1);
	create_stop(0);
	if (side == LEFT) {
		turn(90); //create_drive(-500,-520);
	}
	if (side == RIGHT) {
		turn(-90); //create_drive(-500, 520);
	}
	/*run_for(.5,clawStack2);
	run_for(2.0,armPosBlockStack2); */
	armPosBlockStack2;
	clawStack2;
	create_drive_straight(-500);
	sleep(1.5);
	create_stop();
	detectPVC();
	if (side == LEFT) {
	turn(-90);
	}
	if (side == RIGHT) {
		turn(90);
	}
	blockStack3();
	timeLapse();
}
