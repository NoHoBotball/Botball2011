#include "lib.Movement.h"
#include "lib.Rotation.h"

void toTape(int speed); //Go to tape at a speed
void offTape(int speed); //Get off tape at a speed
void bothToTape(int speed); //Only one IR sensor has to touch tape to stop
void bothOffTape(int speed); //Only one IR sensor has to come off of tape to stop
void straightTape(int speed, int tspeed); //Crackling turns perpendicular to tape
void straightOff(int speed, int tspeed); //Straightens while going off tape
void toTouch(int speed); //Goes at a speed until Crackling hits touch sensor
void dropAirplane(); //Drops paper airplane
void reverseOffTape(int speed, int tspeed);

void toTape(int speed) 
{ 
	forward(speed);
	while((leftIR < threshold) || (rightIR < threshold)) 
	{
	}
	stop();
}

void offTape(int speed)
{
	forward(speed);
	while((leftIR > threshold) || (rightIR > threshold)) 
	{
	}
	stop();
}

void bothToTape(int speed)
{
	forward(speed);
	while((leftIR < threshold) && (rightIR < threshold)) 
	{
	}
	stop();
}

void bothOffTape(int speed)
{
	forward(speed);
	while((leftIR > threshold) && (rightIR > threshold)) 
	{
	}
	stop();
}

void reverseOffTape(int speed, int tspeed)
{
	reverse(speed);
	while (leftIR < threshold || rightIR < threshold)
	{		
		
		if(leftIR > threshold && rightIR < threshold)
		{
			while (leftIR > threshold && rightIR < threshold)
			{
				onlyRight(tspeed);
			}
			stop();
		}
		if (leftIR < threshold && rightIR > threshold)
		{
			while (leftIR < threshold && rightIR > threshold)
			{
				onlyLeft(speed);
			}
			stop();
		}
	}
		stop();
}

void straightTape(int speed, int tspeed)
{
	forward(speed);
	while (leftIR < threshold || rightIR < threshold)
	{		
		
		if(leftIR > threshold && rightIR < threshold)
		{
			while (leftIR > threshold && rightIR < threshold)
			{
				onlyRight(tspeed);
			}
			stop();
		}
		if (leftIR < threshold && rightIR > threshold)
		{
			while (leftIR < threshold && rightIR > threshold)
			{
				onlyLeft(tspeed);
			}
			stop();
		}
	}
		stop();
}

void straightOff(int speed, int tspeed)
{
	forward(speed);
	while (leftIR > threshold || rightIR > threshold)
	{			
		if(leftIR < threshold && rightIR > threshold)
		{
			while (leftIR < threshold && rightIR > threshold)
			{
				onlyRight(tspeed);
			}
			stop();
		}
		if (leftIR > threshold && rightIR < threshold)
		{
			while (leftIR > threshold && rightIR < threshold)
			{
				onlyLeft(speed);
			}
			stop();
		}
	}
	stop();
}


void toTouch(int speed)
{
	forward(speed);
	while (touch == 0)
	{
	}
}
