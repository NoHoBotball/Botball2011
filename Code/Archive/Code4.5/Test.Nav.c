
#ifndef TEST_NAV
#define TEST_NAV
#define CREATE
#include "config.Definitions.h"
void instructions();
//void writeToFile();
void testDrive();
void testArc();
void testTurnAdjust();
void testTurnCCW();
void testTurnCW();
void testDetectPVC();

int done=0;
int arc_value = 580;

void main(){
	int X = 0;
	create_connect();
	set_create_distance(0);
	set_create_total_angle(0);
	enable_servos();
	armPosBlockStack1();
	clawStack1();
/*	create_drive(-500,-380);
	sleep(2.3);
	create_stop();
}
*/  
//	writeToFile();
	printf("%f",seconds());
	while(1) //black_button
	{
		if (a_button()){
			testDrive();
		}
		if (b_button()){
			testDetectPVC();
		}
		if (up_button()){
			
		}
		if (down_button()){
			testTurnAdjust();
		}
		if (left_button()){
			testTurnCCW();
		}
		if (right_button()){
			testTurnCW();
		}	
	}
}
void testDrive(){
	float time1, time2;
	set_create_distance(0);
	printf("//Press Black Button to start/stop drive\n");
	while(!black_button());	time1 = seconds();
	create_drive_straight(-50);
	printf("drive(50);\t");
	sleep(2.0);
	while(!black_button());	time2 = seconds();
	stop();
	printf("sleep(%f);\t//move %dmm",time2-time1,get_create_distance(0));
	done = 1;
}
void testArc(){
	float time1, time2;
	cbc_display_clear();
	set_create_total_angle(0);
	printf("//Press Black Button to start/stop arc\n");
	while(black_button()) while(!black_button()){}
		time1 = seconds();
	create_drive(-100,-580);
	while(!black_button());	time2 = seconds();	stop();
	printf("%fsecs\t %dmm\n",time2-time1,get_create_distance(0));
	while(!black_button());
	clawSB();
	armPosSB();
	printf("\npress A for too far, B for not far enough, Black for just right\n");
	while(!done){
		if(a_button()){
			arc_value = arc_value-5;
			done = 1;
		}
		if(b_button()){
			arc_value = arc_value+5;
			done = 1;
		}
		if(black_button()) done = 1;
	}
	printf("arc = %d",arc_value);
    printf("press black button to exit");
	while(!black_button());
}
void instructions(){
	cbc_display_clear();
	msleep(500);
	printf("A to drive.\n");
	printf("  Black Button to stop\n");
	printf("B to turn.\n");
	printf("  Left to turn CCW 90 deg.\n");
	printf("  Right to turn CW  90 deg.\n");
	printf("\nBlack Button to clear this screen");
	while(!black_button())	     msleep(500);
	cbc_display_clear();
	msleep(500);
}

void testTurnAdjust(){
	turnAdjust(margin_of_error);
	printf("turnAdjust(margin_of_error);\n");
	//printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
}
void testTurnCCW(){
	turn(90);
	printf("turn(90);\n");
	//printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
}

void testTurnCW(){
	turn(-90);
	printf("turn(-90);\n");
	//printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
}

void testDetectPVC(){
	detectPVC();
	printf("detectPVC();\n");
}

void writeToFile(){
	
}

#endif
