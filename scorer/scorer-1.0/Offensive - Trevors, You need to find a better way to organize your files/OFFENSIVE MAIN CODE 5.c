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
//#define time 30;
void countdown();


int main()
{
	//	wait_for_light(7);
	/*shut_down_in(117);
	start_process(*countdown);
	enable_servos();
	
	clawdrop();
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
	//biofuelblock();
	*/
	while(digital(12) == 0)
	{
		Luggagecartcafe();
		movecenterfast(500);
		sleep(0.4);
	}
	set_servo_position(1,1000);
	sleep(0.75);
	movecenterbackwards(800);
	sleep(3);
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
	mav(0, tspeed -50);
}
void left(int tspeed)
{
	mav(1, tspeed-50);
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
	left(250);
	}	
	ao();	
	}
	else // (track_x(0,0) < X)
	{
	while (track_x(0, 0) < X)
	{
	track_update();
	right(250);
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
	left(250);
	}	
	ao();	
	}
	else // (track_x(0,0) < X)
	{
	while (track_x(2, 0) < X-5)
	{
	track_update();
	right(250);
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
	
void countdown()
{
	float timeBegin = seconds();
	
	while ((30 - (seconds() - timeBegin)) > 20){}
	printf("Shut down in:\n");
	while(1)
	{
		printf("%2.0f\t", (30 - (seconds() - timeBegin)));
		sleep(0.950);
	}
}
