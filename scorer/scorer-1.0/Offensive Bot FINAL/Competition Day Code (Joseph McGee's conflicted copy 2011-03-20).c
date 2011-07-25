/*
####### ####### ####### ####### #     #  #####  ### #     # ####### 
#     # #       #       #       ##    # #     #  #  #     # #       
#     # #       #       #       # #   # #        #  #     # #       
#     # #####   #####   #####   #  #  #  #####   #  #     # #####   
#     # #       #       #       #   # #       #  #   #   #  #       
#     # #       #       #       #    ## #     #  #    # #   #       
####### #       #       ####### #     #  #####  ###    #    ####### 
                                                                    
######  ####### ####### 
#     # #     #    #    
#     # #     #    #    
######  #     #    #    
#     # #     #    #    
#     # #     #    #    
######  #######    #  

####### ####### #     # 
#          #    #  #  # 
#          #    #  #  # 
#####      #    #  #  # 
#          #    #  #  # 
#          #    #  #  # 
#          #     ## ##  
*/

//////-v-#Defines-v-/////
#define motorL 1
#define motorR 0
#define drag 10 //Used to slow down the right wheel
#define IR_right analog(4) //Top hat on right claw
#define IR_left analog(6) //Top hat on left claw
#define touch digital(12) //Touch sensor
#define right 0
#define left 1
/////-^-#Defines-^-/////

/////-v-Variables-v-/////
int strategy = 0;
int IR; 
float threshold = 190; //Used to differentiate between white board and black tape
char Side;
/////-^-Variables-^-/////

/////-v-Function prototypes-v-/////
void forward(int speed);
void reverse(int speed);
void forwardP(int speed);
void reverseP(int speed);
void forwardT(int speed, float seconds);
void reverseT(int speed, float seconds);
void stop();
void CW(); //Clockwise
void CCW(); //Counter-clockwise
void CCW80();
void CW180();
void CCW180();
void onlyLeft(int speed);
void onlyRight(int speed);
void turnStraight(int speed, int tspeed);
void toTouch(int speed);
void toTape(int speed);
void offTape(int speed);
void claw_up();
void claw_down();
void whichSide();
void strategySelect();
void biofuel_block();
void tower_tip();
void bordercross();
void patrol();
void strategy_1();
void strategy_2();
void strategy_3();
void strategy_4();
/////-^-Function prototypes-^-/////
void countdown();
void Luggagecartcafe();
void IRcross();
int sr, sl; 


int main()
{
	enable_servos();
	claw_down();
	
	whichSide();
	
	strategySelect();
	
	wait_for_light(7);
	
	if (strategy == 1)
	{
		printf("Running luggage carts...\n");
		run_for(117, strategy_1);
		start_process(*countdown);
	}
	
	if (strategy == 2)
	{
		printf("Running tower tip...\n");
		run_for(117, strategy_2);
		start_process(*countdown);
	}
	
	if (strategy == 3)
	{
		printf("Running biofuel block...\n");
		run_for(117, strategy_3);
		start_process(*countdown);
	}
	
	if (strategy == 4)
	{
		printf("Running center defense...\n");
		run_for(117, strategy_4);
		start_process(*countdown);
	}
	
}

/////-v-Function definitions-v-/////
void forward(int speed)
{
	mav(motorL, speed);
	mav(motorR, speed - drag);
}

void forwardP(int speed)
{
	mav(motorL, speed);
	mav(motorR, speed);
}

void reverseP(int speed)
{
	mav(motorL, -speed);
	mav(motorR, -speed);
}

void reverse(int speed)
{
	mav(motorL, -speed);
	mav(motorR, -speed + drag);
}

void forwardT(int speed, float seconds)
{
	
	mav(motorL, speed);
	mav(motorR, speed - drag);
	sleep(seconds);
	freeze(motorL);
	freeze(motorR);
}

void reverseT(int speed, float seconds)
{
	
	mav(motorL, -speed);	
	mav(motorR, -speed + drag);
	sleep(seconds);
	freeze(motorL);
	freeze(motorR);
}

void stop()
{
	freeze(motorL);
	freeze(motorR);
}

void CCW80(){ 
	if (Side == right)
	{
		mav(motorR,700); mav(motorL,-700);
		sleep(0.4);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,-700); mav(motorL,700);
		sleep(0.4);
		stop();
	}
}	
 

void CW()
{ 
	if (Side == right)
	{
		mav(motorR,-650); mav(motorL,650);
		sleep(0.48);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,650); mav(motorL,-650);
		sleep(0.46525169);
		stop();
	}
}	

void CCW()
{
	if (Side == right)
	{
		mav(motorR,650); mav(motorL,-650);
		sleep(0.46525169);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,-650); mav(motorL,650);
		sleep(0.48);
		stop();
	}
	
}	

void CW180()
{
	if (Side == right)
	{
		mav(motorR,-700); mav(motorL,700);
		sleep(0.959998);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,700); mav(motorL,-700);
		sleep(0.92);
		stop();
	}
}

