//Offensive Bot Ver 3.1.4.159//

/////-v-Define things :D-v-/////
#define motorL 3//Left motor
#define motorR 0//Right motor
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
/////-^-Voids-^-/////

//track_update, track_count, track_x,track_y

int main()
{
	printf("Press A to start\n");
	while (a_button() == 0){}
	track_update();
	while (track_count(0) == 0 || track_count(2) == 0)
	{
		track_update();
		right(300);
	}
	
	GetMidpoint();
	while (b_button() == 0) //Later, insert a function to know that it's touching the barrels
	{
		GetMidpoint();
		if (midpoint > 80)
		{
			right(200);
		}
		if (midpoint < 79)
		{
			left(200);
		}
		forward(350);
	}
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
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
}

void right(int tspeed)
{
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
}

void GetMidpoint() //Get midpoint for the x-coordinate of the luggage carts
{
	track_update();
	midpoint = (track_x(0, 0) + track_x(2, 0)) / 2;
}
