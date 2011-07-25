//Offensive Bot Ver 3.1.4.159//

/////-v-Define things :D-v-/////
#define motorL 1//Left motor
#define motorR 0//Right motor
#define X 60
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
	/*printf("Press A to start\n");
	while (a_button() == 0)
	{
	
	}
	*/
	/*
	while (track_count(0) > 0 && track_count(2) == 0) //If seeing pink, not green, turn right
	{
	track_update();
	right(250);
	}
	
	while (track_count(2) > 0 && track_count(0) == 0) //If seeing green, not pink, turn left
	{
	track_update();
	left(250);
	}*/
	
	track_update();
	if (track_x(0,0) < track_x(2,0))//track_x(0,0) > X || track_x(2,0) <  rightX)
	{
		//while (track(0,0) < track_x(2,0))//track_x(0,0) > X  || track_x(2,0) < rightX)
		//{
		//int X = 0;
		//int Y=0;
		track_update();
		if (track_x(0, 0) > X)
		{
			while(track_x(0,0) > X)
			{
				track_update();
				left(100);
			}
			//X = X+30;
			
		}
		ao();
		if (track_x(0,0) < X)
		{
			while (track_x(0, 0) < X)
			{
				track_update();
				right(100);
			}
			//Y = Y+30;
		}
		ao();
		//int i = 0;
		while (a_button() == 0)//while (i < 15)
		{
			//printf("%d\n", i);
			//i = i + 1;
			forward(500);
		}
	}
	if (track_x(0,0) > track_x(2,0))
	{
		//while (track(0,0) < track_x(2,0))//track_x(2,0) > X  || track_x(0,0) < rightX)
		//{
		//track_update();
		//	int X = 0;
		//	int Y=0;
		//	if (track_x(0, 0) > X)
		//{
		while(track_x(2,0) > X)
		{
			track_update();
			left(100);
		}
		//X = X+30;
		
		//}
		ao();
		//if (track_x(0,0) < rightX)
		//{
		while (track_x(0, 0) < rightX)
		{
			track_update();
			right(100);
		}
		//Y = Y+30;
		//}
	}
	ao();
	//int i = 0;
	while (a_button() == 0)//while (i < 15)
	{
		//printf("%d\n", i);
		//i = i + 1;
		forward(500);
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
