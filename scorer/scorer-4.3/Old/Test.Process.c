//Test -- Process
//Process
/*	
/	Description	:
/		-This File was created to test the usefullness
/		 of using multiple processes
/
/	Written and Maintained By:
/		-Jae Kim 	02/2011-
/	
*/

void Drive();
void Beeping();


int main()
{
	int Driving;
	int BeepBeep;
	Driving=start_process(Drive);
	BeepBeep=start_process(Beeping);
	create_full();
	start_process(Drive);
	start_process(Beeping);
	sleep(3);
	kill_process(Driving);
	sleep(1);
	kill_process(BeepBeep);
}

void Drive()
{
	create_drive_straight(200);
}

void Beeping()
{
	while(1)
	{
		sleep(1);
		beep(1);
	}
}
/*Function definitions go below.*/
