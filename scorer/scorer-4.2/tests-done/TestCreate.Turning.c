#define CreateDiameter inchestomm(10.375);
float inchestomm(float inches);
int main()
{
	create_connect();
	create_full();
	while(1)
	{
		
		if(a_button ()==1)
		{
			printf("testing with create_drive");
			create_drive(101.3,1);  //uses int. does it round?
			sleep(2.057252314);
			create_stop();
		}
		if (black_button ()==1)
		{
			set_create_total_angle(0);
			create_drive(101.3,1);  //uses int. does it round?
			sleep(2.057252314);
			create_stop();
			get_create_total_angle(.1);
			printf("asdb");
			if (get_create_total_angle(.1) != 90)
			{
				set_create_total_angle(get_create_total_angle(.1) - 90);
				printf("dfsf");
				if (get_create_total_angle(.1) > 0) //CCW ADDS TO TOTAL ANGLE
				{
					create_spin_CW(200);
					while (get_create_total_angle(.1) < 0);
					{
						printf("aeqweqw");
					}
				}
				if (get_create_total_angle(.1) < 0)
				{
					create_spin_CCW(200);
					while (get_create_total_angle(.1) > 0);
					{
						printf("BBBB");
					}
				}
				create_stop();
			}
		}
		
		if (b_button()==1)
		{
			set_create_total_angle(0);
			printf("A");
			sleep(1);
			create_spin_CCW(50);;
			while (get_create_total_angle(0.01) < 90);
			{
				printf("B");
			}
			create_stop();
			printf("C");
		}
	}
}

float inchestomm(float inches)
{
	float mm;
	mm = (inches*25.4);
	return mm;
}
