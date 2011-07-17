//Robotics Club Libraries
//Robotics Club General 2011 Library
#ifdef  LIB_GENERAL_2011
#ifndef LIB_GENERAL_2011_CLOSE
extern void initialize();  //lib.ScorerStart.h
extern void whichSide();   //lib.ScorerStart.h
extern void ScorerStart(); //lib.ScorerStart.h
extern void ScorerNav();   //lib.ScorerNav.h
extern void SafetyNav();   //lib.SafetyNav.h
extern void Lift();        //lib.Lift.h
#define LIB_GENERAL_2011_CLOSE
#endif
#endif

//Ross's Library's

//Ross's Array Library Declarations
#ifdef 	ROSS_ARRAY
#ifndef	ROSS_ARRAY_CLOSE
extern BOOL  arrayClear(int array[]);
extern BOOL  arrayCopy(int src[], int dest[]);
extern int   arrayMax(int array[]);
extern int   arrayMin(int array[]);
extern void  arrayPrint(int array[], char label[]);
extern BOOL  arraySort(int array[]);
extern BOOL  arraySwap(int array[], int i, int j);
extern BOOL  farrayClear(float array[]);
extern BOOL  farrayCopy(float src[], float dest[]);
extern float farrayMax(float array[]);
extern float farrayMin(float array[]);
extern void  farrayPrint(float array[], char label[]);
extern BOOL  farraySort(float array[]);
extern BOOL  farraySwap(float array[], int i, int j);
extern BOOL  larrayClear(long array[]);
extern BOOL  larrayCopy(float src[], float dest[]);
extern long  larrayMax(long array[]);
extern long  larrayMin(long array[]);
extern void  larrayPrint(long array[], char label[]);
extern BOOL  larraySort(long array[]);
extern BOOL  larraySwap(long array[], int i, int j);
#define	ROSS_ARRAY_CLOSE
#endif
#endif

//Ross's Behavior Library
#ifdef ROSS_BEHAVIOR
#ifndef ROSS_BEHAVIOR_CLOSE
extern BOOL initBehavior(struct Behavior* b);
extern BOOL setBehavior(struct Behavior* b, BehaviorType type, int s);
extern BOOL setBehaviorType(struct Behavior* b, BehaviorType type);
extern BOOL setBehaviorStatus(struct Behavior* b, int s);
extern BOOL copyBehavior(struct Behavior* src, struct Behavior* dest);
extern BOOL isBehaviorActive(struct Behavior* b);
extern BOOL isBehaviorDone(struct Behavior* b);
extern BOOL isBehaviorInactive(struct Behavior* b);
extern BOOL isBehaviorStatus(struct Behavior* b, int s);
extern BOOL isBehaviorType(struct Behavior* b, BehaviorType type);
extern BOOL subsumeBehaviors(struct Behavior* bHigh,
                      struct Behavior* bLow,
                      struct Behavior* b);
extern BOOL compareBehaviors(struct Behavior* b1, struct Behavior* b2);
extern BOOL printBehavior(struct Behavior* b, char label[]);
#endif
#endif
//Ross's Buttons Library
#ifdef	ROSS_BUTTONS
#ifndef	ROSS_BUTTONS_CLOSE
extern void a_press();
extern void b_press();
extern void black_press();
extern void down_press();
extern void l_press();
extern void left_press();
extern void r_press();
extern void right_press();
extern void up_press();
#define	ROSS_BUTTONS_CLOSE
#endif
#endif


//Ross's Circles Library Declration
#ifdef 	ROSS_CIRCLES
#ifndef	ROSS_CIRCLES_CLOSE
extern float circumference(float diameter);
extern float degreesToRadians(float degrees);
extern float degToRad(float deg);
extern float diameterToRadius(float diameter);
extern float radiansToDegrees(float radians);
extern float radToDeg(float rad);
extern float radiusToDiameter(float radius);
#define	ROSS_CIRCLES
#endif
#endif

