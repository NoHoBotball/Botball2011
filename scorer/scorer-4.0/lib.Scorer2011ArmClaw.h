//Library -- Create -- Arm&Claw
//CreateArmClaw

/*	
/	Description	:
/		-This File contains all funcions relating to the funcitonality of the 
/		 Arm and Claw mounted the Create-based robot called Scorer

/	Written and Maintained By:
/		-Jae Kim		03/2011-
/		-Joseph McGee	03/2011-
/	
*/

#define LIB_CREATEARMCLAW

/*	you must specify accurate definitions for
/		Claw, ArmServo, and ArmCreateDist
/	in the Definitions file which this function calls
*/

void grab();
void release();
void armUp();
void armDown();
void enableServoDown();
void armStack();
void cliffArmUp();
void armDownFast();

//CALIBRATE. OPEN 180 DEGREES, THEN CLEAR MOTOR COUNTER WITH SENSORS/MOTORS -> MOTORS -> TUNE

void cliffArmUp()
{
	drive(200);
	while (get_create_lcliff(.1) == 0 && get_create_rcliff(.1) ==0)
	{
		armUp();
	}
	create_stop();
	armUp();
}

void armStack()
{
	//drivemm(ArmCreateDist, 1);
	int i;
	forwardTouch(-50);
	drivemm(155,1);
	for(i = 0; i<=200; i=i+30)
	{
		set_servo_position(ArmServo1, RaiseArm1-i);
		set_servo_position(ArmServo2, RaiseArm2+i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
//		printf("%d\n", get_servo_position(ArmServo2)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.00005);
	}
	printf("%d\n", get_servo_position(ArmServo1));
}

void grab ()
{
	mtp(Claw, 500, ClawClose);
	while(get_motor_position_counter(Claw) > ClawClose+10 || get_motor_position_counter(Claw) < ClawClose-10)
	{}
	freeze(Claw);
}

void release ()
{
	/*
	mtp(Claw, 500, ClawOpen);
	while(get_motor_position_counter(Claw) > ClawOpen+10 || get_motor_position_counter(Claw) < ClawOpen-10)
	{}
	off(Claw);
	*/
	mav(Claw, -400);
	while(digital(ClawTouch) ==0)
	{}
	off(Claw);
	clear_motor_position_counter(Claw);
}

void armUp ()
{
	//drivemm(ArmCreateDist, 1);
	int i;
	for(i = 1500; i<=100; i=i-30)
	{
		set_servo_position(ArmServo1, RaiseArm1-i);
		set_servo_position(ArmServo2, RaiseArm2+i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
		// printf("%d\n", get_servo_position(ArmServo2)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.005);
	}
	set_servo_position (ArmServo1, RaiseArm1);
	set_servo_position (ArmServo2, RaiseArm2);
	//set_servo_position (ArmServo1, RaiseArm1);
	//set_servo_position (ArmServo2, RaiseArm2);
}

void armDown()
{
	//drivemm(ArmCreateDist, 1);
	int i;
	for(i = 1500; i>=100; i=i-25)
	{
		set_servo_position(ArmServo1, LowerArm1+i);
		set_servo_position(ArmServo2, LowerArm2-i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
		// printf("%d\n", get_servo_position(ArmServo2)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.0001);
	}
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
}

void enableServoDown() {
	int j;
	for (j=0; j <=450; j=j+10)
	{
		set_servo_position(ArmServo1, 1024-j);
		set_servo_position(ArmServo2, 1024+j);
		sleep(.001);
	}
	set_servo_position(ArmServo1, LowerArm1);
	set_servo_position(ArmServo2, LowerArm2);
}

	/*
	void armUpOpen()
	{
	
	printf("aaa");
	sleep(1);
	set_servo_position(ArmServo1, RaiseArm1);
	set_servo_position(ArmServo2, RaiseArm2);
	sleep(2);
	printf("qqq");
	}
	
	void armDownClose()
	{
	set_servo_position(ArmServo1, LowerArm1);
	set_servo_position(ArmServo2, LowerArm2);
	printf("%f\n", get_servo_position (3));
	set_servo_position(Claw, CloseClaw);
	printf("%f\n", get_servo_position (1));
	sleep(5);
	}
	*/


void grabComplex()
{
	if (digital(TouchSensor)==1)
	drivemm(ArmCreateDist/2, 2);
	armDown();
	grab();
	armUp();
}

void releaseComplex()
{
	//if (digital(TouchSensor)==1)
	drivemm((ArmCreateDist + CubeLength + 5)/4,4);//back dist of Create's Arm + Cubelength + 5mm safety
	armDown();
	release();
	armUp();
}


void armDownFast()
{
	//drivemm(ArmCreateDist, 1);
	int i;
	for(i = 1500; i>=100; i=i-60)
	{
		set_servo_position(ArmServo1, LowerArm1+i);
		set_servo_position(ArmServo2, LowerArm2-i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
		// printf("%d\n", get_servo_position(ArmServo2)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.00005);
	}
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
}
