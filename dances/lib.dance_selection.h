// dance initialization and selection program for 'scorer'
// code written by ben shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */


/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
void initialize();
void danceSelection();
void enableServoDown();
void release();

// dance selection:

void initialize() {
	printf("initializing. please wait.\n");
	enable_servos();
	/*sleep(.25);
	mav(3,100);
	sleep(.8);
	off(3);
	enableServoDown();
	sleep(.5);
	release();
	set_servo_position(1,120); // mini servo down
	mav(3, 400); // move arm to open position -- test values -- should be slightly angeled forwards
	sleep(1);
	off(3);*/
	printf("servos initalized.\n");
	
	create_connect();
	create_full();
	set_create_total_angle(0);
	printf("create initialized.\n");
	
	//enableServoDown();
	//release();
	
	danceSelection(); // pick a dance yahh??
	
}

void danceSelection() { // include dances as you make them
	cbc_display_clear();
	sleep(.1);
	printf("select a dance\n\n");
	printf("mfinger: press black button\n");
	printf("createwiggle: press a_button\n");
	printf("demo:press b_button\n"); printf ("touchdemo: press up button\n");
	printf("exit program: press left button\n");
	int count = 0;
	while (count != 1) {
		sleep(1);
		printf("Choose.");
		
		if (black_button() == 1) {
			cbc_display_clear();
			finger();
			sleep(.1);
			printf("select a dance\n\n");
			printf("mfinger: press black button\n");
			printf("createwiggle: press a_button\n");
			printf("demo:press b_button\n"); printf ("touchdemo: press up button\n");
			printf("exit program: press left button\n");
		}
		if (up_button() == 1) {
			while(black_button() == 0)
			{
				if (digital(15) == 1)
				{
					beep();
					printf("Touch Sensor Detected. Black Button to exit.");
					create_drive_straight(-200);
					sleep(.5);
					create_stop();
				}
			}
		}
		if (a_button() == 1) {
			cbc_display_clear();
			danceFor(20);
			sleep(.1);
			printf("select a dance\n\n");
			printf("mfinger: press black button\n");
			printf("createwiggle: press a_button\n");
			printf("demo:press b_button\n"); printf ("touchdemo: press up button\n");
			printf("exit program: press left button\n");
		}
		if (b_button() == 1) {
			cbc_display_clear();
			demo();
			sleep(.1);
			printf("select a dance\n\n");
			printf("mfinger: press black button\n");
			printf("createwiggle: press a_button\n");
			printf("demo:press b_button\n"); printf ("touchdemo: press up button\n");
			printf("exit program: press left button\n");
		}
		if (left_button() == 1) {
			count = 1;
		}
	}
	shut_down_in(2.0);
	cbc_display_clear();
	printf("program finished");
}
