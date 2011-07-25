#define CREATE

#include "config.Definitions.h"

void main()
{
	create_connect();
	enable_servos();
	set_each_analog_state(1,1,0,0,0,0,0,0);
	set_create_total_angle(0);
	printf ("select orientation of the robot compared to botguy.\n'A' button for left of bot guy.\n'B' button for right of bot guy.\n\n");
	while (!b_button() && !a_button()) {}
		if (b_button()) {
			side = RIGHT;
			printf("robot is on right of botguy.");
			msleep(500);
			cbc_display_clear();
		}
		if (a_button()) {
			side = LEFT;
			printf("robot is on left of botguy.");
			msleep(500);
			cbc_display_clear();
		}
	printf("select strategy.\n 'up arrow' for double elimination round.\n 'down arrow' for seeding round.\n\n");
	while (!up_button() && !down_button()){}
		if (up_button()) {
			printf("double elimination strategy selected.\n");
			strategyOrder = 1;
			msleep(500);
		}
		if (down_button()) {
			printf("seeding strategy selected.\n");
			strategyOrder = 2;
			msleep(500);
		}
	//initialize();
	richardNav();
}
