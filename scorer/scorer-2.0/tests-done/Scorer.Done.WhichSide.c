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
	int Side; 
	printf ("press and hold button for 1 second");
	beep();
	while (a_button() == 0 && b_button() == 0)
	{
		sleep(1);
		printf ("try again");
	}
	if (a_button() == 1)
	{
		Side = 0;//create is on the right side
		printf("right %d/n", Side);
		printf ("set up lights/n");
	}
	if (b_button() == 1)
	{
		Side = 1;//create is on the left side
		printf("left %d/n", Side);
		printf ("set up lights/n");
	}
}

/*Function definitions go below.*/
