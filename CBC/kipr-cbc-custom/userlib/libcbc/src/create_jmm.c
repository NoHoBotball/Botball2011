#include "create_jmm.h"

void create_turn(int deg, int speed) { // degrees, vel in mm/sec
        CREATE_BUSY;
        create_write_byte(137); // move
        create_write_byte(HIGH_BYTE(speed));
        create_write_byte(LOW_BYTE(speed));
        if (deg > 0){ // CCW case
                create_write_byte(0);
        	create_write_byte(1); }
        else { // CW case
                create_write_byte(255);
        	create_write_byte(255); }
        create_write_byte(157); // wait for angle done
        create_write_byte(HIGH_BYTE(deg));
        create_write_byte(LOW_BYTE(deg));
        CREATE_FREE;
}

void create_wait_for_angle(int deg) {//degrees
	CREATE_BUSY;
	create_write_byte(157); // wait for angle done
        create_write_byte(HIGH_BYTE(deg));
        create_write_byte(LOW_BYTE(deg));
	CREATE_FREE;
}

void create_wait_for_dist(int dist) {//distance in mm
	create_write_byte(156); // wait for distance done
        create_write_byte(HIGH_BYTE(dist));
        create_write_byte(LOW_BYTE(dist));
}
