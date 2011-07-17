//
// "ross.Circles.h"
//
// Programmer:    Ross Mead
// Last modified: 13Jul2007
//

// preprocessor directives
#include "ross.Math.h"

#ifndef	 ROSS_CIRCLES_OPEN
#define	 ROSS_CIRCLES_OPEN
#include "ross.Declarations.h"



// returns the circumference of a circle with the parameterized diameter
float circumference(float diameter)
{
    return diameter * PI;
}   // circumference(float)



// returns the value of the parameterized degrees in radians
float degreesToRadians(float degrees)
{
    return scaleDegrees(degrees) * PI_OVER_180;
}   // degreesToRadians(float)



// returns the value of the parameterized degrees in radians
float degToRad(float deg)
{
    return degreesToRadians(deg);
}   // degToRad(float)



// returns the radius of a circle with the parameterized diameter
float diameterToRadius(float diameter)
{
    return diameter / 2.0;
}   // diameterToRadius(float)



// returns the value of the parameterized radians in degrees
float radiansToDegrees(float radians)
{
    return scaleRadians(radians) / PI_OVER_180;
}   // radiansToDegrees(float)



// returns the value of the parameterized radians in degrees
float radToDeg(float rad)
{
    return radiansToDegrees(rad);
}   // radToDeg(float)



// returns the diameter of a circle with the parameterized radius
float radiusToDiameter(float radius)
{
    return radius * 2.0;
}   // radiusToDiameter(float)

#endif
