// the middle finger
// code written by ben shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */

/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
/*
void armUp();
void armDown();
void finger();
void fingerSelect();
*/

/*
void finger() {
	set_servo_position(1,120); // mini servo down
	mav(3, 400); // move arm to open position -- test values -- should be slightly angeled forwards
	sleep(.5);
	off(3);
	cbc_display_clear();
	printf("press black button to flick someone off\n\npress 'B' button to go to selection screen\n");
	fingerSelect();
} */

void finger() {
	armUp();
	sleep(1.5);
	set_servo_position(1, 1200);
	sleep(2.0);
	armDown();
	sleep(.3);
	set_servo_position(1, 120);
}

/*
void fingerSelect() {
	while (black_button() == 0 && b_button() == 0) {
		if (black_button() == 1) {
			armUp();
			sleep(1.5);
			set_servo_position(1, 1200);
			sleep(2.0);
			armDown();
			sleep(.3);
			set_servo_position(1, 120);
			} if (b_button() == 1) {
			release();
			danceSelection();
		}
		fingerSelect();
	}
} */
/*
void armDown() { // arm goes down slowly
	int i;
	for(i = 1500; i>=100; i=i-25) {
		set_servo_position(0, 460+i);
		set_servo_position(3, 1500-i);
		sleep(.0001);
	}
	set_servo_position (0, 460);
	set_servo_position (3, 1500);
	
}

void armUp() { // arm goes up quickly
	set_servo_position (0, 1780);
	set_servo_position (3, 280);
}
*/
