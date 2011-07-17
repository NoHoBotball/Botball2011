void demo();

void demo()
{
	printf("a to raise arm, b to lower arm, up to auto drive");
	while (black_button() ==0)
	{
		if(a_button() == 1)
		{
			armUp();
		}
		if(b_button() == 1)
		{
			armDown();
		}
		if(up_button() ==1)
		{
			printf("Up_button to exit.");
			create_demo(1);
			while(up_button()==0)
			{}
			create_stop();
			cbc_display_clear();
		}
	}
}
