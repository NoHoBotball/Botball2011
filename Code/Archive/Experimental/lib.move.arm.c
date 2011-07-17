void grabBlocks() {
	detectBlock();
	backFromTouch(0);
	armPosBlockGrab();
	clawGrab();
	scootUp(0);
	clawClose();
}

void blockStack1() {
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_GRAB+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_GRAB-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_GRAB+100);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_GRAB-100); //barely above PVC
	detectPVC();
	backFromTouch(1);
	armPosBlockGrab();
	clawGrab();
	scootUp(1);
	clawOpen();
}
	
void blockStack2() {
	armPosBlockStack1();
	clawStack1();
	set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT_STACK1+300);
	set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT_STACK1-300);
	set_servo_position(SERVO_CLAW_LEFT_PORT, SERVO_CLAW_LEFT_STACK1+200);
	set_servo_position(SERVO_CLAW_RIGHT_PORT, SERVO_CLAW_RIGHT_STACK1-200); //above 2 cube height
	detectBlock();
	backFromTouch(2);
	clawStack1();
	armPosBlockStack1();
	clawOpen();
}

void blockStack3() {
	detectBlock();
	backFromTouch(3);
	clawOpen();
}
