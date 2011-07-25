void toTape(int speed);
void offTape(int speed);
void toTouch(int speed);
void turnStraightonTape(int speed, int tspeed);
void turnStraightoffTape(int speed, int tspeed);
void toTape_left(int speed);

void toTape(int speed)
{
	forward(speed);
	while(analog(IR_left) < threshold && analog(IR_right) < threshold)
	{}
	stop();
}

void toTape_left(int speed)
{
	forward(speed);
	while(analog(IR_left) < threshold)
	{}
	stop();
}

void offTape(int speed)
{
	forward(speed);
	while (analog(IR_left) > threshold || analog(IR_right) > threshold)
	{}
	stop();
}

void toTouch(int speed)
{
while (digital(touch_sensor) == 0){//move to other side of game board
	forward(speed);
}
stop();
}

void turnStraightonTape(int speed, int tspeed)
{
	while (analog(IR_left) < threshold || analog(IR_right) < threshold)
	{
		forward(speed);			
		if(analog(IR_left) > threshold && analog(IR_right) < threshold)
		{
			stop();
			onlyRight(tspeed);
			while (analog(IR_left) > threshold && analog(IR_right) < threshold)
			{}
			stop();
		}
		if (analog(IR_left) < threshold && analog(IR_right) > threshold)
		{
			stop();
			onlyLeft(speed);
			while (analog(IR_left) < threshold && analog(IR_right) > threshold)
			{}
			stop();
		}
	}
	stop();
}

void turnStraightoffTape(int speed, int tspeed)
{
	while (analog(IR_left) > threshold || analog(IR_right) > threshold)
	{
		forward(speed);			
		if(analog(IR_left) > threshold && analog(IR_right) < threshold)
		{
			stop();
			onlyRight(tspeed);
			while (analog(IR_left)> threshold && analog(IR_right) < threshold)
			{}
			stop();
		}
		if (analog(IR_left) < threshold && analog(IR_right) > threshold)
		{
			stop();
			onlyLeft(speed);
			while (analog(IR_left) < threshold && analog(IR_right) > threshold)
			{}
			stop();
		}
	}
	stop();
}
