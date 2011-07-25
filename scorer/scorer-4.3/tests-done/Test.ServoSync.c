/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/

int main()
{
	enable_servos();
	sleep(2);
	int x= get_servo_position(2);
	int y = get_servo_position(3);
	printf ("Servo1, Port 2 %d\n", x);
	printf ("Servo2, Port 3 %d\n", y);
}

/*Function definitions go below.*/
