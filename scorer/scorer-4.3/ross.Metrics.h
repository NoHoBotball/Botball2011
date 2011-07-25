//
// "ross.Metrics.h"
//
// Programmer:    Ross Mead
// Last modified: 07Mar2007
//



// metric conversion definitions
#ifndef  ROSS_METRICS_OPEN
#define  ROSS_METRICS_OPEN
#include "ross.Declarations.h"

#define CM_PER_INCH   2.54
#define INCHES_PER_FT 12.0
#define MM_PER_CM     10.0



// returns the number of centimeters per inch
float centimetersPerInch()
{
    return CM_PER_INCH;
}   // centimetersPerInch()



// returns the value of the parameterized centimeters in feet
float centimetersToFeet(float centimeters)
{
    return inchesToFeet(centimetersToInches(centimeters));
}    // centimetersToFeet(float)



// returns the value of the parameterized centimeters in inches
float centimetersToInches(float centimeters)
{
    return (float)centimeters / CM_PER_INCH;
}    // centimetersToInches(float)



// returns the value of the parameterized centimeters in millimeters
float centimetersToMillimeters(float centimeters)
{
    return centimeters * MM_PER_CM;
}    // centimetersToMillimeters(float)



// returns the number of centimeters per inch
float cmPerIn()
{
    return centimetersPerInch();
}   // cmPerIn()



// returns the value of the parameterized centimeters in feet
float cmToFt(float cm)
{
    return centimetersToFeet(cm);
}    // cmToFt(float)



// returns the value of the parameterized centimeters in inches
float cmToIn(float cm)
{
    return centimetersToInches(cm);
}    // cmToIn(float)



// returns the value of the parameterized centimeters in millimeters
float cmToMm(float cm)
{
    return centimetersToMillimeters(cm);
}    // cmToMm(float)



// returns the value of the parameterized feet in centimeters
float feetToCentimeters(float feet)
{
    return inchesToCentimeters(feetToInches(feet));
}    // feetToCentimeters(float)



// returns the value of the parameterized feet in inches
float feetToInches(float feet)
{
    return feet * INCHES_PER_FT;
}   // feetToInches(float)



// returns the value of the parameterized feet in millimeters
float feetToMillimeters(float feet)
{
    return centimetersToMillimeters(feetToCentimeters(feet));
}   // feetToMillimeters(float)



// returns the value of the parameterized feet in centimeters
float ftToCm(float ft)
{
    return feetToCentimeters(ft);
}    // ftToCm(float)



// returns the value of the parameterized feet in inches
float ftToIn(float ft)
{
    return feetToInches(ft);
}   // ftToIn(float)



// returns the value of the parameterized feet in millimeters
float ftToMm(float ft)
{
    return feetToMillimeters(ft);
}   // ftToMm(float)



// returns the number of inches per foot
float inchesPerFoot()
{
    return INCHES_PER_FT;
}   // inchesPerFoot()



// returns the value of the parameterized inches in centimeters
float inchesToCentimeters(float inches)
{
    return inches * CM_PER_INCH;
}    // inchesToCentimeters(float)



// returns the value of the parameterized inches in feet
float inchesToFeet(float inches)
{
    return inches / INCHES_PER_FT;
}   // inchesToFeet(float)



// returns the value of the parameterized inches in millimeters
float inchesToMillimeters(float inches)
{
    return centimetersToMillimeters(inchesToCentimeters(inches));
}   // inchesToMillimeters(float)



// returns the number of inches per foot
float inPerFt()
{
    return inchesPerFoot();
}   // inPerFt()



// returns the value of the parameterized inches in centimeters
float inToCm(float in)
{
    return inchesToCentimeters(in);
}    // inToCm(float)



// returns the value of the parameterized inches in feet
float inToFt(float in)
{
    return inchesToFeet(in);
}   // inToFt(float)



// returns the value of the parameterized inches in millimeters
float inToMm(float in)
{
    return inchesToMillimeters(in);
}   // inToMm(float)



// returns the number of millimeters per centimeter
float millimetersPerCentimeter()
{
    return MM_PER_CM;
}   // millimetersPerCentimeter()



// returns the value of the parameterized millimeters in centimeters
float millimetersToCentimeters(float millimeters)
{
    return millimeters / MM_PER_CM;
}    // millimetersToCentimeters(float)



// returns the value of the parameterized millimeters in feet
float millimetersToFeet(float millimeters)
{
    return inchesToFeet(millimetersToInches(millimeters));
}    // millimetersToFeet(float)



// returns the value of the parameterized millimeters in inches
float millimetersToInches(float millimeters)
{
    return centimetersToInches(millimetersToCentimeters(millimeters));
}    // millimetersToInches(float)



// returns the number of millimeters per centimeter
float mmPerCm()
{
    return millimetersPerCentimeter();
}   // mmPerCm()



// returns the value of the parameterized millimeters in centimeters
float mmToCm(float mm)
{
    return millimetersToCentimeters(mm);
}    // mmToCm(float)



// returns the value of the parameterized millimeters in feet
float mmToFt(float mm)
{
    return millimetersToFeet(mm);
}    // mmToFt(float)



// returns the value of the parameterized millimeters in inches
float mmToIn(float mm)
{
    return millimetersToInches(mm);
}    // mmToIn(float)

#endif
