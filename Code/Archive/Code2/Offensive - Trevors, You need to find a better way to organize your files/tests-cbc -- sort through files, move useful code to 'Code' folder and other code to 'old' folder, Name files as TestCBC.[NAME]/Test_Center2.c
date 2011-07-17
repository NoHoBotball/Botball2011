//Offensive Bot Ver 3.1.4.159//

/////-v-Define things :D-v-/////
#define motorL 3//Left motor
#define motorR 0//Right motor
#define X 70 //60
#define rightX 100
/////-^-Define things :D-^-/////

/////-v-Void-v-/////
void forward(int speed);
void reverse(int speed);
void left(int tspeed);
void right(int tspeed);
/////-^-Void-^-/////

//track_update, track_count, track_x,track_y

int main()
{
	enable_servos();
	set_servo_position(1,0);
	track_update();
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
					left(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X-5)
				{
					track_update();
					right(100);
				}
			}
		}
		ao();
		forward(500);
		while (a_button() == 0)
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
					left(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-5)
				{
					track_update();
					right(100);
				}
			}
		}
		ao();
		forward(500);
		while (a_button() == 0)
		{}
		ao();
		set_servo_position(1,800);
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
