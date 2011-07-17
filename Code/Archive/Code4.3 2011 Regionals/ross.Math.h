//
// "ross.Math.h"
//
// Programmer:    Ross Mead
// Last modified: 07Aug2007
//

// preprocessor directives
#include "ross.Boolean.h"

#ifndef	 ROSS_MATH_OPEN
#define	 ROSS_MATH_OPEN
#include "ross.Declarations.h"



// pi definitions
#define PI             3.1415926535897932384626433832795
float   TWO_PI      =  2.0 * PI;
float   PI_OVER_180 =  PI / 180.0;



// IEEE 754 single precision machine epsilon definitions
// (used for comparing floating-point numbers)
//#define F_EPSILON      5.96046447753906E-8
#define F_EPSILON      5E-6



// minimum/maximum number definitions
/*//Change 005
const int     MAX_INT     =  pow(2, 15) - 1;
const int     MIN_INT     =  MAX_INT + 1;
const long    MAX_LONG    =  lpow(2L, 31L) - 1L;
const long    MIN_LONG    =  MAX_LONG + 1L;
const float   MAX_FLOAT   =  fpow(2.0, 24.0);
const float   MIN_FLOAT   = -MAX_FLOAT;
*/
#define MAX_INT		(pow(2, 15) - 1)
#define MIN_INT		(MAX_INT + 1)
#define MAX_LONG    (lpow(2L, 31L) - 1L)
#define MIN_LONG	(MAX_LONG + 1L)
#define MAX_FLOAT   (fpow(2.0, 24.0))
#define MIN_FLOAT   (-MAX_FLOAT)


// undefined number definitions
#define I_UNDEFINED    MAX_INT
#define L_UNDEFINED    MAX_LONG
#define F_UNDEFINED    MAX_FLOAT



// returns the absolute value of the parameterized integer
int abs(int i)
{
    return i * sign(i);
}   // abs(int)



// returns the arc-tangent of the parameterized xy-coordinates,
// with consideration to the quadrant
/*//Change 003
float atan2(float y, float x)
{
    if (fisEqualToZero(x)) {
        if (fisEqualToZero(y)) return 0.0;
        return scaleRadians(fsign(y) * PI / 2.0);
    }
    if (x < 0.0) {
        if (fisEqualToZero(y)) return PI;
        return scaleRadians(-fsign(y) * (PI - fsign(y) * atan(y / x)));
    }
    return scaleRadians(atan(y / x));
}   // atan2(float, float)
*/


// returns the clipped value of the parameterized integer
// based on the parameterized [min, max]
int clip(int i, int min, int max)
{
    if (i < min) return min;
    if (i > max) return max;
    return              i;
}   // clip(int, int, int)



// returns the cube of the parameterized integer
int cube(int i)
{
    return i * i * i;
}   // cube(int)



// returns the Euclidean distance between the
// parameterized (x1, y1) and (x2, y2) coordinates
float dist(float x1, float y1, float x2, float y2)
{
//  float mdist = mdist(x1, y1, x2, y2);
    return sqrt(mdist(x1, y1, x2, y2));
}   // dist(float, float, float, float)



// returns the absolute value of the parameterized floating-point number
/*//Change 003
float fabs(float f)
{
    return f * fsign(f);
}   // fabs(float)
*/


// returns the clipped value of the parameterized floating-point
// number based on the parameterized [min, max]
float fclip(float f, float min, float max)
{
    if (f < min) return min;
    if (f > max) return max;
    return              f;
}   // fclip(float, float, float)



// returns TRUE if the two parameterized floating-point
// numbers are equal, FALSE otherwise
BOOL fcompare(float a, float b)
{
    return fabs(a - b) <= F_EPSILON;
}   // fcompare(float, float)



// returns the cube of the parameterized floating-point number
float fcube(float f)
{
    return f * f * f;
}   // fcube(float)



// returns the value of the IEEE 754 single precision machine epsilon
// (used for comparing floating-point numbers)
float fepsilon()
{
    return F_EPSILON;
}   // fepsilon()



