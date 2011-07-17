//Drive Straight Functions


void driveAtMillimeters(int mm_speed) 
{
	printf("%4.1fmm/s\n", (float)mm_speed);
	create_drive_straight(mm_speed);
}
void driveAtMm(int speed) {
	driveAtMillimeters(speed);
}
void drive(int speed) {//in mm/s
	driveAtMm(speed);//mm/s
}

void driveAtInches(float in_speed) {
	int mm_speed = inToMm(in_speed);
	printf("%2.2fin/s  *  25.4mm/in = %6.1fmm/s\n", in_speed, inToMm(in_speed));
	create_drive_straight(mm_speed);
}
void driveAtMillimetersFor(int mm_speed, float seconds) {
	printf("%4.1fmm/s  * %3.1fsecs  = %6.1fmm\n", (float)mm_speed, seconds, mm_speed*seconds);
	create_drive_straight(mm_speed);
	msleep(seconds*1000);
	create_stop();
}
void driveAtInchesFor(float in_speed, float seconds) {
	int mm_speed = inToMm(in_speed);
	printf("%2.2fin/s  *  25.4mm/in = %6.1fmm/s\n", in_speed, inToMm(in_speed));
	printf("           * %3.1fsecs = %6.1fmm\n", seconds, mm_speed*seconds);
	create_drive_straight(mm_speed);
	msleep((int)(seconds*1000));
	create_stop();
}

void driveAtIn(float speed) {
	driveAtIn(speed);
}
void driveAtMmFor(int speed, float seconds) {
	driveAtMillimetersFor(speed, seconds);
}
void driveAtInFor(float speed, float seconds) {
	driveAtInchesFor(speed, seconds);
}


void stop() {
	create_stop();
}
void stopIn(float seconds) {
	msleep((int)(seconds*1000));
	stop();
}
