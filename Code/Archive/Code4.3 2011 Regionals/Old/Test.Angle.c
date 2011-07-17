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
	create_connect();
	create_full();
	printf("angle");
	set_create_total_angle(0);
	printf("A\n");
	sleep(1);
	create_drive_direct(-10,10);
	while (get_create_total_angle(0.01) < 90);
	{
		printf("B");
	}
	printf("\n");
	create_stop();
	printf("C");
}

/*Function definitions go below.*/