// returns TRUE if the parameterized floating-point number
// is between [min, max], FALSE otherwise
BOOL fisBetween(float f, float min, float max)
{
    return (f >= min) && (f <= max);
}   // fisBetween(float, float, float)



// returns TRUE if the parameterized floating-point
// number is equal to zero, FALSE otherwise
BOOL fisEqualToZero(float f)
{
    return fcompare(f, 0.0);
}   // fisEqualToZero(float)



// returns the maximum of the two parameterized floating-point numbers
/*//Change 003
float fmax(float a, float b)
{
    if (a > b) return a;
    return b;
}   // fmax(float, float)
*/


// returns the midpoint of the two parameterized floating-point numbers
float fmid(float a, float b)
{
    return 0.5 * (a + b);
}   // fmid(float, float)



// returns the minimum of the two parameterized floating-point numbers
/*//Change 003
float fmin(float a, float b)
{
    if (a < b) return a;
    return b;
}   // fmin(float, float)
*/


// returns the value of x % y
/*//Change 003
float fmod(float x, float y)
{
    if (y == 0.0) return F_UNDEFINED;
    return x - (float)((int)(x / y)) * y;
}   // fmod(float, float)
*/


// returns the normalized form of the parameterized
// floating-point number and sets, by reference,
// the exponent (if applicable)
float fnorm(float f, int* e)
{
    if (e != NULL) *e = 0;
    if (!fisEqualToZero(f)) {
        while (fabs(f) > 10.0) {
            f /= 10.0;
            if (e != NULL) ++(*e);
        }
        while (fabs(f) <  1.0) {
            f *= 10.0;
            if (e != NULL) --(*e);
        }
    }
    printf("fnorm = %f\n", f);
    return f;
}   // fnorm(float)



// returns the value of x ^ y
float fpow(float x, float y)
{
    if ((x == 0.0) && (y == 0.0)) return F_UNDEFINED;
    if (x < 0.0) {
        if (y != (float)(int)y)   return F_UNDEFINED;
        x *= -1.0;
        if (isOdd((int)y))        return -1.0 * exp(y * log(x));
    }
    return exp(y * log(x));
}   // fpow(float, float)



// returns the sign of the parameterized floating-point number
float fsign(float f)
{
    if (f > F_EPSILON) return  1.0;
    if (f < 0.0)       return -1.0;
    return                     0.0;
}   // fsign(float)



// returns the square of the parameterized floating-point number
float fsquare(float f)
{
    return f * f;
}   // fsquare(float)



// returns the wrapped value of the parameterized floating-point
// number based on the parameterized [min, max]
float fwrap(float f, float min, float max)
{
    if (f < min) return max;
    if (f > max) return min;
    return              f;
}   // fwrap(float, float, float)



// returns TRUE if the parameterized integer
// is between [min, max], FALSE otherwise
BOOL isBetween(int i, int min, int max)
{
    return (i >= min) && (i <= max);
}   // isBetween(int, int, int)



// returns TRUE if the parameterized integer is even, TRUE otherwise
BOOL isEven(int i)
{
    return (i % 2) == 0;
}   // isEven(int)



// returns TRUE if the parameterized integer is odd, FALSE otherwise
BOOL isOdd(int i)
{
    return (i % 2) != 0;
}   // isOdd(int)



// returns the absolute value of the parameterized long integer
long labs(long l)
{
    return l * lsign(l);
}   // labs(int)



// returns the clipped value of the parameterized long
// integer based on the parameterized [min, max]
long lclip(long l, long min, long max)
{
    if (l < min) return min;
    if (l > max) return max;
    return              l;
}   // lclip(long, long, long)



// returns the cube of the parameterized long integer
long lcube(long l)
{
    return l * l * l;
}   // lcube(long)



// returns TRUE if the parameterized long integer
// is between [min, max], FALSE otherwise
BOOL lisBetween(long l, long min, long max)
{
    return (l >= min) && (l <= max);
}   // lisBetween(long, long, long)



// returns TRUE if the parameterized long integer is even, FALSE otherwise
BOOL lisEven(long l)
{
    return (l % 2L) == 0L;
}   // lisEven(long)



