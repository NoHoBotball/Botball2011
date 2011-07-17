
#ifndef TEST_NAV
#define TEST_NAV
#define CREATE
#include "config.Definitions.h"
void instructions();
void writeToFile();
void mainNav();

void main(){
	int X = 0;
	
	create_connect();
	set_create_distance(0);
	set_create_total_angle(0);
	enable_servos();
	armPosBlockStack1();
	clawStack1();
	instructions();
	writeToFile();
	printf("%f",seconds());
	while(1) //black_button
	{
		if (a_button()){
			float time1, time2;
			set_create_distance(0);
			printf("//Press Black Button to start/stop drive\n");
			while(!black_button());	time1 = seconds();
			create_drive_straight(-50);
			sleep(2.0);
			printf("drive(50);\t");
			while(!black_button());	time2 = seconds();
			stop();
			printf("sleep(%f);\t//move %dmm",time2-time1,get_create_distance(0));
			
		}
		if (b_button()){
			int done=0;
			while(!done){
				if (down_button()){
					turnAdjust(margin_of_error);
					printf("turnAdjust(margin_error);  ");
					printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
					done = 1;
				}
				if (left_button()){
					turn(90);
					printf("turn(90);  ");
					printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
					done = 1;
				}
				if (right_button()){
					turn(-90);
					printf("turn(-90);  ");
					printf("//X=%d  Angle=%d\n",X,get_create_total_angle(0.1));
					done  = 1;
				} 
			}
		}
	}
}

void instructions(){
	cbc_display_clear();
	msleep(500);
	printf("A to drive.\n");
	printf("\tBlack Button to stop\n");
	printf("B to turn.\n");
	printf("\tLeft to turn CCW 90 deg.\n");
	printf("\tRight to turn CW  90 deg.\n");
	printf("\nBlack Button to clear this screen");
	while(!black_button())	     msleep(500);
	cbc_display_clear();
	msleep(500);
}

void writeToFile(){
	
}
/*Function definitions go below.*/
#endif
