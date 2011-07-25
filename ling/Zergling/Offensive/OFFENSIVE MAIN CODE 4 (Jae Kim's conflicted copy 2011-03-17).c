/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void left(int tspeed);
void right(int tspeed);
void LuggageTrack();
void movebackward();
void turnCW();
void turnCCW();
void clawlift();
void clawdrop();
void cameratrack();
void detectlinestop();
void movecenterslow();
void movecenterfast();
void turnCCWtenth();
void movecenterbackwards();
void LuggageTrack();
void spinCW();
void spinCCW();

int main()
{
	//	wait_for_light(7);
	enable_servos();
	//set_servo_position(1,900);
	//sleep(2);
	float threshold=190;     // set threshold for light conditions
	/*while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	if(analog(4) >= threshold ||analog(6) >= threshold) {
	ao();
	sleep(.5);
	movecenterslow(400);
	sleep(.2);
	}
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	
	ao();
	turnCCW();
	sleep(1);
	movecenterfast(900);
	sleep(3.2124512516);
	turnCW();
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterfast(500);
	}
	ao();
	sleep(8);
	movecenterfast(800);
	sleep(1);
	*/ 
	/*while(analog(4) <= 190) {
	movecenterslow(500);
	}
	ao();
	//at this point it has stopped at our side of the center divider
	set_servo_position(1, 800);
	sleep(1.5);	//lift up the arms enough so that the robot can still detect the line while clearing the center bump.
	movecenterfast(1000); //move forward over the center (this needs to be set distance because the arms need to clear the bump and the light sensors are on the arms
	sleep(1.7);
	ao();
	set_servo_position(1,500);
	sleep(2.5);
	turnCCW();
	//insert tower tracking function here (possibly move servos to knock over towers
	sleep(3);
	movecenterfast(800);
	sleep(1);
	ao();
	sleep(3);
	movecenterbackwards(800);
	sleep(1);
	turnCW();
	turnCW();
	sleep(1);
	turnCCW();==================
	sleep(5);
	ao();
	set_servo_position(1,100);
	sleep(2);
		LuggageTrack();
	ao();//track and pick up luggage
	set_servo_position(1,1200);
	sleep(2);
	movecenterbackwards(600);
	sleep(3);
	ao();
	set_servo_position(1,5);
	sleep(2);
	movecenterbackwards(400);
	sleep(1);
	ao();
	/*turnCCW();
	movecenterfast(600);
	sleep(1.5);
	ao();
	turnCW();
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(350);
	}
	ao();
	movecenterslow(200);
	sleep(0.3);
	ao();
	*/
	LuggageTrack();
	
}	




void turnCW(){ 
	mav(0,-700); mav(1,700);
	sleep(0.479999);
	ao();	
}	
void turnCCW(){ 
	mav(0,700); mav(1,-700);
	sleep(0.46);
	ao();	
	
}		

void clawlift() { 
	enable_servos();
	set_servo_position(1,400);
}	
void clawdrop() {
	enable_servos();
	set_servo_position(1,1400);
}

void cameratrack()
{
	//enable_servos();
	//set_servo_position(1,0);
	track_update();//=========00
	//while(digital(12) == 0)
	//{
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > 82 || track_x (0,0) <77)
		{
			while(digital(12) == 0)
			{	//ANDREW
				if (track_x(0, 0) > 82)
				{
					while(track_x(0,0) > 82)
					{
						while(digital(12) ==0){
							track_update();
							left(400);
						}
					}	
					ao();	
				}
			}
		}
	}
	/*
	else // (track_x(0,0) < X)
	{
	while(digital(12) == 0)
	{//ANDREW
	while (track_x(0, 0) < 77)
	{
	while(digital(12) == 0){
	track_update();
	right(400);
	}
	}
	}//ANDREW
	}
	ao();
	movecenterfast(400);
	if (track_x(0,0) > track_x(2,0))*/
	else
	{
		track_update();
		while (track_x (2,0) > 82 || track_x (2,0) < 77)
		{
			while(digital(12) == 0)
			{//ANDREW
				if (track_x(2, 0) > 82)
				{
					while(track_x(2,0) > 82){//00000
						while(digital(12) == 0){
							track_update();
							left(100);
						}
					}	
				}
				ao();	
			}
		}//ANDREW
	}/*
	else // (track_x(0,0) < X)
	{
	while(digital(12) == 0)
	{//ANDREW
	while (track_x(2, 0) < 77)
	{
	while(digital(12) == 0){
	track_update();
	right(100);
	}
	}
	}//ANDREW
	}
	}
	ao();
	//movecenterfast(800);
	//	set_servo_position(1,800);*/
}

//0
void movecenterfast(int tspeed)
{
mav(1, tspeed);
mav(0, tspeed - 40);  // AACCOUNTS FOR SHITTY MECHANICS WHEELS MAKES LEFT WHEEL FASTER!
}
void movecenterslow(int tspeed)
{
mav(1, tspeed);
mav(0, tspeed - 10);  // AACCOUNTS FOR SHITTY MECHANICS WHEELS MAKES LEFT WHEEL FASTER!
}
void movecenterbackwards(int tspeed) {
mav(1, -tspeed);
mav(0, -tspeed+40);
}
void leftRed(int tspeed) {
mav(1, -tspeed);
mav(0, tspeed);
}


void rightRed(int tspeed) {
mav(1, tspeed);
mav(0, -tspeed);
}

void right(int tspeed)
{
mav(1, tspeed);
mav(0, tspeed -600);
}
void left(int tspeed)
{
mav(1, tspeed-60);
mav(0, tspeed);
}
void spinCCW(tspeed) {
	mav(1,-tspeed);
	mav(0,tspeed);
}
void spinCW(tspeed) {
	mav(1,tspeed);
	mav(0,-tspeed);
}
void LuggageTrack()
{
	enable_servos();
	set_servo_position(1,0);
	track_update();
	int X = 80; //x coord of center
	int y = 3; //how far right/left of center luggage carts can be
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > X+y || track_x (0,0) < X-y)
		{
			if (track_x(0, 0) > X+y)
			{
				while(track_x(0,0) > X+y)
				{
					track_update();
					spinCCW(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X-y)
				{
					track_update();
					spinCW(100);
				}
			}
		}
		ao();
		movecenterfast(500);
		while (digital(12) == 0)
		{}
		ao();
		set_servo_position(1,1600);
	}
	else  
	{
		track_update();
		while (track_x (2,0) > X+y || track_x (2,0) < X-y)
		{
			if (track_x(2, 0) > X+y)
			{
				while(track_x(2,0) > X+y)
				{
					track_update();
					spinCCW(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-y)
				{
					track_update();
					spinCW(100);
				}
			}
		}
		ao();
		movecenterfast(500);
		while (digital(12) == 0)
		{}
		ao();
		set_servo_position(1,1600);
	}
}
