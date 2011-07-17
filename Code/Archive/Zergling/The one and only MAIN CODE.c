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

int main()
{
	enable_servos();
	claw_down();
	
	whichSide();
	
	strategySelect();
	
	//wait_for_light(7);
	
	if (strategy == 1)
	{
		printf("Running luggage carts...\n");
		run_for(117, strategy_1);
	}
	
	if (strategy == 2)
	{
		printf("Running tower tip...\n");
		run_for(117, strategy_2);
	}
	
	if (strategy == 3)
	{
		printf("Running biofuel block...\n");
		run_for(117, strategy_3);
	}
	
	if (strategy == 4)
	{
		printf("Running center defense...\n");
		run_for(117, strategy_4);
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

void CW()
{ 
	if (Side == right)
	{
		mav(motorR,-700); mav(motorL,700);
		sleep(0.479999);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,700); mav(motorL,-700);
		sleep(0.46);
		stop();
	}
}	

void CCW()
{
	if (Side == right)
	{
		mav(motorR,700); mav(motorL,-700);
		sleep(0.46);
		stop();
	}
	if (Side == left)
	{
		mav(motorR,-700); mav(motorL,700);
		sleep(0.479999);
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
	set_servo_position(1, 0);
}

void claw_down()
{
	set_servo_position(1, 1424);
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
		IR = 4;
	}
	if (Side == left)
	{
		IR = 6;
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
	while (1 == 1) //Maybe I should change?
	{
		reverseT(1000, 3);
		sleep(0.2);
		forwardT(1000, 3);
		sleep(0.2);
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
	CW();
}

void center_defense()
{
	CW180();
	sleep(0.5);
	claw_down();
	sleep(0.5);
	turnStraight(200, 100);
	forwardT(100, 1);
	CCW();
	patrol();
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
		while (1 == 1)
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
	bordercross();
}

void strategy_2() //Tower 
{
	bordercross();
	tower_tip(); 
}

void strategy_3() //Biofuels
{
	bordercross();
	biofuel_block();
}

void strategy_4() //Center gaurd
{
	bordercross();
	center_defense();
	
}

/////-^-Function definitions-^-/////
