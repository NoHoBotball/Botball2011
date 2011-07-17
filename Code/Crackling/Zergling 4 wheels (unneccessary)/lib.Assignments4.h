#define touch digital(8) //Touch sensor on the front
#define leftIR analog10(6) //IR sensor on left claw
#define rightIR analog10(4) //IR sensor on right claw
#define threshold 512 //To differentiate between white board and black lines
#define left 0 //Left side of botguy
#define right 1//Right side of botguy
#define dragL //Used to slow down left wheel if needed
#define dragR //Used to slow down right wheel if needed
#define dragTurn 0.7444444444444444 //(268/360)Used for the turn_degrees function. The gears will change the amount that the wheels spin
#define motorLB 3
#define motorLF 2
#define motorRB 1
#define motorRF 0

int motorLB; //Left motor back
int motorLF; //Left motor front
int motorRB; //Right motor back
int motorRF; //Right motor front
//int strategy; //Used to determine what strategy the Zergling will do
//char side; //Which side of game board?
