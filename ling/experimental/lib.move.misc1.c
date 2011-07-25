//Miscellaneous  EXPERIMENTAL
#ifdef TOUCH_FRONT
#ifdef TOUCH_BACK_OR
#ifdef TOUCH_BACK_AND
void clearWall()
{
	if(TOUCH_BACK_AND)		driveAtMmFor(-50,1);
	else if(TOUCH_FRONT)	driveAtMmFor(50,1);
	else if(TOUCH_BACK_OR){
		if(TOUCH_BACK_LEFT){
			create_spin_CW(50);
			while(!TOUCH_BACK_RIGHT){}
			create_stop();
		}
		if(TOUCH_BACK_RIGHT){
			create_spin_CCW(50);
			while(!TOUCH_BACK_LEFT){}
			create_stop();
		}
	}
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
	drive(-400);
	while (ET_FRONT < ET_FRONT_PVC-100) {printf("%d\n", ET_FRONT); sleep(.1);}
	drive(-200);
	printf("%d\n", ET_FRONT);
	while (ET_FRONT < ET_FRONT_PVC) {printf("%d\n", ET_FRONT); sleep(.1);}
	create_stop();
	driveAtMmFor(-100,1);
}

void detectBlock(){  //200
	printf("%d\n", ET_FRONT);
	drive(-200);
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
		armPosBlockStack1();
	}
	driveAtMmFor(-200, .5);
	create_stop();
}

void backFromTouch(int stack_num)
{
	switch (stack_num){
		case 0:
		driveAtMmFor(GRAB_DIST,1);
		break;
		case 1:
		driveAtMmFor(STACK1_DIST,1); //touch to stack height 1
		break;
		case 2:
		driveAtMmFor(STACK2_DIST,1); //touch to stack height 2
		break;
		case 3:
		driveAtMmFor(STACK3_DIST,1); //touch to stack height 3
		break; 
		default:
		break;
		}
		}
		
		void scootUp(int scoot_num)
		{
		switch (scoot_num){
		case 0:
		driveAtMmFor(SCOOT_GRAB,1);
		break;
		case 1:
		driveAtMmFor(SCOOT_STACK1,1); //touch to stack height 1
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
	
