/*
Ctrl + F to find penis and replace with a strategy
samething for vagina and titties
*/

//There is a MUCH easier way to do this with arrays, but I was too lazy to do it

int strategy;

int main()
{
	printf("Press A for penis, B for vagina, or black button for titties!\n");
	while(a_button() == 0 || b_button() == 0 || black_button() == 0)
	{
		if(a_button() == 1)
		{
			strategy = 1;
		}
		if(b_button() == 1)
		{
			strategy = 2;
		}
		if(black_button() == 1)
		{
			strategy = 3;
		}
	}
	
	sleep(0.5);
	
	if (strategy == 1)
	{
		printf("You picked penis as your first strategy, press B for vagina or black button for titties next\n");
		while(b_button() == 0 || black_button() == 0)
		{
			if (b_button() == 1)
			{
				strategy = strategy * 10 + 2;
			}
			if (black_button() == 1)
			{
				strategy = strategy * 10 + 3;
			}
		}
	}
	if (strategy == 2)
	{
		printf("You picked vagina as your first strategy, press A for penis or black button for titties next\n");
		while(a_button() == 0 || black_button() == 0)
		{
			if (a_button() == 1)
			{
				strategy = strategy * 10 + 1;
			}
			if (black_button() == 1)
			{
				strategy = strategy * 10 + 3;
			}
		}
	}
	if (strategy == 3)
	{
		printf("You picked titties as your first strategy, press A for penis or B for vagina next\n");
		while(a_button() == 0 || b_button() == 0)
		{
			if (a_button() == 1)
			{
				strategy = strategy * 10 + 1;
			}
			if (b_button() == 1)
			{
				strategy = strategy * 10 + 2;
			}
		}
	}
	
	if (strategy - 1 / 10 == 2)
	{
		strategy = 213;
	}
 //Someone else can finish the rest :l
}
