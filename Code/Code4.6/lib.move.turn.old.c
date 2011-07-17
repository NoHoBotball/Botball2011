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

void create_direct(lspeed,rspeed){create_drive_direct(rspeed,lspeed);}

void adjustCW () {create_direct( adjust_speed,-adjust_speed);}
void adjsutCCW() {create_direct(-adjust_speed, adjust_speed);}

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



void turn(int deg){
	switch(deg)
	{
		case -180:
			turn180CW();
			break;
		case -90:
			turnCW();
			break;
		case 90:
			turnCCW();
			break;
		case 180:
			turn180CCW();
	}
}
void turnFast(int deg){
	switch (deg)
	{
		case -180:
			turnFast180CW();
			break;
		case -90:
			turnFastCW();
			break;
		case 90:
			turnFastCCW();
			break;
		case 180:
			turnFast180CCW();
	}
}

void turnCW(){
	create_drive(-101.3,1);
	sleep(2.057252314);
	create_stop();
	updateAngle(100,0);
	if (Angle > -89 || Angle < -91){
		if (Angle > -90){//too far CW
			create_direct(-adjust_speed, adjust_speed);//CCW adjust
			while (updateAngle(0,.1) < -90){}
			create_stop();
			updateX(-90); 
			return;
		}
		//updateAngle(100,.1);
		if (Angle < -90){//too far CCW
			create_drive_direct(adjust_speed, -adjust_speed);//CW adjust
			while (updateAngle(0,.1) > -90){}
			create_stop();
			updateX(-90);
			return;
		}
		//updateAngle(100,.1);
	}
	create_stop();
	//updateX(-90);
}
void turnFastCW()
{
	create_drive(-101.3*2.0,1);
	sleep(2.057252314*.5);
	create_stop();
	updateX(-90);
}
void turn180CW()
{
	create_drive(-101.3,1);
	sleep(2.057252314*2.0);
	create_stop();
	updateAngle(100,0);
	if (Angle > -179 || Angle < -181){
		if (Angle < -180){//too far CW
			create_direct(-adjust_speed, adjust_speed);//CCW adjust
			while (updateAngle(0,.1) < -180){}
			create_stop();
			updateX(-180); 
			return;
		}
		//updateAngle(100,.1);
		if (Angle < -90){//too far CCW
			create_drive_direct(adjust_speed, -adjust_speed);//CW adjust
			while (updateAngle(0,.1) > -180){}
			create_stop();
			updateX(-180);
			return;
		}
		//updateAngle(100,.1);
	}
	create_stop();
	//updateX(-180);
}
void turnFast180CW(){
	create_drive(-101.3*2.0,1);
	sleep(2.057252314);
	create_stop();
	updateX(-180);
}

void turnCCW()
{
	create_drive(101.3,1);
	sleep(2.057252314);
	create_stop();
	updateAngle(100,0);
	if (Angle < 89 || Angle > 91){
		if (Angle > 90){//too far CCW
			create_direct(adjust_speed, -adjust_speed);//CW adjust
			while (updateAngle(0,.1) > 90);
			create_stop();
			updateX(90);
			return;
		}
		//updateAngle(100,0);
		if (Angle < 90){//too far CW
			create_direct(-adjust_speed, adjust_speed);//CCW ajdust
			while (updateAngle(0,.1) < 90)
			create_stop();
			updateX(90);
			return;
		}
		//updateAngle(100,0);
	}
	//create_stop();
	//updateX(90);
}

void turnFastCCW(){
	create_drive(101.3*2.0,1);
	sleep(2.057252314*.5);
	create_stop();
	updateX(90);
}
void turn180CCW(){
	create_drive(101.3,1);
	sleep(2.057252314*2.0);
	create_stop();
	updateAngle(100,0);
	if (Angle > 181 || Angle < 179){
		if (Angle > 180){//too far CW
			create_direct(-adjust_speed, adjust_speed);//CCW adjust
			while (updateAngle(0,.1) < 180){}
			create_stop();
			updateX(180); 
			return;
		}
		//updateAngle(100,.1);
		if (Angle < 180){//too far CCW
			create_drive_direct(adjust_speed, -adjust_speed);//CW adjust
			while (updateAngle(0,.1) > 180){}
			create_stop();
			updateX(180);
			return;
		}
		//updateAngle(100,.1);
	}
	create_stop();
	//updateX(-180);
}
void turnFast180CCW(){
	create_drive(-101.3*2.0,1);
	sleep(2.057252314);
	create_stop();
	updateX(180);
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
	if (side==LEFT)  turn(-deg);
	if (side==RIGHT) turn( deg);
}
void turnFastForLeft(int deg){
	if (side==LEFT)  turn ( deg);
	if (side==RIGHT) turn (-deg);
}
#endif
