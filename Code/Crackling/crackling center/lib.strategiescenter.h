#include "lib.Advanced movement.h" //Combo of forward, backward, left and right movement

void start(); //Moves Crackling to tape and crosses after 30 seconds
void strategy_1(); //Lugguage carts
void strategy_2(); //Tower tip
void strategy_3(); //Biofuel block
void strategy_4(); //Center patrol
void strategy_5(); //Center block

void start()
{
	float time1 = seconds();
	claw_down();
	sleep(0.5);
	forwardT(100, 0.1);
	sleep(0.4);
	straightTape(250, 100);
	sleep(4);
	straightOff(250, 100);
	sleep(1);
	straightTape(550, 100);
	claw_up();
	sleep(0.5);
	spinCW_degrees(1000, 80);
	sleep(0.5);
	forwardT(1000, 6.5);
	sleep(1);
	spinCW_degrees(1000, 78);
	sleep(0.5);
	forwardT(1000, 1);
	sleep(0.5);
	claw_down();
	sleep(0.5);
	straightTape(200, 150);
	sleep(0.5);
	claw_up();
	float time2 = seconds();
	float time3 = time2 - time1;
	while (time3 < 30)
	{
		time2 = seconds();
		time3 = time2 - time1;
	}
	beep();
	sleep(0.5);
	forwardT(500, 2);
	claw_down();
	sleep(0.5);
	straightOff(500, 250);
	//dropPlane();
}

void strategy_1() //Luggage carts
{
	start();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	float time1 = seconds();
	toTouch(1000);
	float time2 = seconds();
	if (time2 - time1 < 5)
	{
		while(1)
		{
			stop();
			ao();
		}
	}
	stop();
	sleep(.5);
	claw_down();
	sleep(0.5);
	reverseT(1000, 3);
	sleep(0.5);
	while (1)
	{
		spinCW_time(1000, 5);
		spinCCW_time(1000, 5);
	}
}

void strategy_2() //Tower tip
{
	start();
	sleep(0.6);
	claw_up();
	sleep(0.5);
	forwardT(1000, 2.1493567);
	stop();
	sleep(0.5);
	spinCCW_degrees(1000, 90);
	sleep(0.5);
	forwardT(1000, 2.5);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCW_degrees(1000, 180);
	sleep(0.5);
	forwardT(1000, 5);
	stop();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	beep();
	ao();
	//spinCW_degrees(1000, 90);
}

void strategy_3() //Biofuel block
{
	start();
	forwardT(500, 5);
	sleep(0.5);
	spinCCW_degrees(1000, 86);
	sleep(0.5);
	forwardT(1000,1);
	toTape(500);
	sleep(0.5);
	reverseT(200, 1);
	sleep(.5);
	spinCW_degrees(1000, 89);
	sleep(0.5);
	bothToTape(600);
	claw_up();
	sleep(.5);
	forwardT(1000,1.3);
ao();
	
	/*while(1)
	{
		reverseT(1000, 1.5);
		stop();
		sleep(0.5);
		forwardT(1000, 1.2);
		stop();
		sleep(0.5);
	}*/
	
}

void strategy_4() //Center patrol
{
	start();
	forwardT(250, 2.5);
	sleep(0.5);
	claw_up();
	spinCCW_degrees(1000, 90);
	reverseT(1000, 1.5);
	while (1)
	{
		forwardT(1000, 3.5);
		sleep(0.5);
		reverseT(1000, 3.5);
		sleep(0.5);
	}
}

void strategy_5() //Center block
{
	start();
	forwardT(500, 1.5);
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCCW_degrees(1000, 220);
	sleep(0.5);
	claw_down();
	sleep(0.5);
	while(1)
	{
		if (abs(accel_x()) > 90)
		{
			reverse(1000);
		}
	}
}

void strategy_6() { //Tower Tip > Biofuel Block



	}