void CCW180()
{
	if (Side == right)
	{
		mav(motorR,700); mav(motorL,-700);
		sleep(0.92);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,-700); mav(motorL,700);
		sleep(0.959998);
		stop();
	}
}
void spinCCW(speed) {
	if (Side == right)
	{
		mav(1,-speed);
		mav(0,speed);
	}
	if (Side == left)
	{
		mav(1,speed);
		mav(0,-speed);
	}
	
	
} 
void spinCW(speed) {
	if (Side == right)
	{
		mav(1,speed);
		mav(0,-speed);
	}
	if (Side == left)
	{
		mav(1,-speed);
		mav(0,speed);
	}
}
void onlyLeft(int speed)
{
	mav(motorL, speed);
}

void onlyRight(int speed)
{
	mav(motorR, speed);
}

void turnStraight(int speed, int tspeed)
{
	while (IR_left < threshold || IR_right < threshold)
	{
		forwardP(speed);			
		if(IR_left > threshold && IR_right < threshold)
		{
			stop();
			onlyRight(tspeed);
			while (IR_left > threshold && IR_right < threshold)
			{}
			stop();
		}
		if (IR_left < threshold && IR_right > threshold)
		{
			stop();
			onlyLeft(speed);
			while (IR_left < threshold && IR_right > threshold)
			{}
			stop();
		}
	}
	stop();
}

void toTouch(int speed)
{
	forward(speed);
	while (touch == 0)
	{}
	stop();
}

void toTape(int speed)
{
	forward(speed);
	while(IR_left < threshold && IR_right < threshold)
	{}
	stop();
}

void offTape(int speed)
{
	forward(speed);
	while (IR_left > threshold || IR_right > threshold)
	{}
	stop();
}

void claw_up()
{
	set_servo_position(1, 700);
}

void claw_down()
{
	set_servo_position(1, 2000);
}

