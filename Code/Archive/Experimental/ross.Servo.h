//
// "ross.Servo.h"
//
// Programmer:    Ross Mead
// Last modified: 22Jun2007
//

// preprocessor directives
#include "ross.Math.h"

#ifndef	 ROSS_SERVOS
#define	 ROSS_SERVOS
#include "ross.Declarations.h"


// servo debug definitions
//#define DEBUG_SERVO 1



// defines a servo
struct Servo
{
    int   port, minPosition, maxPosition;
    float minAngle, maxAngle;
};  // Servo



// initializes the parameterized servo,
// returning TRUE if successful, FALSE otherwise
BOOL initServo(struct Servo* s)
{
    return setServo(s, -1, 0, 255, 0.0, 180.0);
}   // initServo(struct Servo*)



// sets the parameterized servo to the parameterized
// values, returning TRUE if successful, FALSE otherwise
BOOL setServo(struct Servo* s,        int   p,
              int           minPos,   int   maxPos,
              float         minTheta, float maxTheta)
{
    return setServoPort(s, p)        &&
      setServoMinPosition(s, minPos) &&
      setServoMaxPosition(s, maxPos) &&
      setServoMinAngle(s, minTheta)  &&
      setServoMaxAngle(s, maxTheta);
}   // setServo(struct Neighbor*, struct Relationship*, struct State*)



// sets the port of the parameterized servo to the parameterized
// port, returning TRUE if successful, FALSE otherwise
BOOL setServoPort(struct Servo* s, int p)
{
    if (s == NULL) return FALSE;
    s->port = p;
    return TRUE;
}   // setServoPort(struct Servo*, int)



// sets the minimum position of the parameterized servo to the parameterized
// minimum position, returning TRUE if successful, FALSE otherwise
BOOL setServoMinPosition(struct Servo* s, int minPos)
{
    if (s == NULL) return FALSE;
    s->minPosition = minPos;
    return TRUE;
}   // setServoMinPosition(struct Servo*, int)



// sets the maximum position of the parameterized servo to the parameterized
// maximum position, returning TRUE if successful, FALSE otherwise
BOOL setServoMaxPosition(struct Servo* s, int maxPos)
{
    if (s == NULL) return FALSE;
    s->maxPosition = maxPos;
    return TRUE;
}   // setServoMaxPosition(struct Servo*, int)



// sets the minimum angle of the parameterized servo to the parameterized
// minimum angle returning TRUE if successful, FALSE otherwise
BOOL setServoMinAngle(struct Servo* s, float minTheta)
{
    if ((s == NULL) || (minTheta > s->maxAngle)) return FALSE;
    s->minAngle = minTheta;
    return TRUE;
}   // setServoMinAngle(struct Servo*, float)



// sets the maximum angle of the parameterized servo to the parameterized
// maximum angle, returning TRUE if successful, FALSE otherwise
BOOL setServoMaxAngle(struct Servo* s, float maxTheta)
{
    if ((s == NULL) || (maxTheta < s->minAngle)) return FALSE;
    s->maxAngle = maxTheta;
    return TRUE;
}   // setServoMaxAngle(struct Servo*, float)



// sets the position of the parameterized servo to the parameterized
// position, returning the new servo position if successful, -1 otherwise
BOOL setServoPosition(struct Servo* s, int pos)
{
    if ((s == NULL) ||
        (!isBetween(pos, s->minPosition, s->maxPosition))) return -1;
    set_servo_position(s->port, pos);
    return getServoPosition(s);
}   // setServoPosition(struct Servo*, int)



// sets the angle of the parameterized servo to the parameterized
// angle, returning the new servo position if successful, -1 otherwise
BOOL setServoAngle(struct Servo* s, float angle)
{
    if ((s == NULL) || (!fisBetween(angle, s->minAngle, s->maxAngle)))
      return -1;
    return setServoPosition(s, s->minPosition +
                            (int)((float)(s->maxPosition - s->minPosition) *
                                  angle / (s->maxAngle - s->minAngle)));
}   // setServoAngle(struct Servo*, float)



// returns the position of the parameterized servo
int getServoPosition(struct Servo* s)
{
    if (s == NULL) return -1;
    return get_servo_position(s->port);
}   // getServoPosition(struct Servo*)



// returns the angle of the parameterized servo
float getServoAngle(struct Servo* s)
{
    int pos = getServoPosition(s);
    if ((pos == -1) || (!isServoValid(s))) return -1.0;
    return (s->maxAngle - s->minAngle) *
      (float)(pos - s->minPosition) / (float)(s->maxPosition - s->minPosition);
}   // getServoAngle(struct Servo*)



// returns TRUE if the parameterized servo has
// valid values for its data members, FALSE otherwise
BOOL isServoValid(struct Servo* s)
{
    return (s != NULL) && (s->port != -1) &&
      (s->minPosition <= s->maxPosition)  && (s->minAngle <= s->maxAngle);
}   // isServoValid(struct Servo*)



// copies the contents of the parameterized source
// servo into the parameterized destination servo,
// returning TRUE if successful, FALSE otherwise
BOOL copyServo(struct Servo* src, struct Servo* dest)
{
    if (src == NULL) return FALSE;
    return setServo(dest,             src->port,
                    src->minPosition, src->maxPosition,
                    src->minAngle,    src->maxAngle);
}   // copyServo(struct Servo*, struct Servo*)



// prints the parameterized servo (with an optional label) to the screen
BOOL printServo(struct Servo* s, char label[])
{
    if (s == NULL) return FALSE;
    printf("%s[%d]:\n", label, s->port);
    printf("- minPos=%d, maxPos=%d\n", s->minPosition, s->maxPosition);
    printf("- minPos=%f, maxPos=%f\n", s->minAngle,    s->maxAngle);
    return TRUE;
}   // printServo(struct Servo*, char [])



#ifdef DEBUG_SERVO
int main()
{
    int angle = 0, interval = 5;
    struct Servo servo;
    setServo(&servo, 2, 24, 240, 0.0, 180.0);
    
    enable_servos();
    while (!b_button()) {
        display_clear();
        if      (left_button()  && (angle <= 180 - interval)) {
            angle += interval;
            setServoAngle(&servo, (float)angle);
        }
        else if (right_button() && (angle >  interval - 1)) {
            angle -= interval;
            setServoAngle(&servo, (float)angle);
        }
        printf("angle=%f(%d)\n", getServoAngle(&servo), angle);
        sleep(0.1);
    }
    disable_servos();
    return 0;
}   // main()
#endif
#endif
