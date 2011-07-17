void servoPosCheck();
void servoPosCheck()
{
	enable_servos();
	int i;
	for(i =0; i<4 && !black_button(); i++)
		printf("Servo 0: %d. ", get_servo_position(i);
		msleep(500);
	}
}
