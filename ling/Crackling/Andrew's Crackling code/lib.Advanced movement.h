#include "lib.Movement.h"
#include "lib.Rotation.h"

void toTape(int speed); //Go to tape at a speed
void offTape(int speed); //Get off tape at a speed
void bothToTape(int speed); //Only one IR sensor has to touch tape to stop
void bothOffTape(int speed); //Only one IR sensor has to come off of tape to stop
void straightTape(int speed, int tspeed); //Crackling turns perpendicular to tape
void straightOff(int speed, int tspeed); //Straightens while going off tape
void toTouch(int speed); //Goes at a speed until Crackling hits touch sensor
void reverseOffTape(int speed, int tspeed); //Reverse straight tape

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
	while (leftIR > threshold && rightIR > threshold)
	{		
		reverse(speed);
	}
	stop();
	if(leftIR > threshold && rightIR < threshold)
	{
		while (leftIR > threshold && rightIR < threshold)
		{
			onlyLeft(-tspeed);
		}
		stop();
	}
	if (leftIR < threshold && rightIR > threshold)
	{
		while (leftIR < threshold && rightIR > threshold)
		{
			onlyRight(-tspeed);
		}
		stop();
	}
}

void straightTape(int speed, int tspeed)
{

	while (leftIR < threshold && rightIR < threshold)
	{
		forward(speed);
	}
	stop();
	if (leftIR > threshold && rightIR < threshold)
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

void straightOff(int speed, int tspeed)
{	
	while (leftIR > threshold && rightIR > threshold)
	{
		forward(speed);
	}
	stop();
	if (leftIR < threshold && rightIR > threshold)
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
			onlyLeft(tspeed);
		}
	stop();
	}
}


void toTouch(int speed)
{
	forward(speed);
	while (touch == 0)
	{
	}
}
