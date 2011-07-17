/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/
#define CREATE
#include "config.Definitions.h"
void instructions();

int main(){
	int X = 0;
	
	create_connect();
	set_create_total_angle(0);
	enable_servos();
	armPosSB();
	clawSB();
	instructions();
	while(!black_button()) //black_button
	{
		
		if (a_button()){
			instructions();
		}
		if (b_button()){
			turnAdjust(margin_of_error);
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (left_button()){
			turnCCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		}
		if (right_button()){
			turnCW();
			printf("%d\t%d\n",X,get_create_total_angle(0.1));
		} 		
		if (down_button()){
			
		}
	}
}

void instructions(){
	cbc_display_clear();
	msleep(500);
	printf("A to open/close these directions.\n");
	printf("B to force angle readjustment.\n");
	printf("Left to turn CCW 90 deg.\n");
	printf("Right to turn CW 90 deg.\n");
	printf("Black Button to stop test.");
	while(!a_button())	     msleep(500);
	cbc_display_clear();
	printf("X\tAngle\n");
	printf("-\t-----\n");
	msleep(500);
}

/*Function definitions go below.*/
