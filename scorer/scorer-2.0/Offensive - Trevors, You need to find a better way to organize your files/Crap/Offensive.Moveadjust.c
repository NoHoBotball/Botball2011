
//FOR CBC 
#define Rightmotor 0
#define Leftmotor 1
#define Robotlength 6
#define ConversionFactor 287.295077 //287.295077 ticks is one inch
#define AccCompX
#define AccCompY
float inchestoticks (float inches);
float tickstoinches (float ticks);
void forward (int speed, int seconds);
void move (int speed, int seconds);
void adjust (int speed);
int main()
{
	// uncomment the line below anf put 1s in the appropriate places if using floating sensors (ET and sonar)
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	
	// uncomment the line below to have the rest of the program wait for the starting light to turn on
	//wait_for_light(port_number);//replace "port_number" with the analog port number into which the light sensor is connected
	
	// uncomment the line below to have a function run for a specified amount of seconds
	//run_for(num_secs, function_name);//replace num_secs with the amount of time to run and function_name with your function's name
	mav (Rightmotor, 1000);
	mav (Leftmotor, 1000);
	sleep(100);
}

void move (int speed, int seconds)
{
	start_process(adjust);
	start_process(forward);
	sleep(seconds);
	bmd (Rightmotor);
	kill_process(adjust(int s);
	kill_process(forward);
}

void forward (int speed, int seconds)
{
	mav (Rightmotor, speed);
	mav (Leftmotor, speed);
}

void adjust (int speed)
{
	/*float acceleration;
	while(1)
	{
		while (accel_x > 5)
		{
			mav(Rightmotor
		}
	}*/
}
	float inchestoticks (float inches)
	{
		return (inches*ConversionFactor);
	}
	//inchestoticks is used as a variable
	
	float tickstoinches (float ticks)
	{
		return (ticks/ConversionFactor);
	}
	
	/*Function definitions go below.*/






void CenterCamera() //CAMERA MUST BE AT CENTER OF CREATE, POINTING RIGHT RESPECT TO CREATE
{
	create_drive_straight(-200);
	while (track_x (0,0) > 84)	//WHAT TRACK # IS RED? MAKE SURE IT DOESNT DETECT BOTGUY
	{
		track_update();
	}
	create_stop();
	if (track_x (0,0) < 75)
	{
		create_drive_straight(200);
		while (track_x (0,0) < 75)
		{
			track_update();
		}
		create_stop();
	}
}
