//SCORER
#define LightPort 8
#define TowerClaw 0
#define TouchSensor 1
#define IRSensor 9
int Side;
int WhichSide (int Side);
void Start (void);
void Cubes (void);
void GotoBox();
void Grab();
void TurnCW();
void TurnCCW();
void Drive
void ForwardTouch();
float mmtoinches(float mm);
float inchestomm(float inches);
void ClearWall();
void Release(); 
void CenterCamera();

int main()
{
	//set_each_analog_state(0,0,0,0,0,0,0,0);// This line sets analog ports to be pullup (0) or floating (1)
	int WhichSide(int Side);
	Start();
	Cubes();	
}

int WhichSide (int Side)//need to specify whether 0 and 1 are right or left, respectively
{
	printf ("press and hold button for 1 second");
	while (a_button() == 0 && b_button() == 0)
	{
		sleep(1);
		printf ("try again");
	}
	if (a_button() == 1)
	{
		Side = 0;//create is on the right side
		printf ("set up lights");
	}
	if (b_button() == 1)
	{
		Side = 1;//create is on the left side
		printf ("set up lights");
	}
}

void Start (void)
{
	wait_for_light(LightPort);
	shut_down_in (117); //TEST THIS
	create_connect();
	set_create_total_angle(0);
	
}

void Cubes (void)
{
	if (Side == 0)
	{
		//Right of Botguy
		//keep offense in box until scorer gets into position
		//start with claw facing out
		ForwardTouch(); //until it hits luggage    DOES BAR TOUCH SENSOR REGISTER LUGGAGE TOUCH?
		TurnCCW();		//turn left -- now facing airplanes
		CenterCamera();	//move forwards and center the camera on the blocks -- now facing airplanes and in front of blocks
		TurnCCW();		//turn left to face blocks with claw -- now in front of and facing blocks
		ForwardTouch();	//move forward until it hits blocks
		Grab();			//grab blocks
		/*create_drive_straight(100);
		sleep(2);//to avoid crashing with our luggage carts
		create_stop();
		TurnCCW();*/
		//OFFENSE SHOULD BE OUT OF STARTING BOX BY NOW
		//FORWARD BAR SENSOR SHOULD NOT BE OBSTRUCTED
		//CREATE SHOULD DRIVE BACKWARDS
		GotoBox();
		create_drive_straight(200);
		sleep(1);
		create_stop();
		TurnCW();
		create_drive_straight(-300);
		sleep(1);
		create_stop();
		TurnCW();
		CenterCamera(); 
		TurnCCW();
		ForwardTouch();
		Grab();
		TurnCCW();
		create_drive_straight(-500);
		sleep(2.2352);
		TurnCW();
		GotoBox();
		Release();
	}
	if (Side == 1) //Left of Botguy. START WITH CREATE FACING OUT
	{
		ForwardTouch(); //Switch to distance
		TurnCW();
		ForwardTouch();
		create_drive_straight(50);
		sleep(1);
		create_stop();
		TurnCW();
		CenterCamera();
		TurnCCW();
		ForwardTouch();
		Grab();
		TurnCCW();
		/*create_drive_straight(100);
		sleep(1);
		create_stop();
		TurnCW();*/
		while (get_create_lbump(.1) == 0 && get_create_rbump(.1) == 0)
		{
			create_drive_straight(200); //unless arm is strong enough to hold
		}
		ClearWall();
		TurnCW();
		ForwardTouch();
		create_drive_straight(132);  //one cube length (5 inches) + 5 mm safety
		sleep(1);
		create_stop();
		create_drive_straight(-75);
		sleep(1);
		create_stop();
		Release();
		
	}
}

void GotoBox()
{
	while (get_create_lbump(.1) == 0 && get_create_rbump(.1) == 0)//drive backwards until hit pvc w/ bumper
	{
		create_drive_straight(200); //unless arm is strong enough to hold
	}
	create_stop();
	ClearWall();	//move away from pvc to turn
	if(Side == 0)	//turn towards outer starting box -- now facing our outer starting box w/ blocks in claw
	{
		TurnCCW();
	}
	if(Side == 1)
	{
		TurnCW();
	}
	create_stop();
	ForwardTouch();	//forward till front touch sensor ==1
	create_drive_straight(132);  //one cube length (5 inches) + 5 mm safety // drive backwards
	sleep(1);
	Release();	// realease claw w/ 2 blocks -- block now in starting box
	create_drive_straight(-75);
	sleep(1);
	create_stop();  //make sure cubes are touching pvc
}

void ClearWall()
{
	if(get_create_lbump(.1) == 1 || get_create_rbump(.1) == 1)
	{
		create_drive_straight(-132);  //one cube length (5 inches) + 5 mm safety
		sleep(1);
		create_stop();
	}
	if(digital(TouchSensor) == 1)
	{
		create_drive_straight(132);
		sleep(1);
		create_stop();
	}
}
	
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
	
	void TurnCCW()
	{
		while(get_create_total_angle(0.1) > 90)
		{
			create_spin_CCW(500);
		}
		create_stop();                   //TEST THESE. IS IT TOO FAST FOR LAG TIME? 
		//IS IT BETTER TO GO MANUAL? (219.44 for 1 second)
	}
	
	void TurnCW()
	{
		while(get_create_total_angle(0.1) > -90)
		{
			create_spin_CW(500);
		}
		create_stop();
	}
	
	void ForwardTouch ()
	{
		while (analog(TouchSensor) == 0)
		{
			create_drive_straight(-500);
		}
		create_stop();
	}
	
	/*void SlowTape (void)
	{
	while (analog IRSensor 
	}*/
	void Grab ()
	{
		mav(TowerClaw, 500);  //ideal: claw on "elevator" (duckrobot) with touch sensor at bottom of claw
		
		
	}
	
	void Release ()
	{
		mav(TowerClaw, -500);  
	}
	
	float inchestomm(float inches)
	{
		float mm;
		mm = (inches*25.4);
		return mm;
	}
	
	float mmtoinches(float mm)
	{
		float inches;
		inches = (mm/25.4);
		return inches;
	}
