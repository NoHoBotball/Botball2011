#define CREATE
#include "config.Definitions.h"

void armLowerManual();
int main(){
	printf("initializing. please wait.\n");
	servoSetup();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	clearAngle();
	createSetup();
	sideSelect();
	clawGrab();
	clawOpen();             while(!black_button()); while(black_button());
	clawClose();            while(!black_button()); while(black_button());
	armPosBlockStack1();    while(!black_button()); while(black_button());
	clawStack1();           while(!black_button()); while(black_button());
	printf("\nUse this program to manually find servo positions for the arm/claw.\n");
	//printf("A to select the arm.  B to select the claw.\n");
	sleep(1);
	armLowerManual();	
}


void armLowerManual(){
	printf("Claw seleced. Black Button to exit current selection.");
	printf("To raise Arm press Up.  To lower Arm press Down.\n");
	while(!black_button()){
		if(up_button()){//raise arm
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT+30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT-30);
			sleep(.01);
			printf("LEFT_ARM: %d  RIGHT_ARM: %d",SERVO_ARM_LEFT,SERVO_ARM_RIGHT);
		}
		if(down_button()){//lower arm
			set_servo_position(SERVO_ARM_LEFT_PORT, SERVO_ARM_LEFT-30);
			set_servo_position(SERVO_ARM_RIGHT_PORT, SERVO_ARM_RIGHT+30);
			sleep(.01);
			printf("LEFT_ARM: %d  RIGHT_ARM: %d",SERVO_ARM_LEFT,SERVO_ARM_RIGHT);
		}
	}
}
