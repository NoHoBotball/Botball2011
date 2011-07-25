//
// "ross.Random.h"
//
// Programmer:    Ross Mead
// Last modified: 09Jul2007
//

// preprocessor directives
#inlcude "ross.Math.h"

#ifndef	 ROSS_RANDOM
#define	 ROSS_RANDOM
#include "ross.Declarations.h"


// returns a random floating-point number between [min, max]
float frand(float min, float max)
{
    return min + (max - min) * (float)random(MAX_INT) / (float)MAX_INT;
}   // frand(float, float)



// returns a random floating-point sign
float frandSign()
{
    return (float)randSign();
}   // frandSign()



// returns a random long integer between [min, max]
long lrand(long min, long max)
{
    return (long)frand((float)min, (float)max);
}   // lrand(long, long)



// returns a random long integer sign
long lrandSign()
{
    return (long)randSign();
}   // lrandSign()



// returns a random integer between [min, max]
int rand(int min, int max)
{
    return min + random(MAX_INT) % max;
}   // rand(int, int)



// returns a random integer sign
int randSign()
{
    if (random(MAX_INT) % 2) return -1;
    return 1;
}   // randSign()
#endif
