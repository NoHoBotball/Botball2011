#include "lib.Initialize.h" //Combo of forward, backward, left and right movement

void start(); //Moves Crackling to tape and crosses after 30 seconds
void strategy_1(); //Lugguage carts
void strategy_2(); //Tower tip
void strategy_3(); //Biofuel block
void strategy_4(); //Center patrol
void strategy_5(); //Center block
void strategy_6(); //Tower to biofuel

void start()
{
	float time1 = seconds();
	sleep(0.5);
	straightTape(250, 100);
	sleep(0.5);
	straightOff(250, 100);
	sleep(18);
	forwardT(1000, 6);
	stop();
	sleep(0.5);
	spinCW_degrees(1000, 90);
	stop();
	sleep(0.5);
	if (leftIR > threshold || rightIR > threshold)
	{
		reverseOffTape(250, 100);
	}
	else
	{
		straightTape(250, 100);
	}
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
	forwardT(500, 2);
	sleep(0.5);
	claw_down();
	sleep(0.5);
	straightOff(500, 250);
}

void strategy_1() //Luggage carts
{
	start();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	forwardT(1000, 1.5);
	drop_airplanes();
	sleep(0.5);
	forwardT(1000, 1);
	sleep(0.5);
	hold_airplanes();
	sleep(0.5);
	float time1 = seconds();
	toTouch(1000);
	float time2 = seconds();
	if (time2 - time1 < 2.5)
	{
		while(1)
		{
			stop();
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
	claw_up();
	sleep(0.5);
	forwardT(1000,1.5);
	drop_airplanes();
	sleep(0.7);
	forwardT(1000, 1.02939109);
	stop();
	//claw_up();
	hold_airplanes();
	sleep(0.5);
	spinCCW_degrees(1000, 92);
	stop();
	sleep(0.5);
	forwardT(1000, 3);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	/*
	reverseT(1000, 2);
	stop();
	sleep(0.5);
	spinCCW_degrees(1000, 180);
	stop();
	sleep(0.5);
	forwardT(1000, 3);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCW_degrees(1000, 45);
	stop();
	sleep(0.5);
	spinCCW_degrees(1000, 45);
	stop();
	sleep(0.5);
	reverseT(1000, 3);
	*/
	stop();
	sleep(120);
}

void strategy_3() //Biofuel block
{
	start();
	sleep(0.5);
	forwardT(1000,1.5);
	drop_airplanes();
	sleep(0.5);
	forwardT(1000, 2);
	hold_airplanes();
	stop();
	sleep(0.5);
	spinCCW_degrees(1000, 90);
	stop();
	sleep(0.5);
	forwardT(1000,2);
	sleep(0.5);
	straightTape(500, 250);
	sleep(0.5);
	reverseT(500, 0.5);
	stop();
	sleep(.5);
	spinCW_degrees(1000, 86);
	stop();
	sleep(0.5);
	bothToTape(500);
	stop();
	claw_up();
	sleep(.5);
	forwardT(1000, 1.7);
	stop();
	/*while(1)
	{
		reverseT(1000, 1.5);
		stop();
		sleep(0.5);
		forwardT(1000, 1.2);
		stop();
		sleep(0.5);
	}
	*/
}

void strategy_4() //Center patrol
{
	start();
	forwardT(250, 3);
	stop();
	sleep(0.5);
	claw_up();
	spinCCW_degrees(1000, 90);
	stop();
	sleep(0.5);
	reverseT(1000, 1.5);
	stop();	
	drop_airplanes();
	sleep(0.7);
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
	sleep(0.5);
	forwardT(1000, 1.5);
	sleep(0.5);
	drop_airplanes();
	sleep(0.5);
	forwardT(1000, 1);
	stop();
	claw_up();
	hold_airplanes();
	sleep(0.5);
	spinCCW_degrees(1000, 200);
	stop();
	sleep(0.5);
	claw_down();
	sleep(0.5);
	while(1)
	{
		if (abs(accel_x()) >= 90)
		{
			reverse(1000);
		}
		if (abs(accel_x()) < 90)
		{
			stop();
		}	
	}
}

void strategy_6() //Tower Tip -> Biofuel Block
{
	start();
	sleep(0.5);
	forwardT(1000, 1);
	sleep(0.5);
	drop_airplanes();
	claw_up();
	sleep(0.5);
	forwardT(1000, 0.3);
	stop();
	sleep(0.5);
	hold_airplanes();
	sleep(0.5);
	spinCCW_degrees(1000, 92);
	stop();
	sleep(0.5);
	forwardT(1000, 4);
	stop();
	claw_down();
	sleep(0.5);
	spinCW_degrees(1000, 90);
	stop();
	sleep(0.5);
	bothToTape(1000);
	stop();
	sleep(0.5);
	forwardT(500, 2);
	sleep(120);
}
