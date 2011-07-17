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
void moveforwardfast();
void moveforwardslow();
void movebackward();
void turnCW();
void turnCCW();
void clawlift();
void clawdrop();
void detectlinestop();
void cameratrack();
//int target_cha_in_chb(int,int, int, int);
int main()
{
	int threshold=512;     // set threshold for light conditions
	//int x = 79;
	//int y = 80;
	//moveforwardslow();
	//sleep(0.3);
	//ao();
	//turnCCW();
	int i;
	for(i = 0; i <=8000; i++) {
		cameratrack();
	}
	//turnCW();
	
	/* while(){ //while the luggage carts are in frame, do all this code) 
	while (analog10(1) >= threshold) {
	moveforewardfast();
	}
	ao();
	sleep(5);//wait until we can cross to other side (15 sec)
	while (analog10(1) >= threshold) {
	moveforewardfast();
	}
	break; //break the while loop when we are going to knock down towers
	}
	turnCCW();
	//tower push
	6y
	moveforward();
	sleep(2);
	turnCW();
	turnCW();
	moveforward();
	sleep(2);
	turnCCW();
	//track, grab, and move backwards
	//insert luggage cart tracker
	
	*/
	
}
void moveforwardfast() {
	mav(0, 1000);
	mav(1, 1000);
}
void moveforwardslow() {
	mav(0, 500);
	mav(1, 500);
}
void movebackward() { 
	mav(0, -1000);
	mav(1, -1000);
}
void turnCW(){ 
	mav(0,-700); mav(1,700);
	sleep(0.479999);
	ao();	
}	
void turnCCW(){ 
	mav(0,700); mav(1,-700);
	sleep(0.479999);
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
void detectlinestop() {
	int threshold=512;     // set threshold for light conditions
	if (analog10(1) >= threshold) { // continue until dark
		ao();       // move to line
		
	}
}
/*
void cameratrack() {
	
	enable_servos();
	set_servo_position(1,0);
	track_update();
	while (track_x (0,0) > 77 || track_x (0,0) < 82 || digital(8) == 0)
	{
		if (track_x(0, 0) > 77)
		{
			while(track_x(0,0) > 77)
		}		
		void clawlift() { 
			enable_servos();
			set_servo_position(1,400);
		}	
		void clawdrop() {
			enable_servos();
			set_servo_position(1,1400);
		}
		void detectlinestop() {
			int threshold=512;     // set threshold for light conditions
			if (analog10(1) >= threshold) { // continue until dark
				ao();       // move to line
				
			}
		}
*/

void cameratrack() {
	
	enable_servos();
	set_servo_position(1,0);
	track_update();
	while (track_x (0,0) > 77 || track_x (0,0) < 82 || digital(8) == 0)
	{
		if (track_x(0, 0) > 77)
		{
			while(track_x(0,0) > 77)
			{
				track_update();
				left(500);
			}	
			ao();	
		}
		else // (track_x(0,0) < X)
		{
			while (track_x(0, 0) < 82)
			{
				track_update();
				right(500);
			}
			ao();
		}
	}
	
	mav(1,500);
	mav(0,500);
	sleep(0.1);
	ao();
	/*
	
	//check every 1/2 of a second
	track_update();
	int x, y;
	if ((target_cha_in_chb(0,2, x, y)) == 1) {
	//cha is channel number for the inner color and chb is the surrounding color channel. 
	//If target is found function returns 1, otherwise 0. x and y are changed
	target_cha_in_chb(0,2, x, y);
	
	if (x <= 76) {
	mav(0,100); mav(1,-100);
	}
	if (x <=83, x>=76) {
	mav(0,0); mav(1,0);
	}
	if (x >=83) {
	mav(0,-100); mav(1,100);
	}
	}
	*/
	sleep(0.05);
}
//void cameratrackpinkleft() {



void left(int tspeed)
{
	mav(1, tspeed / 2);
	mav(0, tspeed);
}

void leftRed( int tspeed)) {
	mav(1, -tspeed);
	mav(0, tspeed);
}

void rightRed(
	mav(1, tspeed);
	mav(0, -tspeed);
}

void right(int tspeed)
{
	mav(1, tspeed);
	mav(0, tspeed / 2);
}

//}

//void cameratrackgreenleft(){

//}



/*Function definitions go below.*/
