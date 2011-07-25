//Library -- Movement
//Movement Functions



#ifndef LIB_MOVEMENT
#define LIB_MOVEMENT
#ifdef CREATE
#include "ross.Metrics.h"

/*	
/	Description	:
/		-This File contains all funcions relating to the funcitonality of the 
/		 Drive Trains of all Create or 2wheel-based CBC robots
/
/	Written and Maintained By:
/		-Jae Kim		02/2011-
/		-Joseph McGee	02/2011-
/
/	
*/


/*	you must define
/		TOUCH_FRONT and either Create 
/		or CBC, motorR, motorL 
/		in the file from which this funcition is called
*/

//Drive functions
void drive(int speed);
void driveMm(float mm_speed, float seconds);//speed is mm/s
void driveIn(float in_speed, float seconds);//speed is in/s
void stop();
void stopIn(float seconds);

void driveAtMillimeters(int mm_speed);			             void driveAtMm(int mm_speed);
void driveAtInches(float in_speed);                          void driveAtIn(float in_speed);
void driveAtMillimetersFor(int mm_speed, float seconds);     void driveAtMmFor(int mm_speed, float seconds);
void driveAtInchesFor(float in_speed, float seconds);        void driveAtInFor(float mm_speed, float seconds);


//Turn functions
int X;//ideal turn correction factor
int Angle;

void turnAdjust(int margin_of_error);
int updateX(int increment);
int updateAngle(int wait, float lag);
void clearAngle();
void create_direct(int lspeed , int rspeed);
void adjustCW();
void adjustCCW();

void turn(int deg);
void turnFast(int deg);
void turnForRight(int deg);
void turnForLeft(int deg);

//Miscellaneous
//void forwardTouch(int speed);
void detectPVC();
void detectPVCSlow();
void detectBlock();
void backwardTouch(int speed);
void clearWall();
void backFromTouch(int stack_num);
void create_direct(int lspeed, int rspeed);
int beepFor(int num_of_beeps);
float timeLapse();

//Arm
void grabBlocks();
void blockStack1();
void blockStack2();
void blockStack3();

#include "lib.move.drive.c"
#include "lib.move.turn.c"
#include "lib.move.misc.c"
#include "lib.move.arm.c"

#endif
#endif
