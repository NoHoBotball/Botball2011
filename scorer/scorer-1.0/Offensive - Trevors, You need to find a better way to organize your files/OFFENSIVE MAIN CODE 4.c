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
void LuggageTrack2();
void Luggagecartcafe();
void spinCW();
void spinCCW();
int z;
void biofuelblock();

int main()
{
	//	wait_for_light(7);
	enable_servos();

	set_servo_position(1,1500);
	float threshold=190;     // set threshold for light conditions
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	if(analog(4) >= threshold ||analog(6) >= threshold) {
	ao();
	sleep(.5);
	movecenterfast(700);
	sleep(.1);
	}
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	
	ao();
	turnCCW();
	sleep(1);
	movecenterfast(900);
	sleep(4);
	turnCW();
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterfast(500);
	}
	ao();
	sleep(11);
	movecenterfast(900);
	sleep(1);
	while(analog(4) <= 190) {
	movecenterslow(1000);
	}
	ao();
	//at this point it has stopped at our side of the center divider
	//THE LINE DETECTOR PART OF CROSSING CENTER IS NO LONGER NECCESSARY, JUST SET DISTANCE IT
	set_servo_position(1, 300);
	sleep(0.5);	//lift up the arms enough so that the robot can still detect the line while clearing the center bump.
	mav(0,1000);
mav(1,1000); 	//move forward over the center (this needs to be set distance because the arms need to clear the bump and the light sensors are on the arms
	sleep(4.3);
	ao();
	
	//NOW ON OTHER SIDE, IN MIDDLE REGION
	//can run either biofuel blocking code or luggage cart code
	biofuelblock();
	while(digital(12) == 0)
	{
		luggagecartcafe();
		movecenterfast(500);
		sleep(0.4);
	}
		set_servo_position(1,1000);
	sleep(0.75);
	movecenterbackwards(800);
	sleep(3);
	/*set_servo_position(1,1600);
	sleep(0.5);
	turnCCW();
	//insert tower tracking function here (possibly move servos to knock over towers
	//if this was biofuel, andrews code goes here
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
	turnCCW();
	sleep(5);
	ao();
	while(digital(12)==0) {
	movecenterfast(1000);
	}
		/*while(digital(12)==0) {
			LuggageTrack();
		movecenterfast(500);
		sleep(0.5);
		ao();
		}//track and pick up luggage
		set_servo_position(1,950);
	sleep(3);
	movecenterbackwards(500);
	sleep(3);
	ao();
	set_servo_position(1,5);
		sleep(0.7);
	movecenterbackwards(400);
	sleep(1.5);
		turnCCW();
		while(digital(12)==0){
		movecenterfast(600);
	}
	movecenterbackwards(400);
	sleep(0.5);	
	turnCW();
	set_servo_position(1,1900);
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	ao();
	turnCW();
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(350);
	}
	ao();
	movecenterslow(200);
	sleep(0.3);
	ao();
	
	/*while (digital(12) == 0)
		{
	LuggageTrack2();
//			if(z=1){
				movecenterfast(600);
		//		sleep(0.5);
//}

}
ao();
set_servo_position(1,950);
movecenterbackwards(500);
	sleep(3);
	ao();
	set_servo_position(1,5);
		sleep(0.7);
	movecenterbackwards(400);
	sleep(1.5);
		turnCCW();
		while(digital(12)==0){
		movecenterfast(600);
	}
	movecenterbackwards(400);
	sleep(0.5);	
	turnCW();
	set_servo_position(1,1900);
	while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	ao();
	*/
	//Luggagecartcafe();
	sleep(4);
	set_servo_position(1,200);
	while(digital(12) == 0) {
		movecenterfast(600);
	}
	Luggagecartcafe();
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
	else if (track_x(0,0) > track_x(2,0));
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
mav(0, tspeed -20);
}
void left(int tspeed)
{
mav(1, tspeed-20);
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

void LuggageTrack2()
{
	enable_servos();
	z = 0;
	set_servo_position(1,0);
	track_update();
	int X = 72;
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > X+5 || track_x (0,0) < X-5)
		{
			if (track_x(0, 0) > X+5)
			{
				while(track_x(0,0) > X+5)
				{
					track_update();
					spinCW(30);
				}	
				z=1;
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X-5)
				{
					track_update();
					spinCCW(30);
				}
				z=1;
				ao();
			}
		}
		ao();
		movecenterfast(500);
		while (digital(12) == 0)
		{}
		ao();
		set_servo_position(1,800);
	}
	else  
	{
		track_update();
		while (track_x (2,0) > X+5 || track_x (2,0) < X-5)
		{
			if (track_x(2, 0) > X+5)
			{
				while(track_x(2,0) > X+5)
				{
					track_update();
					spinCW(30);
				}	
				z=1;
				ao();
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-5)
				{
					track_update();
					spinCCW(30);
				}
				z=1;
				ao();
			}
		}
		ao();
		movecenterfast(500);
		
	}
}

void LuggageTrack()
{
	enable_servos();
	set_servo_position(1,0);
	track_update();
			int X = 73; //x coord of center of left cart
	int y = 5; //how far right/left of center luggage carts can be
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) < X-y || track_x (0,0) > X+y)
		{
			if (track_x(0, 0) > X+y)
			{
				while(track_x(0,0) > X+y)
				{
					track_update();
					spinCW(50);
				}	
				ao();	
			}
			else if (track_x(0,0) < X-y)
			{
				while (track_x(0, 0) < X-y)
				{
					track_update();
					spinCCW(50);
				}
			}
		}
	
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
					spinCCW(50);
				}	
				ao();	
			}
			else if (track_x(0,0) < X-y)
			{
				while (track_x(2, 0) < X-y)
				{
					track_update();
					spinCW(50);
				}
				ao();
			}
		}
	}
}
void Luggagecartcafe()
{
	enable_servos();
	set_servo_position(1,200);
	track_update();
	int X = 69;
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > X+5 || track_x (0,0) < X-5)
		{
			if (track_x(0, 0) > X+5)
			{
				while(track_x(0,0) > X)
				{
					track_update();
					left(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X)
				{
					track_update();
					right(100);
				}
				ao();
			}
		}
	
	}
	else  if (track_x(2,0) < track_x(0,0)) //Pink on left
	{
		track_update();
		while (track_x (2,0) > X+5 || track_x (2,0) < X-5)
		{
			if (track_x(2, 0) > X+5)
			{
				while(track_x(2,0) > X+5)
				{
					track_update();
					left(80);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-5)
				{
					track_update();
					right(80);
				}
			}
		}

	}
			
}

void biofuelblock() {
	turnCCW();
	while(digital(12) == 0) {
		movecenterfast(900);
	}
	movecenterbackwards(800);
	sleep(032342);
	ao();
	turnCW();
	set_servo_position(1,1900);
while(analog(4) <= 190 && analog(6) <= 190) {
	movecenterslow(500);
	}
	ao();
}

