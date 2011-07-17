#define CREATE
#include "config.Definitions.h"
int main()
{
	enable_servos();
	while (black_button() == 0) {
		if(up_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)+30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)-30);
			printf("%d,%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
		if(down_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)-30);
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)+30);
			printf("%d,%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT), get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
		if(left_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)+30);
			printf("%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT));
		}
		if(right_button() == 1)
		{
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)+30);
			printf("%d\n", get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
		if(a_button() == 1)
		{
			set_servo_position(SERVO_CLAW_LEFT_PORT, get_servo_position(1)-30);
			printf("%d\n", get_servo_position(SERVO_CLAW_LEFT_PORT));
		}
		if(b_button() == 1)
		{
			set_servo_position(SERVO_CLAW_RIGHT_PORT, get_servo_position(2)-30);
			printf("%d\n", get_servo_position(SERVO_CLAW_RIGHT_PORT));
		}
	}
}
