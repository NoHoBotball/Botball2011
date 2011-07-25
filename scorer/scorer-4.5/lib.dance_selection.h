// dance initialization and selection program for 'scorer'
// code written by ben shukman

/* Libraries used in Botball are automatically included, but list any additional includes below */
#include "lib.middle_finger.h"

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
	sleep(.25);
	mav(3,100);
	sleep(.8);
	off(3);
	enableServoDown();
	sleep(.5);
	release();
	set_servo_position(1,120); // mini servo down
	mav(3, 400); // move arm to open position -- test values -- should be slightly angeled forwards
	sleep(1);
	off(3);
	printf("servos initalized.\n");
	
	create_connect();
	create_full();
	set_create_total_angle(0);
	printf("create initialized.\n");
	
	danceSelection(); // pick a dance yahh??

}

void danceSelection() { // include dances as you make them
	cbc_display_clear();
	sleep(.1);
	printf("select a dance\n\n");
	printf("mfinger: press black button\n");
	printf("exit program: press left button\n");
	int count = 0;
	while (count != 1) {
		if (black_button() == 1) {
			finger();
		}
		if (a_button() == 1) {
			
		}
		if (b_button() == 1) {
			
		}
		if (left_button() == 1) {
			count = 1;
		}
	}
	shut_down_in(2.0);
	cbc_display_clear();
	printf("program finished");
}

void enableServoDown() { // claw goes down after servos enable
	int j;
	for (j=0; j <=450; j=j+10) {
	
		set_servo_position(0, 1024-j);
		set_servo_position(3, 1024+j);
		sleep(.001);
	}
	set_servo_position(0, 460);
	set_servo_position(3, 1500);
}

void release() { // open claw until touch sensor #14 is activated
	mav(3, -400);
	while(digital(14) ==0) {
	}
	off(3);
	clear_motor_position_counter(3);
}
