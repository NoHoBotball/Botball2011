// scorer wiggle dance
// made by ben shukman

int main()
{
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
	
	benDance();
}

benDance() {
	wiggle();
}

wiggle() {
	wiggleCreate();
	sleep(.25);
	wiggleArm(); /*
	wiggleClaws();
	wiggleFinger();*/
}
	
wiggleCreate() {
	wiggleCreateLeft();
	wiggleCreateRight();
	wiggleCreateLeft();
}

wiggleArm() {
	wiggleArmUp();
	sleep(.25);
	wiggleArmDown();
	sleep(.25);
	wiggleArmUp();
	sleep(.25);
	wiggleArmDown();
	sleep(.25);
}

wiggleClaws() {
	
}

wiggleFingers() {
	
}

wiggleCreateRight() {
	create_spin_CW(300);
	sleep(.15);
	create_stop();
}

wiggleCreateLeft() {
	create_spin_CCW(300);
	sleep(.15);
	create_stop();
}

wiggleArmUp() {
	set_servo_position (0, 1780);
	set_servo_position (3, 280);
}

wiggleArmDown() {
	set_servo_position (0, 460);
	set_servo_position (3, 1500);
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
