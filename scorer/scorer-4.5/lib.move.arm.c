void grabBlocks() {
	//detectBlock();
	//backFromTouch(0);
	//scootUp(0);
	clawClose();
	sleep(1);
}

void blockStack1() {
	/*set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_GRAB+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_GRAB-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_GRAB+100);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_GRAB-100); //barely above PVC*/
	detectPVC();
	//create_drive_straight(-50);
	//sleep(1);
	//create_stop();
	clearAngle();
	backFromTouch(1);
	scootUp(1);
	clawOpen();
	
}
	
void blockStack2() {
	/*set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK1+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK1-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK1+200);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK1-200); *///above 2 cube height
	armPosBlockStack1();
	detectBlock();
	backFromTouch(2);
	clawStack1();
	armPosBlockStack1Lower();
	clawOpen();
}

void blockStack3() {
	armPosBlockStack2();
	detectBlockLast();
	backFromTouch(3);
	clawOpen();
}
