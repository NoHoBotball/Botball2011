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

void Grab();
void Release();
void ArmUp();
void ArmDown();
void ArmStack();
//CALIBRATE. OPEN 180 DEGREES, THEN CLEAR MOTOR COUNTER WITH SENSORS/MOTORS -> MOTORS -> TUNE

void ArmStack()
{
	//drivemm(ArmCreateDist, 1);
	int X;
	for(X = 1500; X!=100; X=X-200)
	{
		set_servo_position(ArmServo1, RaiseArm1-X);
		set_servo_position(ArmServo2, RaiseArm2+X);
	}
	
}

void Grab ()
{
	//set_servo_position (Claw, CloseClaw);
	mtp(Claw, 500, ClawClose);
	while(get_motor_position_counter(1) > ClawClose+5 || get_motor_position_counter(1) < ClawClose-5)
	{}
	freeze(Claw);
}

void Release ()
{
	mtp(Claw, 500, ClawOpen);
	while(get_motor_position_counter(1) > ClawOpen+5 || get_motor_position_counter(1) < ClawOpen-5)
	{}
	off(Claw);
}

void ArmUp ()
{
	set_servo_position (ArmServo1, RaiseArm1);
	set_servo_position (ArmServo2, RaiseArm2);
}

void ArmDown ()
{
	//drivemm(ArmCreateDist, 1);
	for(int i = 1500; i!=100; i=i++)
	{
		set_servo_position(ArmServo1, LowerArm1+i);
		set_servo_position(ArmServo2, LowerArm2-i);
		printf("Servo 1: %d. Servo 2: %d. ", get_servo_position(ArmServo1), get_servo_position(ArmServo2));
		// printf("%d\n", get_servo_position(ArmServo2)); // delete if working.
		printf("iteration: %d\n", i);
		sleep(.0025);  // test values. make faster.
	}
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
	printf("%d\n", get_servo_position(ArmServo1));
}

/*
void ArmUpOpen()
{
	
	printf("aaa");
	sleep(1);
	set_servo_position(ArmServo1, RaiseArm1);
	set_servo_position(ArmServo2, RaiseArm2);
	sleep(2);
	printf("qqq");
}

void ArmDownClose()
{
	set_servo_position(ArmServo1, LowerArm1);
	set_servo_position(ArmServo2, LowerArm2);
	printf("%f\n", get_servo_position (3));
	set_servo_position(Claw, CloseClaw);
	printf("%f\n", get_servo_position (1));
	sleep(5);
}*/


void GrabComplex()
{
	//if (digital(TouchSensor)==1)
	//{
	drivemm(ArmCreateDist/2, 2);
	//}
	ArmDown();
	Grab();
	ArmUp();
}

void ReleaseComplex()
{
	//if (digital(TouchSensor)==1)
	//{
	drivemm((ArmCreateDist + CubeLength + 5)/4,4);//back dist of Create's Arm + Cubelength + 5mm safety
	//}
	ArmDown();
	Release();
	ArmUp();
}
