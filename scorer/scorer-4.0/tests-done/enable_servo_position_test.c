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
	printf("left servo: %d\n", get_servo_position(0));
	printf("right servo: %d\n", get_servo_position(3));
}

/*Function definitions go below.*/
