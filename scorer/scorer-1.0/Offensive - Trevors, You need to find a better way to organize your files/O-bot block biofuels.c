//Offensive Bot Ver 3.1.4.159//

/////-v-Define things :D-v-/////
#define motorL 0//Left motor
#define motorR 3//Right motor
#define IR analog(7)
#define threshold 512//Threshold for the IR sensor, 60 is white 850 is black
/////-^-Define things :D-^-/////

/////-v-Intergers-v-/////
int counter = 0;
/////-^-Intergers-^-/////

/////-v-Voids-v-/////
void forward(int speed);
void reverse(int speed);
void left(int tspeed);
void right(int tspeed);
void GetMidpoint();
/////-^-Voids-^-/////

int main()
{
	float time1, time2;
	printf("Press A to start\n");
	while (a_button() == 0)
	{
		//When we have a light sensor, replace with wait_for_light
	} 
	
	time1 = seconds();
		forward(350);
	while (counter < 2)
	{
		while (IR > threshold)
		{
			counter = counter + 1;
			printf("counter is %d", counter);
			while(IR > threshold)
			{
				forward(350);
			}
		}
	}
	ao();
	
	if ((time2 - time1) < 15)
	{
		time2 = seconds();
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
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
}

void right(int tspeed)
{
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
}
