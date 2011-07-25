/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/

int main()
{	enable_servos();
	
	set_servo_position(1,400); //should be 400 when it is drivin around
	sleep(3);
	
	set_servo_position(1,1400); //lowers claw
	sleep(3);
	
	
}

/*Function definitions go below.*/
