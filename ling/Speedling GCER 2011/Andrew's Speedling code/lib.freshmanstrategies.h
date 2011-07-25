void run_strategy();

void run_strategy(int strategy) {

if(strategy == 1) 	//Luggage
{
	toTouch(400);
}

if(strategy == 2) //Tower 
{
	int i = 0;
	while (1) {
	toTouch(500);
		if(i%2 == 0) {
	spinCCW_90();
		}
		else {
	spinCW_90();
		}
		i++;
	
	}
}

if(strategy == 3) //Biofuels
{
	claw_down();
	sleep(2);
	claw_up();
	sleep(2);
	claw_down();
	sleep(2);
	claw_up();
	sleep(2);
	claw_down();
	sleep(2);
	claw_up();
	sleep(2);
	
}

if(strategy == 4) //Center gaurd
{
	claw_up();
	sleep(1);
	toTouch(1000);
		set_servo_position(2, 1300);
	sleep(1);
	spinCW_90();
	spinCCW_90();	
}
}
