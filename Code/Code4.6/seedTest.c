#define CREATE
#include "config.Definitions.h"

int main() {
	side = LEFT;
	create_connect();
	set_each_analog_state(0,1,0,0,0,0,0,0);
	create_full();
	clearAngle;
	enable_servos();
	blockStack3();
}
