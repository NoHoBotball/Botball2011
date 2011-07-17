#define left 0 //Left side of botguy
#define right 1//Right side of botguy
#define dragTurn 1.475 //Fine tuning for the spinCC(W)_degrees function
#define claw 2 //Claw is in servo port 2
#define touch digital(8) //Touch sensor is in digital port 8
#define leftIR analog10(lanalog) //IR sensor on left claw
#define rightIR analog10(ranalog) //IR sensor on right claw
#define threshold 600 //To differentiate between white board and black lines
#define airplane 1 //Airplane mini servo is port 0
#define drag 0.85 //Used to slow right wheels when reversing so Crackling drives straight
#define tdrag 0.6 //In reverse, right wheels are faster

int motorLT; //Left motor top
int motorLB; //Left motor bottom
int motorRT; //Right motor top
int motorRB; //Right motor bottom
int lanalog;// left light sensor
int ranalog;//right light sensor
float dragLT; //Used to slow down top left wheel if needed
float dragLB; //Used to slow down bottom left wheel if needed
float dragRT; //Used to slow down top right wheel if needed
float dragRB; //Used to slow down bottom right wheel if needed
float tdragL; //Use to slow down turning for set of wheels
float tdragR; //Use to slow down turning for set of wheels
int strategy; //Used to determine what strategy the Crackling will perform
char side; //Allows you to pick what side of the board the Crackling is on
