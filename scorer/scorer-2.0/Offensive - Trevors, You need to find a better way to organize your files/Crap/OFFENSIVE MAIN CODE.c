/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void moveforwardfast();
void moveforwardslow();
void movebackward();
void turnCW();
void turnCCW();
void clawlift();
void clawdrop();
void detectlinestop();
void cameratrack();
int target_cha_in_chb(int,int, int, int);
int main()
{
int threshold=512;     // set threshold for light conditions
	
	moveforwardslow();
	sleep(0.3);
	ao();
	turnCCW();
	int i;
	for(i = 0; i <=8; i++) {
		cameratrack();
	}
	turnCW();

     while (analog10(1) >= threshold) {
		 moveforewardfast();
	 }
	 ao();
	 sleep(5);//wait until we can cross to other side (15 sec)
	 while (analog10(1) >= threshold) {
		 moveforewardfast();
	 }
	 
	
	
	
	
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
	mav(0,700); mav(1,-700);
	sleep(0.479999);
	ao();	
	}	
void turnCCW(){ 
	mav(0,-700); mav(1,700);
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

void cameratrack() {
	//check every 1/2 of a second
	int x = 79;
	int y = 80;
	target_cha_in_chb(0,2, x, y);
	//cha is channel number for the inner color and chb is the surrounding color channel. 
	//If target is found function returns 1, otherwise 0. x and y are changed
if (x <= 76) 
{
	mav(0,700); mav(1,600);
}
if (x<=83, x>=76) 
{
	mav(0,700); mav(1,700);
}
if (x >=83) 
{
	mav(0,600); mav(1,700);
}
sleep(0.5);
}
//void cameratrackpinkleft() {
	
	
//}

//void cameratrackgreenleft(){
	
//}


	
/*Function definitions go below.*/
