int main()
{
	enable_servos();
	set_servo_position(1, 1000);
	sleep(2);
	set_servo_position(1,100);
	sleep(2);
	set_servo_position(3,1000);
	sleep(2);
	set_servo_position(3,100);
	sleep(2);
}
