#include "lib.Strategies.h"
void strategySelect();
void runStrategy();

void strategySelect()
{
	printf("Press A for luggage carts\n"); //Strategy 1
	printf("Press B for tower tip\n"); //Strategy 2
	printf("Press <- for biofuel block\n"); //Strategy 3
	printf("Press -> for center patrol\n"); //Strategy 4
	printf("Press ^ for center block\n"); //Strategy 5
	printf("Press v for towers and biofuel\n"); //Strategy 6
	while (black_button() == 0 || strategy  < 1)
	{
		while (a_button() == 1 && strategy != 1)
		{
			printf("You picked luggage carts\n");
			printf("Press black button to confirm\n");
			strategy = 1;
			while (a_button() == 1)
			{
			
			}
		}
		while (b_button() == 1 && strategy != 2)
		{
			printf("You picked tower tip\n");
			printf("Press black button to confirm\n");
			strategy = 2;
			while (b_button() == 1)
			{
			
			}
		}
		if (left_button() == 1 && strategy != 3)
		{
			printf("You picked biofuel block\n");
			printf("Press black button to confirm\n");
			strategy = 3;
			while (left_button() == 1)
			{
			
			}
		}
		if (right_button() == 1 && strategy != 4)
		{
			printf("You picked center patrol\n");
			printf("Press black button to confirm\n");
			strategy = 4;
			while (right_button() == 1)
			{
			
			}
		}
		if (up_button() == 1 && strategy != 5)
		{
			printf("You picked center block\n");
			printf("Press black button to confirm\n");
			strategy = 5;
			while (up_button() == 1)
			{
			
			}
			
		}
		if (down_button() == 1 && strategy != 6)
		{
			printf("You picked tower tip to biofuel block\n");
			printf("Press black button to confirm\n");
			strategy = 6;
			while (down_button() == 1)
			{
			
			}
			
		}
	}
	sleep(1);
	cbc_display_clear();
	printf("Running strategy %d\n", strategy);
}

void runStrategy()
{
	shut_down_in(119);
	if (strategy == 1)
	{
		strategy_1();
	}
	
	if (strategy == 2)
	{
		strategy_2();
	}
	
	if (strategy == 3)
	{
		strategy_3();
	}

	if (strategy == 4)
	{
		strategy_4();
	}
	if (strategy = 5)
	{
		strategy_5();
	}
	if (strategy = 6)
	{
		strategy_6();
	}
}
