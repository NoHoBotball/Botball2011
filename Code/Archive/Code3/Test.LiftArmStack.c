/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void Wait();
int main()
{
	initialize();
	Wait();
	
	Lift();
	Wait();
	ArmStack();
}

/*Function definitions go below.*/
void Wait()
{
	while(b_button() != 1)
	{}
	sleep(1);
	beep();
}

