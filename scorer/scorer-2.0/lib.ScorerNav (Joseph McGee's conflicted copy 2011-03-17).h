// ScorerNav - moves block towers to the starting box.  includes stacking functions.
// begins after first towers have been lifted.  starts with initial movement to sb from tower1.
// sb = starting box.
// Code written by Ben Shukman.

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void ScorerNav();
void sbNav();
void sbToTower2Nav();
void sbNav2();
void scorerSetup();
void scorerCheck();
void scorerCheck2();
void scorerCheck3();
void scorerCheck4();
void scorerCheck5();
void scorerCheck6();


// Main:

void ScorerNav() {
	scorerSetup(); // comment out when finalizing.
	scorerCheck();
	sbNav(); // tower1 to starting box.  will include tower drop.
	scorerCheck2();
	sbToTower2Nav(); // up until middle of runway.
	scorerCheck3();
	CenterCamera(); // moves from runway to towers.  positions robot to face towers.
	scorerCheck4();
	Lift();  //lifts towers.
	scorerCheck5();
	sbNav2(); // moves to starting box boundary with towers.  includes right turn at end.
	scorerCheck6();
	// next step: stack towers. then move away.
}


// Functions:

void scorerSetup() {
	create_connect();
	enable_servos();
	create_start();
	create_full();
	ArmUp();
	set_servo_position(1,120);
}

void sbNav() { // start at tower1.  move to sb.
	drivemm(175.0,.5);
	TurnRight();
	drivemm(175.0,.5);
	TurnLeft();
	int speed = 175;
	create_drive_straight(speed); 
	while (get_create_lbump(.01) == 0 && get_create_rbump(.01) == 0) {	
	}
	create_stop();
	//drivemm(-100.0,.5); // moves away from wall. most likely delete for final.
	TurnLeft();
	ArmUp();
	drivemm(-175.0, 2.5);
	int speed2 = -100;
	create_drive_straight(speed2); 
	while (digital(15) == 0) {	
	}
	create_stop();
	
	drivemm(240.0, 1.5);  // move backward set distance (until arm can lower). test values.
	ArmDown();
	drivemm(-75.0,1.5); // move forward set distance (until mini servo bracket hits block). test values.
	Release();
	
}

void sbToTower2Nav() { // start at sb.  move to middle of runway.  transitions into CenterCamera().
	drivemm(175.0,1.0); // back away from towers.
	while (get_create_rbump(0.01) == 0 && get_create_lbump(0.01) == 0) {
		create_drive_straight(250);
	}
	create_stop();
	TurnRight();
	drivemm(-250, 1.5);
	TurnRight();
	drivemm(-250, 1.5);
}

void sbNav2() { // start at tower2. moves to outisde sb.
	while (get_create_rbump(0.1) == 0) { // move until create bumper hits pvc.
		drive(100);
	}
	drivemm(-175.0,1.5); // move away from pvc.
	TurnRight(); 
	drivemm(-240,2.0); // move towards starting box.  test value (should be past luggage carts).
	TurnRight(); 
	while(get_create_rbump(0.01) == 0) {
		drive(100);
	}
	drivemm(-175, .4); // move away from pvc.
	TurnLeft(); // facing sb.
}

void scorerCheck(){
	printf("setup complete\n");
	beep();
}

void scorerCheck2() {
	printf("sb nav and tower drop complete\n");
	beep();
}

void scorerCheck3() {
	printf("nav to runway complete\n");
	beep();
}

void scorerCheck4() {
	printf("center camera program complete\n");
	beep();
}

void scorerCheck5() {
	printf("tower2 lift complete\n");
	beep();
}

void scorerCheck6() {
	printf("tower2 to sb nav complete\n");
	beep();
}
