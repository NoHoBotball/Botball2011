#include "lib.Assignments.h"
//#include "lib.Strategies.h"

void strategySelect();
void runStrategy();

void strategySelect()
{
	printf("Press A for luggage carts\n"); //Strategy 1
	printf("Press B for tower tip\n"); //Strategy 2
	printf("Press <- for biofuel block\n"); //Strategy 3
	printf("Press -> for center defense\n"); //Strategy 4
	while (black_button() == 0)
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
			printf("You picked center defense\n");
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

void runStrategy()
{/*
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
	*/
}