//Ross's Configuration File Declaration
#ifdef	CREATE_CONFIG
#ifndef	CREATE_CONFIG_CLOSE
extern BOOL enabledBackEMF();
#define	CREATE_CONFIG_CLOSE
#endif
#endif

//Ross's Math Library Declarations
#ifdef 	ROSS_MATH
#ifndef	ROSS_MATH_CLOSE
extern int abs(int i);
//extern float atan2(float y, float x);	//Change 003
extern int clip(int i, int min, int max);
extern int cube(int i);
extern float dist(float x1, float y1, float x2, float y2);
//extern float fabs(float f);
extern float fclip(float f, float min, float max);
extern BOOL fcompare(float a, float b);
extern float fcube(float f);
extern float fepsilon();
extern BOOL fisBetween(float f, float min, float max);
extern BOOL fisEqualToZero(float f);
//extern float fmax(float a, float b);	//Change 003
extern float fmid(float a, float b);
//extern float fmin(float a, float b);	//Change 003
//extern float fmod(float x, float y);	//Change 003
extern float fnorm(float f, int* e);
extern float fpow(float x, float y);
extern float fsign(float f);
extern float fsquare(float f);
extern float fwrap(float f, float min, float max);
extern BOOL isBetween(int i, int min, int max);
extern BOOL isEven(int i);
extern BOOL isOdd(int i);
extern long labs(long l);
extern long lclip(long l, long min, long max);
extern long lcube(long l);
extern BOOL lisBetween(long l, long min, long max);
extern BOOL lisEven(long l);
extern BOOL lisOdd(long l);
extern long lmax(long a, long b);
extern float lmid(long a, long b);
extern long lmin(long a, long b);
extern long lpow(long x, long y);
extern long lsign(long l);
extern long lsquare(long l);
extern long lwrap(long l, long min, long max);
//extern int max(int a, int b);		//Change 004
extern float mdist(float x1, float y1, float x2, float y2);
extern float mid(int a, int b);		
//extern int min(int a, int b);		//Change 004
extern float pi();
extern float piOver180();
//extern int pow(int x, int y);		//Change 003
extern float scaleDegrees(float degrees);
extern float scaleRadians(float radians);
extern int sign(int i);
extern int square(int i);
extern float twoPi();
extern int wrap(int i, int min, int max);
#define	ROSS_MATH_CLOSE
#endif
#endif


//Ross's Metrics Library Declarations
#ifdef	ROSS_METRICS
#ifndef	ROSS_METRICS_CLOSE
float centimetersPerInch();
float centimetersToFeet(float centimeters);
float centimetersToInches(float centimeters);
float centimetersToMillimeters(float centimeters);
float cmPerIn();
float cmToFt(float cm);
float cmToIn(float cm);
float cmToMm(float cm);
float feetToCentimeters(float feet);
float feetToInches(float feet);
float feetToMillimeters(float feet);
float ftToCm(float ft);
float ftToIn(float ft);
float ftToMm(float ft);
float inchesPerFoot();
float inchesToCentimeters(float inches);
float inchesToFeet(float inches);
float inchesToMillimeters(float inches);
float inPerFt();
float inToCm(float in);
float inToFt(float in);
float inToMm(float in);
float millimetersPerCentimeter();
float millimetersToCentimeters(float millimeters);
float millimetersToFeet(float millimeters);
float millimetersToInches(float millimeters);
float mmPerCm();
float mmToCm(float mm);
float mmToFt(float mm);
float mmToIn(float mm);
#define	ROSS_METRICS_CLOSE
#endif
#endif


//Ross's Motors Library Declarations
#ifdef	ROSS_MOTORS
#ifndef	ROSS_MOTORS_CLOSE
extern int brakeMotor(int port);
extern long getMotorPosition(int port);
extern int getMotorVelocity(int port);
extern int getMotorVelocityArray(int port);
extern int isValidMotorPort(int port);
extern long resetMotorPosition(int port);
extern long setMotorPosition(int port, long pos);
extern int setMotorVelocity(int port, int vel);
extern int setMotorVelocityArray(int port, int vel);
extern int setMotorFor(int port, int speed, long ticks);
extern void waitForMotorDone(int port);
#define	ROSS_MOTORS_CLOSE
#endif
#endif


