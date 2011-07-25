/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/


#define ClawServo 1
#define OpenClaw 1550
#define CloseClaw 200

#define ArmServo1 3
#define RaiseArm1 1860
#define LowerArm1 380

#define ArmServo2 0
#define RaiseArm2 0
#define LowerArm2 1480
int main()
{
	enable_servos();
	sleep(2);
	set_servo_position (ArmServo1, LowerArm1);
	set_servo_position (ArmServo2, LowerArm2);
	printf("%d\n", get_servo_position(0));
	printf("%d\n", get_servo_position(3));
	sleep(2);
	set_servo_position (ArmServo1, RaiseArm1);
	set_servo_position (ArmServo2, RaiseArm2);
	printf("%d\n", get_servo_position(0));
	printf("%d\n", get_servo_position(3));
	sleep(2);
}

/*Function definitions go below.*/
