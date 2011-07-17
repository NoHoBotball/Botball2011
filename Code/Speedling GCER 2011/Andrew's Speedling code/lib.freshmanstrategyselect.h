void strategySelect();


void strategySelect()
{
	printf("Press A to move until touch\n"); //Strategy 1
	printf("Press B for z movement\n"); //Strategy 2
	printf("Press <- to move claws up and down\n"); //Strategy 3
	printf("Press -> to knock over towers\n"); //Strategy 4
	while (black_button() == 0)
	{
		while (a_button() == 1 && strategy != 1)
		{
			printf("You chose to move until touch\n");
			printf("Press black button to confirm\n");
			strategy = 1;
			while (a_button() == 1)
			{
			
			}
		}
		while (b_button() == 1 && strategy != 2)
		{
			printf("You chose z movement\n");
			printf("Press black button to confirm\n");
			strategy = 2;
			while (b_button() == 1)
			{
			
			}
		}
		if (left_button() == 1 && strategy != 3)
		{
			printf("You chose claw movement\n");
			printf("Press black button to confirm\n");
			strategy = 3;
			while (left_button() == 1)
			{
			
			}
		}
		if (right_button() == 1 && strategy != 4)
		{
			printf("You chose to knock over towers\n");
			printf("Press black button to confirm\n");
			strategy = 4;
			while (right_button() == 1)
			{
			
			}
		}
	}
	sleep(1);
	cbc_display_clear();
	printf("Running strategy %d", strategy);
}
