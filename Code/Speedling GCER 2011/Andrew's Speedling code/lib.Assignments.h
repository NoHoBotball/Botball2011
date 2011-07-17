//#define touch digital(8) //Touch sensor on the front
//#define claw 1//Claw is in servo port 1
//#define leftIR analog10(6) //IR sensor on left claw
//#define rightIR analog10(4) //IR sensor on right claw
//#define threshold 512 //To differentiate between white board and black lines
#define left 0 //Left side of botguy
#define right 1//Right side of botguy
#define dragL //Used to slow down left wheel if needed
#define dragR //Used to slow down right wheel if needed
#define dragTurn 2.01 //Used for the turn_degrees function. The gears will change the amount that the wheels spin

//these values are set in the Which Side function
/*int motorLT = 3; //Left motor top
int motorLB = 2; //Left motor bottom
int motorRT = 1; //Right motor top
int motorRB = 0; //Right motor bottom
*/ 

int motorLT;
int motorLB;
int motorRT;
int motorRB;
int IR_left=1; 
int IR_right=0; 
int strategy; //Used to determine what strategy the Zergling will do
char side; //Which side of game board?
int threshold = 190;//light threshold
int light_sensor = 7;//light sensor
int touch_sensor = 8; //front bump sensor
int forward_drag = 40; //drag while moving forward

