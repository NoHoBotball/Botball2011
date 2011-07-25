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
	if(digital(TouchSensor) == 0 )
	{
		while(1)
		{
			drive(200,3);
			while(get_create_lbump(0.1) == 1)
			{
				spinCW(200);
			}
		}
	}
}

/*Function definitions go below.*/
