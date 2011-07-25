//
// "ross.Vector.h"
//
// Programmer:    Ross Mead
// Last modified: 05Nov2007
//

// preprocessor directives
#include "ross.Circles.h"

#ifndef	 ROSS_VECTORS
#define	 ROSS_VECTORS
#include "ross.Declarations.h"



// vector debug definitions
//#define DEBUG_VECTOR 1



// defines a 2-dimensional vector
struct Vector
{
    float x, y;
};  // Vector



// initializes the parameterized vector,
// returning TRUE if successful, FALSE otherwise
BOOL initVector(struct Vector* v)
{
    return setVector(v, 0.0, 0.0);
}   // initVector(struct Vector*)



// sets the parameterized vector to the parameterized
// xy-values, returning TRUE if successful, FALSE otherwise
BOOL setVector(struct Vector* v, float dx, float dy)
{
    if (v == NULL) return FALSE;
    v->x = dx;
    v->y = dy;
    return TRUE;
}   // setVector(struct Vector*, float, float)



// sets the parameterized vector to the parameterized
// polar-values, returning TRUE if successful, FALSE otherwise
BOOL setVectorPolar(struct Vector* v, float magnitude, float theta)
{
    theta = degreesToRadians(theta);
    return setVector(v, magnitude * cos(theta), magnitude * sin(theta));
}   // setVectorPolar(struct Vector*, float, float)



// copies the contents of the parameterized source
// vector into the parameterized destination vector,
// returning TRUE if successful, FALSE otherwise
BOOL copyVector(struct Vector* src, struct Vector* dest)
{
    if (src == NULL) return FALSE;
    return setVector(dest, src->x, src->y);
}   // copyVector(struct Vector*, struct Vector*)



// rotates the parameterized vector about
// itself based on the parameterized angle,
// returning TRUE if successful, FALSE otherwise
BOOL rotateVector(struct Vector* v, float theta)
{
    if (v == NULL) return FALSE;
    theta = degreesToRadians(theta);
    return setVector(v,
                     v->x * cos(theta) - v->y * sin(theta),
                     v->x * sin(theta) + v->y * cos(theta));
}   // rotateVector(struct Vector*, float)



// scales the parameterized vector based
// on the parameterized scalar, returning
// TRUE if successful, FALSE otherwise
BOOL scaleVector(struct Vector* v, float scale)
{
    if (v == NULL) return FALSE;
    return setVector(v, scale * v->x, scale * v->y);
}   // scaleVector(struct Vector*, float)



// adjusts the parameterized vector to unit length,
// returning TRUE if successful, FALSE otherwise.
BOOL normalizeVector(struct Vector* v)
{
    float magnitude = getVectorMagnitude(v);
    
    // does nothing to zero vectors
    if (fisEqualToZero(magnitude)) return FALSE;
    return scaleVector(v, 1.0 / magnitude);
}   // normalizeVector(struct Vector*)


// sets the angle of the parameterized vector
// to the parameterized angle, returning
// TRUE if successful, FALSE otherwise
BOOL setVectorAngle(struct Vector* v, float theta)
{
    if (v == NULL) return FALSE;
    return setVectorPolar(v, getVectorMagnitude(v), theta);
}   // setVectorAngle(struct Vector*, float)



// sets the magnitude of the parameterized vector
// to the parameterized magnitude, returning
// TRUE if successful, FALSE otherwise
BOOL setVectorMagnitude(struct Vector* v, float magnitude)
{
    if ((magnitude < 0.0) || (!normalizeVector(v))) return FALSE;
    return scaleVector(v, magnitude);
}   // setVectorAngle(struct Vector*, float)



// returns the angle of the parameterized vector
float getVectorAngle(struct Vector* v)
{
    if (v == NULL) return 0.0;
    return radiansToDegrees(atan2(v->y, v->x));
    
    /*if (fisEqualToZero(v->x)) {
        if (fisEqualToZero(v->y)) return 0.0;
        return fsign(v->y) * 90.0;
    }
    if (v->x < 0.0) {
        if (fisEqualToZero(v->y)) return 180.0;
        return -fsign(v->y) *
          radiansToDegrees(PI - fsign(v->y) * atan(v->y / v->x));
    }
    return radiansToDegrees(atan(v->y / v->x));*/
}   // getVectorAngle(struct Vector*)



// returns the magnitude of the parameterized vector
float getVectorMagnitude(struct Vector* v)
{
    if (v == NULL) return 0.0;
    return dist(0.0, 0.0, v->x, v->y);
}   // getVectorMagnitude(struct Vector*)



