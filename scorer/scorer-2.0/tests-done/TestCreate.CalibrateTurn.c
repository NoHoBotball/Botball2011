//Test -- Create -- CalibrateTurn
//CreateCalibrateTurn

#define TEST_CREATECALIBRATETURN

/*	
/	Description	:
/		-This File uses the "get_create_total_angle" function to
/		 test the avg # of seconds neccessart to turn a specific
/		 angle angle (in degrees)
/
/	Written and Maintained By:
/		-Joseph McGee	03/2011-
/	
*/

#define	NumOfTests	10
#define	TestAngle	90.0

int main()
{
	create_connect();
	create_full();
	
	
	float sec;
	int angle;
	float avg = 0.0;
	for(sec = 2.185699; !a_button(); sec = (avg*(1.0 - angle/(TestAngle)) + avg))
	{
		avg = 0.0;
		int y;
		for (y = 0; y < NumOfTests; y++)
		{
			set_create_total_angle(0);
			create_spin_CCW(100);
			sleep(sec);
			create_stop();
			angle = get_create_total_angle(1);
			printf("%fsec %ddeg\n",sec,angle);
			sleep(2);
			avg = avg + angle;
		}
		avg = avg/NumOfTests;
		printf("for %2.6fsec, avg is %2.6fdeg",sec,avg);
	}
	printf("%2.6f seconds\n Done",sec);
}
	
//x = x * 90 / get_create_total_angle(0.1)
