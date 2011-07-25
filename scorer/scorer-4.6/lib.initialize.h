// initialization for richard
// code written by ben shukman

int strategyOrder;

/*Function prototypes below*/
void initialize();
//void shortInitialize();
void servoSetup();
void createSetup();
void sideSelect();
void positionSetup();
void positionSetupTurn();
void strategySelect();


// Main:

void initialize() {
	printf("initializing. please wait.\n");
	servoSetup();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	createSetup();
	sideSelect();
	positionSetup();
	strategySelect();
	positionSetupTurn();
	msleep(1000);
	cbc_display_clear();
	printf("initialization complete");
	msleep(1000);
	cbc_display_clear();
	wait_for_light(LIGHT_PORT);
	shut_down_in(119);
	if (strategyOrder == 1) {
		printf ("running seeding round strategy.");
		seedStrat();
	} else {
		printf ("running double elimination round strategy.");
		DEStrat();
	}
	//msleep(1000);
	cbc_display_clear();
}


// Functions:

void servoSetup() {
	enable_servos();
	armPosSB();
	clawSB();
	mav(0, 250);
	sleep(2);
	freeze(0);
	printf("servos initialized.\n");
	msleep(500);
}

void createSetup() {
	create_connect();
	create_full();
	clearAngle();
	printf("create initialized.");
	msleep(500);
	cbc_display_clear();
}

void sideSelect() {
	printf ("select orientation of the robot compared to botguy.\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n\n");
	while (!b_button() && !a_button()) {}
	if (b_button()) {
		side = RIGHT;
		printf("robot is on right of botguy.");
		msleep(500);
		cbc_display_clear();
	}
	if (a_button()) {
		side = LEFT;
		printf("robot is on left of botguy.");
		msleep(500);
		cbc_display_clear();
	}
}

void positionSetup() {
	printf("%d\n", ET_FRONT);
	drive(-200);
	while (ET_FRONT < ET_FRONT_PVC-100) {printf("%d\n", ET_FRONT); sleep(.1);}
	drive(-150);
	printf("%d\n", ET_FRONT);
	while (ET_FRONT < ET_FRONT_PVC) {printf("%d\n", ET_FRONT); sleep(.1);}
	create_stop();
	driveAtMmFor(-50,2);
	clearAngle();
	driveAtMmFor(50,1);
	msleep(1000);  // pause for a second
}

void positionSetupTurn() {
	printf("Q");
	if (side == RIGHT) {
		printf("F");
		turn(90);
		msleep(1000);  // pause for a second
		turn(45);
		/*while (get_create_lbump(.1) == 0 || get_create_rbump(.1) == 0) {
			create_drive_straight(50);
		}
		create_stop(); */
	} else if (side == LEFT) {
		printf("L");
		turn(-90);
		msleep(1000);
		turn(-45);
	}
	printf("U\n");
}

void strategySelect() {
	printf("select strategy.\n 'up arrow' for double elimination round.\n 'down arrow' for seeding round.\n\n");
	while (!up_button() && !down_button()) {}
	
		if (up_button()) {
			printf("double elimination strategy selected.\n");
			strategyOrder = 2;
			msleep(500);
		}
		if (down_button()) {
			printf("seeding strategy selected.\n");
			strategyOrder = 1;
			msleep(500);
		}
	
}
