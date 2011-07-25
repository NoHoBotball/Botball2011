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


int main()
{
//	wait_for_light(7);
	enable_servos();
	set_servo_position(1,2000);
	float threshold=190;     // set threshold for light conditions
	while(analog(4) <= 190 && analog(6) <= 190) {
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
	
	while(analog(4) <= 190) {
		movecenterslow(500);
	}
	ao();


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
	track_update();
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > 82 || track_x (0,0) <77)
		{
			if (track_x(0, 0) > 82)
			{
				while(track_x(0,0) > 82)
				{
					track_update();
					left(700);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < 77)
				{
					track_update();
					right(700);
				}
			}
		}
		ao();
		movecenterfast(800);
	}
	else  
	{
		track_update();
		while (track_x (2,0) > 82 || track_x (2,0) < 77)
		{
			if (track_x(2, 0) > 82)
			{
				while(track_x(2,0) > 82)
				{
					track_update();
					left(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < 77)
				{
					track_update();
					right(100);
				}
			}
		}
		ao();
		movecenterfast(800);
	//	set_servo_position(1,800);
	}
}

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
	mav(0, tspeed -200);
}
void left(int tspeed)
{
	mav(1, tspeed-200);
	mav(0, tspeed);
}