//Ross's Random Library Declarations
#ifdef	ROSS_RANDOM
#ifdef	ROSS_RANDOM_CLOSE
extern float frand(float min, float max);
extern float frandSign();
extern long lrand(long min, long max);
extern long lrandSign();
extern int rand(int min, int max);
extern int randSign();
#define ROSS_RANDOM_CLOSE
#endif
#endif


//Ross's Servo Library Declarations
#ifdef 	ROSS_SERVO
#ifndef	ROSS_SERVO_CLOSE
extern BOOL initServo(struct Servo* s);
extern BOOL setServo(struct Servo* s,        int   p,
					 int           minPos,   int   maxPos,
					 float         minTheta, float maxTheta);
extern BOOL setServoPort(struct Servo* s, int p);
extern BOOL setServoMinPosition(struct Servo* s, int minPos);
extern BOOL setServoMaxPosition(struct Servo* s, int maxPos);
extern BOOL setServoMinAngle(struct Servo* s, float minTheta);
extern BOOL setServoMaxAngle(struct Servo* s, float maxTheta);
extern BOOL setServoPosition(struct Servo* s, int pos);
extern BOOL setServoAngle(struct Servo* s, float angle);
extern int getServoPosition(struct Servo* s);
extern float getServoAngle(struct Servo* s);
extern BOOL isServoValid(struct Servo* s);
extern BOOL copyServo(struct Servo* src, struct Servo* dest);
extern BOOL printServo(struct Servo* s, char label[]);
#define	ROSS_SERVO_CLOSE
#endif
#endif


//Ross's Vector Library Declarations
#ifdef	ROSS_VECTORS
#ifndef	ROSS_VECTORS_CLOSE
extern BOOL initVector(struct Vector* v);
extern BOOL setVector(struct Vector* v, float dx, float dy);
extern BOOL setVectorPolar(struct Vector* v, float magnitude, float theta);
extern BOOL copyVector(struct Vector* src, struct Vector* dest);
extern BOOL rotateVector(struct Vector* v, float theta);
extern BOOL scaleVector(struct Vector* v, float scale);
extern BOOL normalizeVector(struct Vector* v);
extern BOOL setVectorAngle(struct Vector* v, float theta);
extern BOOL setVectorMagnitude(struct Vector* v, float magnitude);
extern float getVectorAngle(struct Vector* v);
extern float getVectorMagnitude(struct Vector* v);
extern BOOL isZeroVector(struct Vector* v);
extern BOOL addVectors(struct Vector* v1, struct Vector* v2, struct Vector* v);
extern BOOL subVectors(struct Vector* v1, struct Vector* v2, struct Vector* v);
extern BOOL multVectors(struct Vector* v1, struct Vector* v2, struct Vector* v);
extern BOOL divVectors(struct Vector* v1, struct Vector* v2, struct Vector* v);
extern BOOL negateVector(struct Vector* src, struct Vector* dest);
extern BOOL compareVectors(struct Vector* v1, struct Vector* v2);
extern BOOL printVector(struct Vector* v, char label[]);
#define	ROSS_VECTORS_CLOSE
#endif
#endif


//Ross's Wheels Library Declarations
#ifdef	ROSS_WHEELS
#ifndef	ROSS_WHEELS_CLOSE
extern float degreesToCentimeters(float degrees);
extern float degToCm(float deg);
extern float degreesToInches(float degrees);
extern float degToIn(float deg);
extern float degreesToMillimeters(float degrees);
extern float degToMm(float deg);
extern float radiansToCentimeters(float radians);
extern float radToCm(float rad);
extern float radiansToInches(float radians);
extern float radToIn(float rad);
extern float radiansToMillimeters(float radians);
extern float radToMm(float rad);
extern float wheelCircumference();
extern float wheelDiameter();
extern float wheelOffsetDiameter();
#define	ROSS_WHEELS_CLOSE
#endif
#endif
