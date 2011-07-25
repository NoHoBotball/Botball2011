// initialization for richard
// code written by ben shukman

int strategyOrder;

/*Function prototypes below*/
void initialize();
void servoSetup();
void createSetup();
void sideSelect();
void strategySelect();


// Main:

void initialize() {
	printf("initializing. please wait.\n");
	servoSetup();
	createSetup();
	sideSelect();
	strategySelect();
	printf("initialization complete");
	msleep(1000);
	cbc_display_clear();
	//wait_for_light(LIGHT_PORT);
	if (strategyOrder == 1) {
		printf ("running seeding round strategy.");
	} else {
		printf ("running double elimination round strategy.");
	}
	msleep(1000);
	cbc_display_clear();
}


// Functions:

void servoSetup() {
	enable_servos();
	printf("servos initialized.\n");	
}

void createSetup() {
	create_connect();
	create_full();
	set_create_total_angle(0);
	printf("create initialized.\n");
}

void sideSelect() {
	printf ("select orientation of the robot compared to botguy.\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n");
	while (!b_button() && !a_button()) {}
	if (b_button()) {
		side = RIGHT;
		cbc_display_clear();
		printf("robot is on right of botguy.\n");
		msleep(500);
	}
	if (a_button()) {
		side = LEFT;
		cbc_display_clear();
		printf("robot is on left of botguy.\n");
		msleep(500);
	}
}

void strategySelect() {
	printf("select strategy order.\n 'up arrow' for double elimination round.\n 'down arrow' for seeding round.\n");
	while (!up_button() && !down_button())
	{
		if (up_button()) {
			printf("double elimination strategy selected.\n");
			strategyOrder = 1;
			msleep(500);
			break;
		}
		if (down_button()) {
			printf("seeding strategy selected.\n");
			strategyOrder = 2;
			msleep(500);
			break;
		}
	}
}