// returns TRUE if the parameterized long integer is odd, FALSE otherwise
BOOL lisOdd(long l)
{
    return (l % 2L) != 0L;
}   // lisOdd(long)



// returns the maximum of the two parameterized long integers
long lmax(long a, long b)
{
    if (a > b) return a;
    return b;
}   // max(long, long)



// returns the midpoint of the two parameterized long integers
float lmid(long a, long b)
{
    return 0.5 * (float)(a + b);
}   // lmid(long, long)



// returns the minimum of the two parameterized long integers
long lmin(long a, long b)
{
    if (a < b) return a;
    return b;
}   // min(long, long)



// returns the value of x^y
long lpow(long x, long y)
{
    long l = 0L, value = 1L;
    if (x == 0L) {
        if (y <= 0L) return L_UNDEFINED;
        return 0L;
    }
    if (y < 0L)      return 0L;
    for (l = 0L; l < y; ++l) value *= x;
    return value;
}   // lpow(long, long)



// returns the sign of the parameterized long integer
long lsign(long l)
{
    if (l > 0L) return  1L;
    if (l < 0L) return -1L;
    return 0L;
}   // sign(long)



// returns the square of the parameterized long integer
long lsquare(long l)
{
    return l * l;
}   // lsquare(long)



// returns the wrapped value of the parameterized long
// integer based on the parameterized [min, max]
long lwrap(long l, long min, long max)
{
    if (l < min) return max;
    if (l > max) return min;
    return              l;
}   // lwrap(long, long, long)



// returns the maximum of the two parameterized integers
/*//Change 004
int max(int a, int b)
{
    if (a > b) return a;
    return b;
}   // max(int, int)
*/


// returns the Manhattan distance between the
// parameterized (x1, y1) and (x2, y2) coordinates
float mdist(float x1, float y1, float x2, float y2)
{
    return fsquare(x2 - x1) + fsquare(y2 - y1);
}   // mdist(float, float, float, float)



// returns the midpoint of the two parameterized integers
float mid(int a, int b)
{
    return 0.5 * (float)(a + b);
}   // mid(int, int)



// returns the minimum of the two parameterized integers
/*//Change 004
int min(int a, int b)
{
    if (a < b) return a;
    return b;
}   // min(int, int)
*/


// returns the value of pi
float pi()
{
    return PI;
}   // pi()



// returns the value of pi / 180
float piOver180()
{
    return PI_OVER_180;
}   // piOver180()



// returns the value of x^y
/*//Change 003
int pow(int x, int y)
{
    int i = 0, value = 1;
    if (x == 0) {
        if (y <= 0) return I_UNDEFINED;
        return 0;
    }
    if (y < 0)      return 0;
    for (i = 0; i < y; ++i) value *= x;
    return value;
}   // pow(int, int)
*/


// returns parameterized angle (in degrees) scaled to an angle [-180, 180]
float scaleDegrees(float degrees)
{
    degrees = fmod(degrees,   360.0);
    if (fabs(degrees) > 180.0)
      return degrees - fsign(degrees) * 360.0;
    return degrees;
}   // scaleDegrees(float)



// returns the parameterized angle (in radians) scaled to an angle [-PI, PI]
float scaleRadians(float radians)
{
    radians = fmod(radians,   TWO_PI);
    if (fabs(radians) > PI)
      return radians - fsign(radians) * TWO_PI;
    return radians;
}   // scaleRadians(float)



// returns the sign of the parameterized integer
int sign(int i)
{
    if (i > 0) return  1;
    if (i < 0) return -1;
    return 0;
}   // sign(int)



// returns the square of the parameterized integer
int square(int i)
{
    return i * i;
}   // square(int)



// returns the value of 2.0 * PI
float twoPi()
{
    return TWO_PI;
}   // twoPi()



// returns the wrapped value of the parameterized integer
// based on the parameterized [min, max]
int wrap(int i, int min, int max)
{
    if (i < min) return max;
    if (i > max) return min;
    return              i;
}   // wrap(int, int, int)
#endif
