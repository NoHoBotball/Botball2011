#include "lib.Advanced movement.h" //Combo of forward, backward, left and right movement

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
	claw_down();
	sleep(0.5);
	/*forwardT(250, 0.1);
	sleep(0.4);
	straightTape(250, 100);
	sleep(2);
	straightOff(250, 100);
	sleep(1);
	*/    
	forwardT(1000,0.75);
	stop();
	sleep(10);
	forwardT(1000, 6.8);
	spinCW_degrees(1000,80);
	sleep(0.5);
	straightTape(300, 400);
	sleep(0.5);
	//reverseOffTape(50, 150);
	claw_up();
	float time2 = seconds();
	float time3 = time2 - time1;
	/*while (time3 < 30)
	{
		time2 = seconds();
		time3 = time2 - time1;
	}
	*/
	beep();
	claw_down();
	sleep(0.5);
	forwardT(500, 1.7);
}

void strategy_1() //Luggage carts
{
	start();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	float time1 = seconds();
	forwardT(1000, 4); 
	float time2 = seconds();
	if (time2 - time1 < 5)
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
	stop();
	straightOff(400, 400);
	stop();	
	forwardT(1000,1.5);
	drop_airplanes();
	sleep(0.7);
	forwardT(1000, 1.02939109);
	stop();
	claw_up();
	sleep(0.5);
	hold_airplanes();
	sleep(0.5);
	spinCCW_degrees(1000, 95);
	sleep(0.5);
	forwardT(1000, 2);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCW_degrees(1000, 181);
	sleep(0.5);
	forwardT(1000, 5.2);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCCW_degrees(1000, 20);
	spinCW_degrees(1000, 20);
	beep();
	reverseT(1000,0.999);
	ao();
	sleep(1200);
	//spinCW_degrees(1000, 90);
}

void strategy_3() //Biofuel block
{
	start();
	straightOff(400, 400);
	stop();	
	forwardT(1000,1.5);
	drop_airplanes();
	sleep(0.7);
	forwardT(1000, 2);
	sleep(0.5);
	spinCCW_degrees(1000, 90);
	sleep(0.5);
	forwardT(1000,2);
	toTape(500);
	reverseT(500, 1);
	sleep(.5);
	spinCW_degrees(1000, 86);
	sleep(0.5);
	while ((leftIR < threshold) && (rightIR < threshold)) {
	forward(500); 
	}
	stop();
	claw_up();
	sleep(.5);
	forwardT(1000, 1.362453463334);
	stop();
	ao();
	sleep(120);
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
	forwardT(500, 1.5);
	stop();	
	drop_airplanes();
	sleep(0.7);
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

void strategy_6() { //Tower Tip -> Biofuel Block
	start();
	stop();
	straightOff(400, 400);
	stop();	
	forwardT(1000,1.5);
	drop_airplanes();
	sleep(0.7);
	forwardT(1000, 1.02939109);
	stop();
	claw_up();
	sleep(0.5);
	hold_airplanes();
	sleep(0.5);
	spinCCW_degrees(1000, 95);
	sleep(0.5);
	forwardT(1000, 2);
	stop();
	claw_down();
	sleep(0.5);
	claw_up();
	sleep(0.5);
	spinCW_degrees(1000, 95);
	forwardT(1000,1.5);
	spinCCW_degrees(1000,94);
	toTape(500);
	reverseT(500, 1);
	sleep(.5);
	spinCW_degrees(1000, 86);
	sleep(0.5);
	bothToTape(500);
	stop();
	claw_up();
	sleep(.5);
	forwardT(1000, 1.362453463334);
	stop();
	ao();
	sleep(120);
	}
