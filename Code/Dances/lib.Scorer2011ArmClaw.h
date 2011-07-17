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
void grabComplex();
void releaseComplex();
void armUp();
void armDown();
void enableServoDown();
void armDownFast();
void armStack();
void cliffArmUp();


//CALIBRATE. OPEN 180 DEGREES, THEN CLEAR MOTOR COUNTER WITH SENSORS/MOTORS -> MOTORS -> TUNE
void grab()
{
	mtp(Claw, 500, ClawClose);
	while(get_motor_position_counter(Claw) > ClawClose+10 || get_motor_position_counter(Claw) < ClawClose-10){}
	freeze(Claw);
}

void release ()
{
	mav(Claw, -400);
	while(!digital(ClawTouch)){}
	freeze(Claw);
	clear_motor_position_counter(Claw);
}

/*
void grabComplex()
{
	if(digital(TouchSensor))	drivemm(CreateArmDist/2, 2);
	armDown();
	grab();
	armUp();
}

void releaseComplex()
{
	if(digital(TouchSensor))	drivemm((CreateArmDist + CubeLength + 5)/4,4);//back dist of Create's Arm + Cubelength + 5mm safety
	armDown();
	release();
	armUp();
}

*/
void armStack()
{
	//drivemm(ArmCreateDist, 1);
	int i;
	forwardTouch(-100);
	drivemm(500, 0.31);//500*.31 = 155
	for(i = 0; i<=200; i=i+30)
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_RIGHT_UP-i);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_UP+i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
//		printf("%d\n", get_servo_position(SERVO_ARM_RIGHT_PORT)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.00005);
	}
	printf("%d\n", get_servo_position(SERVO_ARM_LEFT_PORT));
}

void armUp ()
{
//	drivemm(ArmCreateDist, 1);
	int i;
	for(i = 1500; i>=100; i=i-30) // i>=100 make sure it is greater than or equals to, just fixed this.
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_UP-i);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_UP+i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
//		printf("%d\n", get_servo_position(SERVO_ARM_RIGHT_PORT)); // delete if working.
		printf("Iterations: %d\n", i);
		sleep(.005);
	}
	set_servo_position (SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_UP);
	set_servo_position (SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_UP);
}

void armDown()
{
	int i;
	for(i = 1500; i>=100; i=i-25)
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN+i);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN-i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
//		printf("%d\n", get_servo_position(SERVO_ARM_RIGHT_PORT)); // delete if working.
		printf("Iterations: %d\n", i);
		msleep(0001);
	}
	set_servo_position (SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN);
	set_servo_position (SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN);
}

void armDownFast()
{
	int i;
	for(i = 1500; i>=100; i=i-60)
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN+i);
		set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN-i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(SERVO_ARM_LEFT_PORT), get_servo_position(SERVO_ARM_RIGHT_PORT));
//		printf("%d\n", get_servo_position(SERVO_ARM_RIGHT_PORT)); // delete if working.
		printf("Iterations: %d\n", i);
		msleep(0005);
	}
	set_servo_position (SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN);
	set_servo_position (SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN);
}

void enableServoDown()
{
	int j;
	for (j=0; j <=450; j=j+10)
	{
		set_servo_position(SERVO_ARM_LEFT_PORT, 1024-j);
		set_servo_position(SERVO_ARM_RIGHT_PORT, 1024+j);
		sleep(.001);
	}
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_DOWN);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_DOWN);
}

void cliffArmUp()
{
	drive(200);
	while (!get_create_lcliff(.1) && !get_create_rcliff(.1))
	{
		armUp();
	}
	create_stop();
	armUp();
}
