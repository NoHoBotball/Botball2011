//Miscellaneous
#ifdef TOUCH_FRONT
#ifdef TOUCH_BACK_OR
#ifdef TOUCH_BACK_AND
void clearWall()
{
	driveAtMmFor(100,1);
}

#endif

void backwardTouch(int speed)
{
	drive(speed);
	while(!TOUCH_BACK_OR);
	create_stop();
}
#endif

void forwardTouch(int speed)
{
	drive(-speed);
	while(!TOUCH_FRONT);
	create_stop();
}
#endif

void detectPVC(){ //400
	printf("%d\n", ET_FRONT);
	drive(-500);
	while (ET_FRONT < ET_FRONT_PVC-100) {printf("%d\n", ET_FRONT); sleep(.1);}
	drive(-200);
	printf("%d\n", ET_FRONT);
	while (ET_FRONT < ET_FRONT_PVC) {printf("%d\n", ET_FRONT); sleep(.1);}
	create_stop();
	driveAtMmFor(-100,1);
	clearAngle();
	clearWall();
}

void detectPVCSlow(){ //200
	printf("%d\n", ET_FRONT);
	drive(-200);
	while (ET_FRONT < ET_FRONT_PVC-100) {printf("%d\n", ET_FRONT); sleep(.1);}
	drive(-150);
	printf("%d\n", ET_FRONT);
	while (ET_FRONT < ET_FRONT_PVC) {printf("%d\n", ET_FRONT); sleep(.1);}
	create_stop();
	driveAtMmFor(-50,2);
	clearAngle();
	clearWall();
}

void detectBlock(){  //200
	/*
	printf("%d\n", ET_FRONT);
	drive(-200);
	while (ET_FRONT < ET_FRONT_BLOCK) {printf("%d\n", ET_FRONT); sleep(.1);}
	driveAtMmFor(-200, .5);*/
	printf("%d\n", ET_FRONT);
	drive(-200);
	//clawOpen();
	/*
	while (ET_FRONT < ET_FRONT_BLOCK) {
	while (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK1)
	{
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT+30);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT-30);
	sleep(.01);
	}
	while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK1)
	{
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
	sleep(.01);
	}
	armPosBlockStack1();*/
	while (ET_FRONT < ET_FRONT_BLOCK) {
		printf("A");
		printf("%d\n", ET_FRONT);
		sleep(.1);
	}
	//driveAtMmFor(-200, .5);
	create_stop();
}

void detectBlockSlow(){
	printf("%d\n", ET_FRONT);
	drive(-100);
		while (ET_FRONT < ET_FRONT_BLOCK) {
		printf("A");
		printf("%d\n", ET_FRONT);
		sleep(.1);
	}
	driveAtMmFor(-100, 1);
	create_stop();
}

void detectBlockLast() { //this is for stacking the third stack. need a different function from above
	printf("%d\n", ET_FRONT);
	drive(-200);
	while (ET_FRONT < ET_FRONT_BLOCK) {
		while (get_servo_position(SERVO_CLAW_LEFT_PORT) < SERVO_CLAW_LEFT_STACK2)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT+30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT-30);
			sleep(.01);
		}
		while (get_servo_position(SERVO_CLAW_LEFT_PORT) > SERVO_CLAW_LEFT_STACK2)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT-30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT+30);
			sleep(.01);
		}
		clawStack2();
	}
	driveAtMmFor(-200, .5);
	create_stop();
}

void backFromTouch(int stack_num)
{
	switch (stack_num){
		case 0:
		driveAtMm(GRAB_DIST*2);
		sleep(.5);
		run_for(.5, clawGrab);
		create_stop();
		clawGrab();
		break;
		case 1:
		driveAtMm(STACK1_DIST*2); //touch to stack height 1
		sleep(.2);
		run_for(.8, clawGrab);
		create_stop();
		clawGrab();                   
		break;
		case 2:
		driveAtMm(STACK2_DIST); //touch to stack height 2
		sleep(.7); //run_for(.8, clawStack1);
		create_stop();
		clawStack1();
		break;
		case 3:
		driveAtMmFor(STACK3_DIST,1.2); //touch to stack height 3
		break; 
		default:
		break;
	}
}

void scootUp(int scoot_num)
{
	switch (scoot_num){
		case 0:
		armPosBlockGrab();
		driveAtMm(SCOOT_GRAB*2);
		/*run_for(.7, armPosBlockGrab);
		create_stop();
		armPosBlockGrab();*/
		sleep(.4);
		create_stop();
		break;
		case 1:
		armPosBlockGrab();
		driveAtMmFor(SCOOT_STACK1,1.05); //touch to stack height 1
		//sleep(.6);
		//run_for(.7, armPosBlockGrab);
		create_stop();
		//armPosBlockGrab();
		break;
		default:
		break;
	}
}

//Experimental

int beepFor(int num_of_beeps)
{
	int i;
	for(i=0; i < num_of_beeps; i++)	beep();
	return (i+1);
}

float timeLapse(){
	run_time[time_num]=seconds();
	printf("time%d - time0 = %f\n", time_num, run_time[time_num] - run_time[0]);
	time_num++;
return (run_time[time_num] - run_time[0]);
}

