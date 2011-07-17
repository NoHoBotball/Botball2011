int main()
{
	create_connect();
	float x=.45;
	if(black_button() == 1)
	{
		create_drive_straight(-100);
		sleep(10);
		create_stop();
	}
	while(left_button() == 0) 
	{
		while(black_button() == 0)
		{
			if (a_button() == 1)
			{
				x=x+.001;
				printf("%f\n", x);
				sleep(.5);
			}
			if (b_button() == 1)
			{
				x=x-.001;
				printf("%f\n", x);
				sleep(.5);
			}
			if (up_button() == 1)
			{
				x=x+.0001;
				printf("%f\n", x);
				sleep(.5);
			}
			if (down_button() == 1)
			{
				x=x-.0001;
				printf("%f\n", x);
				sleep(.5);
			}
		}
		create_spin_CW(450);
		sleep(x);
		create_stop();
	}
}
