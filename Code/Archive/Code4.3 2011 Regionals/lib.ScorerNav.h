// ScorerNav - moves block towers to the starting box.  includes stacking functions.
// sb = starting box.
// starts at end of lifting of first tower blocks.
// code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void ScorerNav();
void scorerSetup();
void sbNav();
void sbToTower2Nav();
void sbNav2();
void stackTowers();
void scorerCheck(int i);

// Main:

void ScorerNav()
{
//	scorerSetup();		scorerCheck(00);
	sbNav(); 			scorerCheck(10);	// tower1 to starting box.  will include tower drop.
	sbToTower2Nav(); 	scorerCheck(20);	// up until middle of runway.
	CenterCamera(); 	scorerCheck(30);	// moves from runway to tower2.  positions robot to face towers.
	Lift();  			scorerCheck(40);	//lifts tower2.
	sbNav2(); 			scorerCheck(50); // moves to starting box boundary with tower2.  includes right turn at end.
//	drivemm(-175, -1);
	stackTowers();		scorerCheck(60);
}


// Functions:

void scorerSetup()
{
	create_connect();
	enable_servos();
	armUp();
	set_servo_position(1,LowerMini);
}

void sbNav() // start at tower1.  move to sb.
{	
	int speed = 100;
	int speed2 = -100;
	
	// hits back of starting box pvc variation.
	drivemm(175,.5);
	turnForRight(tspeed,-90);
	drivemm(400, 1);
	
	create_drive_straight(speed);
	while (get_create_lbump(.01) == 0 && get_create_rbump(.01) == 0){}
	create_stop();
	turnForRight(tspeed,-90);
	armUp();
	
	create_drive_straight(speed2);
	while (digital(TouchSensor) == 0) {}
	create_stop();
	drivemm(240, 1.5);  // move backward set distance (until arm can lower). test values.
	armDown();
	drivemm(-75,1.5); // move forward set distance (until mini servo bracket hits block). test values.
	release();
}

void sbToTower2Nav() // start at sb.  move to middle of runway.  transitions into CenterCamera().
{
	// tourney other strategy variation
	drivemm(150,1.0); // move away from towers.
	turnForRight(tspeed,90);
	while (get_create_rbump(0.01) == 0 && get_create_lbump(0.01) == 0) create_drive_straight(100);
	create_stop();
	drivemm(100,.25);
	armUp();
	drivemm(-500, 3);
	printf("first drive complete\n");
}
	
void sbNav2() // start at tower2. moves to outisde sb.
{
//	competition variation.
	turnForRight(tspeed,-90); 
	drivemm(500,3); // move towards starting box.  test value (should be past luggage carts).
	while(get_create_rbump(0.01) == 0 && get_create_lbump(0.01) == 0) drive(100);
	turnForRight(tspeed,-90); // facing sb.
}
	
void stackTowers()
{
	armStack();
	mav(Claw, -400); // back away from completed towers.
	sleep(2);
	freeze(Claw);
	drivemm(100,3);
}

void scorerCheck(int i)
{
	switch (i)
	{
		case 00:
			printf("%d  setup complete\n",i);
			beep();
			break;
		case 10:
			printf("%d  sb nav and tower drop complete\n",i);
			beep();
			break;
		case 20:
			printf("%d  nav to runway complete\n",i);
			beep();
			break;
		case 30:
			printf("%d  center camera program complete\n",i);
			beep();
			break;
		case 40:
			printf("%d  tower2 lift complete\n",i);
			beep();
			break;
		case 50:
			printf("%d  tower2 to sb nav complete\n",i);
			beep();
			break;
		case 60:
			printf("%d  tower stack complete\n",i);
		default:
			printf("Error");
			beepFor(3);
			break;
	}
}