void whichSide() 
{
	printf ("Select orientation of the robot compared to botguy.\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (b_button() == 0 && a_button() == 0)
	{
		
	}
	if (b_button() == 1)
	{
		Side = right;
		cbc_display_clear();
		printf ("Robot is on right of botguy.\n");
		sleep(1);
	}
	if (a_button() == 1)
	{
		Side = left;
		cbc_display_clear();
		printf ("Robot is on left of botguy.\n");
		sleep(1);
	}
	
	if (Side == right)
	{
		sr = 4;
		sl = 6;
	}
	if (Side == left)
	{
		sr = 6;
		sl = 4;
	}
}

void strategySelect()
{
	printf("Press A for luggage carts\n"); //Strategy 1
	printf("Press B for tower tip\n"); //Strategy 2
	printf("Press <- for biofuel block\n"); //Strategy 3
	printf("Press -> for center defense\n"); //Strategy 4
	while (black_button() == 0)
	{
		if (a_button() == 1)
		{
			printf("You picked luggage carts\n");
			printf("Press black button to confirm\n");
			strategy = 1;
		}
		if (b_button() == 1)
		{
			printf("You picked tower tip\n");
			printf("Press black button to confirm\n");
			strategy = 2;
		}
		if (left_button() == 1)
		{
			printf("You picked biofuel block\n");
			printf("Press black button to confirm\n");
			strategy = 3;
		}
		if (right_button() == 1)
		{
			printf("You picked center defense\n");
			printf("Press black button to confirm\n");
			strategy = 4;
		}
	}
}

void patrol()
{
	int i = 0;
	while (i <= 30) //Maybe I should change?
	{
		reverseT(700, 2);
		sleep(0.2);
		forwardT(700, 2);
		sleep(0.2);
		i++;
	}
}

void biofuel_block()
{
	CW();
	sleep(0.5);
	
	forwardT(500, 3.2);
	sleep(0.5);
	
	claw_down();
	sleep(0.5);	
	turnStraight(500, 250);
	sleep(0.1);
	
	claw_up();
	forwardT(100, 2);
	sleep(1);
	CCW();
	
	forwardT(300, 2.5);
	sleep(0.1);
	patrol();
}

void tower_tip()
{
	claw_down();
	sleep(1);
	while (analog(sr) <= 190) {
		spinCW(200);
	}
	ao();
	spinCCW(200);
	sleep(.2);
	ao();
	set_servo_position(1, 1200);
	sleep(1);
	
	forwardT(1000,1.5);
	set_servo_position(1,900);
	sleep(0.5);
	reverseT(1000, 1);

	CCW();
	claw_down();
	sleep(1);
	forwardT(800,.8);
	CW();
	while (analog(sr) <=190 && analog(sl) <= 190) { 
		forward(600); }
		ao();
	reverseT(600,.3);
	CCW();
	while (analog(sr) <=190 && analog(sl) <= 190) { 
		forward(600); }	
		ao();
		CCW();		
		
}

void center_defense()
{
	/*CW180();
	sleep(0.5);
	claw_down();
	sleep(0.5);
	turnStraight(200, 100);
	forwardT(100, 1);
	CCW();
	
	claw_down();
	sleep(1);
	
	while (analog(sr) <= 190) {
		spinCW();
	}
	if(analog(sl) <= 190) {
	ao();
	claw_up();
	sleep(1);
	*/
	claw_down();
	sleep(1);
	while (analog(sr) <= 190) {
		spinCW(200);
	}
	ao();
	spinCCW(200);
	sleep(.2);
	ao();
	patrol();
	}

void IRcross()
{
	forwardT(700,1);
	claw_down();
	sleep(0.8);

	while (analog(sl) <= 190) 
	{
		forward(750); }
		forward(750);
		sleep(.76);
		CCW80();
		//spinCCW();
		//sleep(0.2);
		ao();
		claw_up();
		sleep(.5);
	    sleep(12);
		ao();
		while (analog(sr) <= 190 && analog(sl) <= 190) {
			forward(700);
		}
		set_servo_position(1,1850);
		sleep(0.5);
		while(analog(sr) >=190 || analog(sl) >= 190){
			forward(450);
		}
		
		/*sleep(0.15);
		ao();
	fd(0);
	mav(1,600);
		//fd(1);	
	sleep(.7);
	
	fd(1);
	mav(0, 600);
	sleep(.7);
		*/
		
		ao();
		claw_down();
		sleep(0.5);
		if(analog(sr) >= 190 && analog(sl) >= 190)
		{
			claw_up();
			sleep(0.5);
	fd(0);
	fd(1);	
	sleep(2);
		}
		claw_down();
		sleep(0.5);
		if(analog(sr) >= 190 && analog(sl) >= 190)
		{
			claw_up();
			sleep(.5);
			reverse(800);
			sleep(0.3);
			fd(0);
			mav(1, -400);
			sleep(.5);
			ao();
		
			fd(1);
			mav(0, -400); 
			sleep(.5);
			ao();
		}
		if(analog(sr) >=190 && analog(sl) >= 190)
		{
			while(1) {
				ao();
			}
		}
	
}

void bordercross()
{
	float sec1 = seconds();
	float sec2;
	float sec3;
	claw_up();
	sleep(0.5);
	toTouch(500);
	sleep(0.2);
	reverseT(500, 0.5);
	sleep(1);
	CCW();
	sleep(1);
	forwardT(1000, 3);
	sleep(0.5);
	CCW();
	reverseT(500, 1);
	sec2 = seconds();
	sec3 = sec2 - sec1;
	while (sec3 < 15)
	{
		sec2 = seconds();
		sec3 = sec2 - sec1;
	}
	beep();
	forwardT(1000, 6);
	sleep(0.3);
	claw_down();
	sleep(1);
	if(IR_left > threshold && IR_right > threshold)
	{
		while (1)
		{
			ao();
		}
	}
	sleep(1);
	claw_up();
	sleep(0.5);
	reverseT(500, 1.5);
	sleep(1);
}

void strategy_1() //Luggage
{
	IRcross();
	Luggagecartcafe();
}

void strategy_2() //Tower 
{
	IRcross();
	tower_tip(); 
}

void strategy_3() //Biofuels
{
	IRcross();
	biofuel_block();
}

void strategy_4() //Center gaurd
{
	IRcross();
	center_defense();
	
}

/////-^-Function definitions-^-/////
void countdown()
{
	float timeBegin = seconds();
	while (120 - (seconds() - timeBegin) > 20){}
	printf("Shut down in:\n");
	while(1)
	{
		printf("%2.0f\t", (120 - (seconds() - timeBegin)));
		sleep(0.950);
	}
}
void Luggagecartcafe()
{
	claw_down();
	sleep(1);
	while (analog(sr) <= 190) {
		spinCW(200);
	}
	ao();
	CCW(); 
	while (digital(12) == 0)  { 
		forward(600);
		}
	claw_down(); 
	sleep(.5);
	ao();
	
	
	
	
	/*
	enable_servos();
	set_servo_position(1,200);
	track_update();
	int X = 69;
	if (track_x(0,0) < track_x(2,0)) //Pink on left
	{
		track_update();
		while (track_x (0,0) > X+5 || track_x (0,0) < X-5)
		{
			if (track_x(0, 0) > X+5)
			{
				while(track_x(0,0) > X)
				{
					track_update();
					spinCCW(250);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(0, 0) < X)
				{
					track_update();
					spinCW(250);
				}
				ao();
			}
		}
		
	}
	else  if (track_x(2,0) < track_x(0,0)) //Pink on left
	{
		track_update();
		while (track_x (2,0) > X+5 || track_x (2,0) < X-5)
		{
			if (track_x(2, 0) > X+5)
			{
				while(track_x(2,0) > X+5)
				{
					track_update();
					spinCCW(250);
				}	
				ao();	
			}
			else // (track_x(0,0) < X)
			{
				while (track_x(2, 0) < X-5)
				{
					track_update();
					spinCW(250);
				}
			}
		}
		
	}
	*/
}
