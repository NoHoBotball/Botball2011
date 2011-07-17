//#include "lib.Movement.h" //Forward and backward movement
//#include "lib.Rotation.h" //Left and right movement 
//#include "lib.Advanced movement.h" //Combo of forward, backward, left and right movement
void bordercross();
void biofuel_block();
void center_defense();
void patrol();
void tower_tip();
void strategy_1();
void strategy_2();
void strategy_3();
void strategy_4();
void run_strategy();

void run_strategy(int strategy) {

if(strategy == 1) 	//Luggage
{
	bordercross();
}

if(strategy == 2) //Tower 
{
	bordercross();
	tower_tip(); 
}

if(strategy == 3) //Biofuels
{
	bordercross();
	biofuel_block();
}

if(strategy == 4) //Center gaurd
{
	bordercross();
	center_defense();
	
}
}

void bordercross()
{
	//wait_for_light(7);
	float sec1 = seconds();
	float sec2;
	float sec3;
	/*toTouch(1000);
	reverseT(500, 0.7);	
	spinCCW_180();
	reverseT(500, 0.7);	//hopefully it pushes right against the pipe, straightens itself out
	set_servo_position(0, 1550);//drop airplanes
	claw_down();
	sleep(1.5); 
	*/
	
	forwardT(1000,1);
	toTape_left(1000);
	forwardT(1000,0.5);
	spinCCW_90();
	forwardT(1000,0.5);
	turnStraightonTape(1000,100);
	sec2 = seconds();
	sec3 = sec2 - sec1;
	claw_up();
	sleep(1);
	while (sec3 < 31)
	{
		sec2 = seconds();
		sec3 = sec2 - sec1;
	}
	beep();
	forwardT(1000, 0.6);//crosses bump
	claw_down();
	sleep(1);
	turnStraightoffTape(1000,100);
	offTape(600);
	claw_up();
	sleep(0.5);
	reverseT(500, 1.5);
	sleep(1);
}

void biofuel_block()
{
	//wtf, should just be a 90 degree turn
	spinCW_90();
	forwardT(500, 3.2);
	sleep(0.5);
	claw_down();
	sleep(0.5);	//blocks are knocked over
	turnStraightonTape(500, 250);//what is happening?!
	sleep(0.1);
	claw_up();
	forwardT(100, 2);
	sleep(1);
	spinCCW_90();
	forwardT(300, 2.5);
	sleep(0.1);
	patrol();
}

void center_defense()
{
	//wtf?\\<:-%
	spinCW_180();
	sleep(0.5);
	claw_down();
	sleep(0.5);
	turnStraightonTape(200, 100);
	forwardT(100, 1);
	spinCCW_90();
	patrol();
}

void patrol()
{
	while (1 == 1) //Maybe I should change?
	{
		reverseT(1000, 3);
		sleep(0.2);
		forwardT(1000, 3);
		sleep(0.2);
	}
}

void tower_tip()
{
	//also wtf, should just be a 90 degree turn
	spinCW_90();
	forwardT(500, 3.2);
	sleep(0.5);
	claw_down();
	sleep(0.5);
}