// returns TRUE if the magnitude of the parameterized vector is 0,
// FALSE otherwise
BOOL isZeroVector(struct Vector* v)
{
    if (v == NULL) return FALSE;
    return fisEqualToZero(getVectorMagnitude(v));
}   // isZeroVector(struct Vector*)



// sets the parameterized destination vector to
// the sum of the two parameterized vectors,
// returning TRUE if successful, FALSE otherwise
BOOL addVectors(struct Vector* v1, struct Vector* v2, struct Vector* v)
{
    if ((v1 == NULL) || (v2 == NULL)) return FALSE;
    return setVector(v, v1->x + v2->x, v1->y + v2->y);
}   // addVectors(struct Vector*, struct Vector*, struct Vector*)



// sets the parameterized destination vector to
// the difference of the two parameterized vectors,
// returning TRUE if successful, FALSE otherwise
BOOL subVectors(struct Vector* v1, struct Vector* v2, struct Vector* v)
{
    if ((v1 == NULL) || (v2 == NULL)) return FALSE;
    return setVector(v, v1->x - v2->x, v1->y - v2->y);
}   // subVectors(struct Vector*, struct Vector*, struct Vector*)



// sets the parameterized destination vector to
// the product of the two parameterized vectors,
// returning TRUE if successful, FALSE otherwise
BOOL multVectors(struct Vector* v1, struct Vector* v2, struct Vector* v)
{
    if ((v1 == NULL) || (v2 == NULL)) return FALSE;
    return setVector(v, v1->x * v2->x, v1->y * v2->y);
}   // subVectors(struct Vector*, struct Vector*, struct Vector*)



// sets the parameterized destination vector to
// the quotient of the two parameterized vectors,
// returning TRUE if successful, FALSE otherwise
BOOL divVectors(struct Vector* v1, struct Vector* v2, struct Vector* v)
{
    if ((v1 == NULL) || (v2 == NULL)) return FALSE;
    return setVector(v, v1->x / v2->x, v1->y / v2->y);
}   // subVectors(struct Vector*, struct Vector*, struct Vector*)



// negates the parameterized source vector,
// returning TRUE if successful, FALSE otherwise
BOOL negateVector(struct Vector* src, struct Vector* dest)
{
    return copyVector(src, dest) && scaleVector(dest, -1.0);
}   // negateVector(struct Vector*, struct Vector*)



// compares the two parameterized vectors for equality,
// returning TRUE if they are the same, FALSE otherwise
BOOL compareVectors(struct Vector* v1, struct Vector* v2)
{
    if ((v1 == NULL) || (v2 == NULL)) return FALSE;
    return fcompare(v1->x, v2->x) && fcompare(v1->y, v2->y);
}   // compareVectors(struct Vector*, struct Vector*)



// prints the parameterized vector (with an optional label) to the screen,
// returning TRUE if successful, FALSE otherwise
BOOL printVector(struct Vector* v, char label[])
{
    if (v == NULL) return FALSE;
    printf("%s: (%f, %f)\n", label, v->x, v->y);
    return TRUE;
}   // printVector(struct Vector*, char [])



#ifdef DEBUG_VECTOR
int main()
{
    struct Vector v1, v2;
    
    initVector(&v1);
    setVector(&v2, 12.0, 1.0);
    printf("\ninit\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    copyVector(&v2, &v1);
    setVector(&v2, 6.0, 11.0);
    printf("\ncopy\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    rotateVector(&v1, 45.0);
    printf("\nrotate\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    setVectorPolar(&v2, sqrt(2.0), 45.0);
    printf("\npolar\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    setVector(&v1, -1.0, 1.0);
    subVectors(&v1, &v2, &v1);
    printf("\ndiff\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    printf("\nv1.mag=%f\n", getVectorMagnitude(&v1));
    printf("v2.angle=%f\n", getVectorAngle(&v2));
    
    setVectorPolar(&v1, 2.0 * sqrt(2.0), 45.0);
    setVectorMagnitude(&v1, 4.0 * sqrt(2.0));
    setVectorMagnitude(&v2, 1.0);
    setVectorAngle(&v2, 90.0);
    printf("\nset mag/angle\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    setVector(&v1, 1.0, 0.0);
    setVector(&v2, 1.0, 1.0);
    printf("\ncompare\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    if (!compareVectors(&v1, &v2)) printf("not ");
    printf("equal\n");
    
    addVectors(&v1, &v2, &v1);
    printf("\narithmetic\n");
    printVector(&v1, "v1");
    printVector(&v2, "v2");
    
    return 0;
}   // main()
#endif
#endif
