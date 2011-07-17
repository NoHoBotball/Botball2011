/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

#define motorL 1//Left motor
#define motorR 0//Right motor
/* Global variables go below (if you absolutely need them).*/
void forward(int speed);
void reverse(int speed);
void left(int tspeed);
void right(int tspeed);
/*Function prototypes below*/

void forward(int speed)
{
	mav(motorL, speed);
	mav(motorR, speed);
}

void reverse(int speed)
{
	mav(motorL, -speed);
	mav(motorR, -speed);
}

void left(int tspeed)
{
	mav(motorL, tspeed / 2);
	mav(motorR, -tspeed / 2);
}

void right(int tspeed)
{
	mav(motorL, -tspeed / 2);
	mav(motorR, tspeed / 2);
}
