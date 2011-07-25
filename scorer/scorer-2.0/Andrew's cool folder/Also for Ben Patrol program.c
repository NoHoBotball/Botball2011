//Offensive Bot Ver 3.1.4.159//

/////-v-Define things :D-v-/////
#define motorL 1//Left motor
#define motorR 0//Right motor
#define IR analog(4) //Analog on claw
#define touch digital(12) //Touch sensor
#define threshold 150 //Treshold for IR sensor
/////-^-Define things :D-^-/////

/////-v-Intergers-v-/////
int midpoint;
/////-^-Intergers-^-/////

/////-v-Voids-v-/////
void forward(int speed);
void reverse(int speed);
void left(int tspeed);
void right(int tspeed);
void GetMidpoint();
void turnCW();
void turnCCW();
/////-^-Voids-^-/////

//track_update, track_count, track_x,track_y

int main() //ALSO also for Ben
{
	
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

void forward(int speed)
{
	mav(motorL, speed);
	mav(motorR, speed);
}

void reverse(int speed)
{
	mav(motorL, -speed);
	mav(motorR, -speed);
}

void left(int tspeed)
{
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
}

void right(int tspeed)
{
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
}

void GetMidpoint() //Get midpoint for the x-coordinate of the luggage carts
{
	track_update();
	midpoint = (track_x(0, 0) + track_x(2, 0)) / 2;
}
