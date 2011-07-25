// robotic arm functions library
// code written by ben shukman, --- 

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void armPosSB();
void armPosBlockGrab();
void armPosBlockStack1();
void armPosBlockStack2();
void clawClose();
void clawOpen();
void clawSB();
void clawGrab();
void clawStack1();
void clawStack2();

// Functions:

void armPosSB() { // arm positions to contain itself in the starting box
	while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_DOWN)
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
		sleep(.01);
	}
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN);
}

void armPosBlockGrab() { //arm positioned to grab blocks
	if (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_GRAB)  //if arm is below grab height, raise it
	{
		while (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_GRAB)
		{
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT+30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT-30);
			sleep(.01);
		}
	}
	if (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_GRAB)
	{
		while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_GRAB)
		{
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
			sleep(.01);
		}
	}
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_GRAB);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_GRAB);
}

void armPosBlockStack1() { // arm positioned to stack blocks
	if (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK1)
	{
		while (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK1) //if arm is below stack height, raise it
		{
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT+30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT-30);
			sleep(.01);
		}
	}
	if (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK1)
	{
		while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK1)
		{
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
			sleep(.01);
		}
	}
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK1);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK1);
}

void armPosBlockStack2() {  //arm positioned to stack third pair of blocks during seeding
	while (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_STACK2-200) //if arm is below stack height, raise it
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT+30);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT-30);
		sleep(.01);

	}
	while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_STACK2-200)  //drive, and run this for duration of drive, then quick move
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
		sleep(.01);
	}
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK2);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK2);
}

void clawClose() {
	mav(0,200);
	sleep(4);
	freeze(0);
}

void clawOpen() {
	mav(0,-300);
	while(digital(TOUCH_CLAW_PORT) == 0)
	{}
	off(0);
}

void clawSB() {
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_SB);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_SB);
	clawOpen();
}

void clawGrab() {
	if (get_servo_position(SERVO_CLAW_RIGHT_PORT) < SERVO_CLAW_RIGHT_GRAB)
	{
		while (get_servo_position(SERVO_CLAW_RIGHT_PORT) < SERVO_CLAW_RIGHT_GRAB) //if arm is below stack height, raise it
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT-30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT+30);
			sleep(.01);
		}
	}
	if (get_servo_position(SERVO_CLAW_RIGHT_PORT) > SERVO_CLAW_RIGHT_GRAB)
	{
		while (get_servo_position(SERVO_CLAW_RIGHT_PORT) > SERVO_CLAW_RIGHT_GRAB)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT+30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT-30);
			sleep(.01);
		}
	}
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_GRAB);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_GRAB);
}


void clawStack1() {
	if (get_servo_position(SERVO_CLAW_RIGHT_PORT) < SERVO_CLAW_RIGHT_STACK1)
	{
		while (get_servo_position(SERVO_CLAW_RIGHT_PORT) < SERVO_CLAW_RIGHT_STACK1) //if arm is below stack height, raise it
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT-30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT+30);
			sleep(.01);
		}
	}
	if (get_servo_position(SERVO_CLAW_RIGHT_PORT) > SERVO_CLAW_RIGHT_STACK1)
	{
		while (get_servo_position(SERVO_CLAW_RIGHT_PORT) > SERVO_CLAW_RIGHT_STACK1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT+30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT-30);
			sleep(.01);
		}
	}
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK1);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK1);
}

void clawStack2() {
	while (get_servo_position(SERVO_CLAW_RIGHT_PORT) < SERVO_CLAW_RIGHT_STACK2) //if arm is below stack height, raise it
	{
		set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT-30);
		set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT+30);
		sleep(.01);
	}
	while (get_servo_position(SERVO_CLAW_RIGHT_PORT) > SERVO_CLAW_RIGHT_STACK2)
	{
		set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT+30);
		set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT-30);
		sleep(.01);
	}
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK2);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK2);
}
