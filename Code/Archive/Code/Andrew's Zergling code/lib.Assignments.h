#include "lib.Which Side.h"

#define touch digital(8) //Touch sensor on the front
#define leftIR analog10(6) //IR sensor on left claw
#define rightIR analog10(4) //IR sensor on right claw
#define threshold 512 //To differentiate between white board and black lines
#define left 0 //Left side of botguy
#define right 1//Right side of botguy
#define dragL //Used to slow down left wheel if needed
#define dragR //Used to slow down right wheel if needed

int motorL; //Left motor
int motorR; //Right motor
int strategy; //Used to determine what strategy the Zergling will do
char side = null; //Which side of game board?

/*int main()
{
	while (side == null)
	{
		
	}
	
	if (side == left)
	{
		motorL = 3;
		motorR = 0;
	}
	if (side == right)
	{
		motorL = 0;
		motorR = 3;
	}
}