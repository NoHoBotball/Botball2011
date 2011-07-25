#define IR 0
#define Black 100
#define motorL 1//Left motor
#define motorR 0//Right motor
#define TouchSensor 8
#define CBC
#define	Front 0
#define	Right 1
#define	Back 2
	#define	Left 3
#include "lib.Movement.h"
#include "lib.ZerglingCamera.h"
char Side;
void WhichSide();
void Start();

int main()
{
	WhichSide();
	LuggageTrack();
	if (Side == Right)
	{
		LuggageTrack();
		sleep(1);
		drive(-500);
		while(analog(IR) > Black)
		{}
		ao();
		TurnCCW();
		sleep(1);
		//FIND GOING FORWARD WHILE CENTERING CODE
		
	}
}
void WhichSide () // For Left/Right of Botguy
{
	printf ("Press and hold button for 1 second.\n\tB button for Right side, A button for Left side.\n");
	while (b_button() == 0 && a_button() == 0)
	{
		sleep(1);
		printf ("Try again.\n");
	}
	if (b_button())
	{
		Side = Right;
		printf ("On Right of Botguy. Set up lights.\n");
		sleep(1);
	}
	if (a_button())
	{
		Side = Left;
		printf ("On Left of Botguy. Set up lights.\n");
		sleep(1);
	}
}
