void dance();
int danceFor (int time);

void dance()
{
	create_connect();
	/*printf("How many times do I repeat? Up is +1, Down is -1, B to start");
	while(b_button() == 0)
	{
		if (up_button() == 1)
		{
			counter ++;
			printf("%d\n", counter);
		}
		if (down_button() ==1)
		{
			counter --;
			printf("%d\n", counter);
		}
		if (a_button() == 1)
		{
			armUp();
		}
		if (b_button() == 1)
		{
			armDown();
		}
	}*/
		create_spin_CCW(100);
		armUp();
		while (get_servo_position(SERVO_ARM_LEFT_PORT) > SERVO_ARM_LEFT_UP)
		{}
		create_stop();
		create_spin_CW(100);
		armDown();
		while (get_servo_position(SERVO_ARM_LEFT_PORT) < SERVO_ARM_LEFT_DOWN)
		{}
		create_stop();
		//counter --;
}

int danceFor(int time)
{
	run_for(time, dance);
}
