/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
int X;
void TurnCCW();
int main()
{
	create_connect();
	set_create_total_angle(0);
	while(black_button() == 0)
	{
		if (a_button() == 1)
		{
			TurnCCW();
		}
	}
}

void TurnCCW()
{
	#ifdef	CREATE
	create_drive(101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	while (get_create_total_angle(.005)-X < 89 || get_create_total_angle(.005)-X > 91)
	{
		//printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.005)-X > 90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(10, -10);
			printf(" to CW");
			while (get_create_total_angle(.005)-X != 90);
			{}
			create_stop();
		}
		if (get_create_total_angle(.005)-X < 90)
		{
			create_drive_direct(-10, 10);
			printf(" to CCW");
			while (get_create_total_angle(.005)-X != 90);
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X+90;
	#endif
	#ifdef	CBC
	int tspeed;
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
	#endif
}

void TurnCW()
{
	#ifdef	CREATE
	create_drive(-101.3,1);
	//create_drive(49.240435,1);
	//sleep(4.2322869);
	sleep(2.057252314);
	create_stop();
	printf("Initial Turn CCW");
	int i;
	for (i = 0; (i < 2) && (get_create_total_angle(.005)-X > -89 || get_create_total_angle(.005)-X < -91); i++)
	{
		//printf("%d\n", get_create_total_angle(.1));
		//set_create_total_angle(get_create_total_angle(.1) - 90);
		printf("Adjusting");
		if (get_create_total_angle(.005)-X < -90) //CCW ADDS TO TOTAL ANGLE
		{
			create_drive_direct(10, -10);
			printf(" to CW");
			while (get_create_total_angle(.005)-X != -90);
			{}
			create_stop();
		}
		if (get_create_total_angle(.005)-X > -90)
		{
			create_drive_direct(-10, 10);
			printf(" to CCW");
			while (get_create_total_angle(.005)-X != -90);
			{}
			create_stop();
		}
	}
	//printf("%d\n", get_create_total_angle(.1));
	create_stop();
	X=X-90;
	#endif
}

/*Function definitions go below.*/
