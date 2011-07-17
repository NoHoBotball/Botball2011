#define left 0 //Left side of botguy
#define right 1//Right side of botguy
#define dragTurn 1.475 //Fine tuning for the spinCC(W)_degrees function
#define claw 2 //Claw is in servo port 2
#define touch digital(8) //Touch sensor is in digital port 8
#define leftIR analog10(lanalog) //IR sensor on left claw
#define rightIR analog10(ranalog) //IR sensor on right claw
#define threshold 650 //To differentiate between white board and black lines
#define airplane 1 //Airplane mini servo is port 0
#define fdrag 0.82 //Used to slow down right wheels when going forward
#define rdrag 0.83 //Used to slow right wheels when reversing so Crackling drives straight
#define tdrag 0.6 //CCW turn isn't enough
#define light 7


#define mLT 2 //These motor positions stay the same on both sides
#define mLB 3
#define mRT 1
#define mRB 0
int motorLT; //Left motor top
int motorLB; //Left motor bottom
int motorRT; //Right motor top
int motorRB; //Right motor bottom
int lanalog; //left light sensor
int ranalog; //right light sensor
float dragLT; //Used to slow down top left wheel if needed
float dragLB; //Used to slow down bottom left wheel if needed
float dragRT; //Used to slow down top right wheel if needed
float dragRB; //Used to slow down bottom right wheel if needed
float tdragL; //Use to slow down turning for left set of wheels
float tdragR; //Use to slow down turning for right set of wheels
float tdragL2;
float tdragR2;
int strategy; //Used to determine what strategy the Crackling will perform
char side; //Allows you to pick what side of the board the Crackling is on
