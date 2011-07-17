//Offensive Bot Ver 3.1.4.159//
/////-v-Define things :D-v-/////
//#define motorL 1//Left motor
//#define motorR 0//Right motor
#define X 70 //60
#define rightX 100
/////-^-Define things :D-^-/////

/////-v-Void-v-/////

void LuggageTrack();
/////-^-Void-^-/////

//track_update, track_count, track_x,track_y

void LuggageTrack()
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
					spinCCW(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X-5)
				{
					track_update();
					spinCW(100);
				}
			}
		}
		ao();
		drive(500);
		while (TouchSensor == 0)
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
					spinCCW(100);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-5)
				{
					track_update();
					spinCW(100);
				}
			}
		}
		ao();
		drive(500);
		while (TouchSensor == 0)
		{}
		ao();
		set_servo_position(1,800);
	}
}



