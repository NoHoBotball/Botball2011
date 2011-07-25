//lib.move.turn.c
//Turn Functions

//I was rummaging through the provided program libraries to better understand how the functions they give us work
// and I found a provided turn function in "InstallationPath\targets\gcc\include\kiss-create-2011.h"
// -McGee

int updateX(int increment){
	X += increment;
	return X;
}
int updateAngle(int wait, float lag){
	msleep(wait);
	return Angle = get_create_total_angle(lag);//if lag == 0 you force the create to update the angle
}

void create_direct(int lspeed, int rspeed){create_drive_direct(rspeed,lspeed);}

void adjustCW (){ create_direct( adjust_speed,-adjust_speed); }
void adjustCCW(){ create_direct(-adjust_speed, adjust_speed); }

void turnAdjust(int margin_of_error)
{
	margin_of_error = abs(margin_of_error);
	updateAngle(100,0);
	while((X > Angle+margin_of_error) || (X < Angle-margin_of_error))
	{
		if(Angle > X)   create_direct( adjust_speed,-adjust_speed);//adjust CW
		if(Angle < X)   create_direct(-adjust_speed, adjust_speed);//adjust CCW
		updateAngle(100,0.1);
	}
}

void turn(deg){
	int upper_bound, lower_bound;
	int abs_deg = abs(deg);
	float speed = 101.3;
	float time = 2.057252314;
	
	if(deg<0)           speed =-speed;
	if(abs_deg == 90 )  time  = time;
	if(abs_deg == 180)  time  = time*2.0;
	upper_bound = deg+margin_of_error;
	lower_bound = deg-margin_of_error;
	
	create_drive(speed,1);
	sleep(time);
	create_stop();
	updateAngle(100,0);
	if (Angle < lower_bound || Angle > upper_bound){
		if (Angle > deg){
			adjustCW();
			while (updateAngle(0,.1) > deg);
			create_stop();
			updateX(deg);
			return;
		}
		if (Angle < deg){
			adjustCCW();
			while (updateAngle(0,.1) < deg)
			create_stop();
			updateX(deg);
			return;
		}
	}
}

void turnFast(deg){
	int abs_deg = abs(deg);
	float speed = 101.3*2.0;
	float time  = 2.057252314*.5;
	
	if(deg<0)           speed =-speed;
	if(abs_deg == 90 )  time  = time;
	if(abs_deg == 180)  time  = time*2.0;
	
	create_drive(speed,1);
	sleep(time);
	create_stop();
}

#ifdef DEF_SIDE
void turnForRight (int deg){
	if (side==LEFT)  turn(-deg);
	if (side==RIGHT) turn( deg);
}
void turnForLeft(int deg){
	if (side==LEFT)  turn ( deg);
	if (side==RIGHT) turn (-deg);
}
void turnFastForRight (int deg){
	if (side==LEFT)  turnFast(-deg);
	if (side==RIGHT) turnFast( deg);
}
void turnFastForLeft(int deg){
	if (side==LEFT)  turnFast( deg);
	if (side==RIGHT) turnFast(-deg);
}
#endif
