// DE
// written by ben shukman

void DE();
void block1();
void block2();


// Main:

void DE() { // needs to be tested on both sides
	block1();
	block2();
}

// Functions:

void block1() {
	if (side==RIGHT) { // arc turn towards first blocks
		turn(-45);
		//sleep(1);
		clawGrab();
		clawOpen();

//		updateX(45);
//		create_drive(101.3,1);
//		run_for(1, clawOpen);
//		create_stop();
		
		create_drive(-500,-380); // arc towards blocks - done
		run_for(2.15, armPosBlockStack1);  // raise arm so it goes over blocks
		create_stop();
		beep();
		//sleep(1); // test value
		create_drive_straight(-350); // drive towards blocks - reduces chance of error
		sleep(.40);
		create_stop();
		detectBlock(); // detect
		beep();
		grabBlocks(); //grab
		sleep(1);; // grab pause - test value
		create_drive_straight(200); // move away from blocks after grabbing
		sleep(.5);
		create_stop();
		clawSBSlow(); // lift towers
		turnFast(180);
		create_drive(-500,250); //TEST
		run_for(1, armPosBlockStack1);
		create_stop();
		create_drive_straight(-400); // move towards pvc - prepare for straighten
		sleep(.5);
		create_stop();
		/*create_drive_straight(-200); // straighten
		sleep(.5);
		create_stop(); */
		create_drive_straight(-150);
		sleep(1);
		create_stop();
		set_create_total_angle(0);
		create_drive_straight(50); // back up from wall - makes space for turning
		msleep(750);
		create_stop();
		turn(90);
		//create_drive_straight(-350);
		//sleep(1);
		//create_stop();
		blockStack1();
	}
	if (side==LEFT)  { // values and turns need to be tested
		turn(45);
		//sleep(1);
		clawGrab();
		clawOpen();

//		updateX(45);
//		create_drive(101.3,1);
//		run_for(1, clawOpen);
//		create_stop();
		
		create_drive(-500, 380); // arc towards blocks - done
		run_for(2.15, armPosBlockStack1);  // raise arm so it goes over blocks
		create_stop();
		beep();
		//sleep(1); // test value
		create_drive_straight(-350); // drive towards blocks - reduces chance of error
		sleep(.40);
		create_stop();
		detectBlock(); // detect
		beep();
		grabBlocks(); //grab
		sleep(1.5); // grab pause - test value
		create_drive_straight(200); // move away from blocks after grabbing
		sleep(.5);
		create_stop();
		clawSBSlow(); // lift towers
		turnFast(180);
		create_drive(-500,-250); // TEST
		run_for(1.2, armPosBlockStack1);
		create_stop();
		create_drive_straight(-400); // move towards pvc
		sleep(.5);
		create_stop();
		/*create_drive_straight(-200);
		sleep(.5);
		create_stop();*/
		create_drive_straight(-150);
		sleep(1);
		create_stop();
		set_create_total_angle(0);
		create_drive_straight(50); // back up from wall - makes space for turning
		msleep(750);
		create_stop();
		turn(-90);
		//create_drive_straight(-350);
		//sleep(1);
		//create_stop();
		blockStack1();
	}
}

void block2() { // grabs second set of blocks and stacks it in sb
	if (side == RIGHT) {
		driveAtMmFor(500,.5);//drive bd away from blocks1 in sb
		turnForRight(-90);//turn towards side opposite side (past blocks2)
		create_drive_straight(100); // straighten create
		sleep(1);
		create_stop();
		set_create_total_angle(0);
		create_drive_straight(50); // back up from wall - makes space for turning
		msleep(750);
		create_stop();
		turn(180); // turn around accurately
		driveAtMmFor(-500,1.8);//drive to other side (past blocks2)
		detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
		drive(250);  run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
		turn(90);//turn towards blocks2
		driveAtMmFor(-500,.4);//drive towards blocks
		detectBlock();//detect and slowly approch blocks.
		stop();//stop create for good measure
		grabBlocks();//grab blocks procedure
		sleep(1.5);//give claw time to close
		turnFast(90);//turn towards sb side of feild
		driveAtMmFor(-500,1.6);//drive to inner sb approx.
		detectPVC();//drive into pvc to set angle to 0
		turn(90);//turn towards outer starting box
		blockStack2();//stack second blocks
	}
	if (side == LEFT) {
		driveAtMmFor(500,.5);//drive bd away from blocks1 in sb
		turnForRight(-90);//turn towards pvc
		create_drive_straight(100); // straighten create
		sleep(1);
		create_stop();
		set_create_total_angle(0);
		create_drive_straight(50); // back up from wall - makes space for turning
		msleep(750);
		create_stop();
		turn(180); // turn around accurately
		driveAtMmFor(-500,1.8);//drive to other side (past blocks2)
		detectPVC();//drive upto, then ram into PVC to straighten create, set total angel to 0
		drive(250);  run_for(1.5, armPosBlockStack1);//drive bd to align create to blocks2, while simultaneously lifting arm above blocks
		turn(-90);//turn towards blocks2
		driveAtMmFor(-500,.4);//drive towards blocks
		detectBlock();//detect and slowly approch blocks.
		stop();//stop create for good measure
		grabBlocks();//grab blocks procedure
		sleep(1.5);//give claw time to close
		turnFast(-90);//turn towards sb side of feild
		driveAtMmFor(-500,1.6);//drive to inner sb approx.
		detectPVC();//drive into pvc to set angle to 0
		turn(90);//turn towards outer starting box
		blockStack2();//stack second blocks
	}
}
