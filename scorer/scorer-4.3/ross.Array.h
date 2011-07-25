//
// "ross.Array.h"
//
// Programmer:    Ross Mead
// Last modified: 27Jun2007
//

// preprocessor directives
#include "ross.Math.h"

#ifndef	 ROSS_ARRAY_OPEN
#define	 ROSS_ARRAY_OPEN
#include "ross.Declarations.h"



// clears the parameterized array of integers,
// returing TRUE if successful, FALSE otherwise
BOOL arrayClear(int array[])
{
    int  i = 0,     n = _array_size(array);
    for (i = 0; i < n; ++i) array[i] = 0;
    return TRUE;
}   // arrayClear(int [])



// copies the contents of the parameterized
// source array of integers into the parameterized
// destination array of integers, returing
// TRUE if successful, FALSE otherwise
BOOL arrayCopy(int src[], int dest[])
{
    int  i = 0, n = _array_size(src);
    if (n != _array_size(dest)) return FALSE;
    for (i = 0; i < n; ++i) dest[i] = src[i];
    return TRUE;
}   // arrayCopy(int [], int [])



// returns the maximum number in the parameterized array of integers
int arrayMax(int array[])
{
    int  i = 0,     n = _array_size(array), max = MIN_INT;
    for (i = 0; i < n; ++i)
      if (array[i] > max) max = array[i];
    return max;
}   // arrayMax(int [])



// returns the minimum number in the parameterized array of integers
int arrayMin(int array[])
{
    int  i = 0,     n = _array_size(array), min = MAX_INT;
    for (i = 0; i < n; ++i)
      if (array[i] < min) min = array[i];
    return min;
}   // arrayMin(int [])



// prints the parameterized array of integers
// (with an optional label) to the screen
void arrayPrint(int array[], char label[])
{
    int  i = 0,     n = _array_size(array);
    if (label != NULL) printf("%s:\n", label);
    printf("{");
    if (n > 0) {
        printf("%d,\n", array[0]);
        for (i = 1; i < n - 1; ++i) printf(" %d,\n", array[i]);
    }
    printf(" %d}\n", array[i]);
}   // arrayPrint(int [], char [])



// sorts the parameterized array of integers,
// returing TRUE if successful, FALSE otherwise
BOOL arraySort(int array[])
{
    int  i = 0, n = _array_size(array), done = FALSE;
    do {
        done = TRUE;
        --n;
        for (i = 0; i < n; ++i)
          if (array[i] > array[i + 1])
            if (!arraySwap(array, i, i + 1)) return FALSE;
            else done = FALSE;
    }  while (!done);
    return done;
}   // arraySort(int [])



// swaps the numbers at the parameterized indeces
// in the parameterized array of integers,
// returing TRUE if successful, FALSE otherwise
BOOL arraySwap(int array[], int i, int j)
{
    int temp = 0;
    if ((!isBetween(i, 0, _array_size(array) - 1)) ||
        (!isBetween(j, 0, _array_size(array) - 1)))
      return FALSE;
    temp     = array[i];
    array[i] = array[j];
    array[j] = temp;
    return TRUE;
}   // arraySwap(int [], int, int)



// clears the parameterized array of floating-point numbers,
// returing TRUE if successful, FALSE otherwise
BOOL farrayClear(float array[])
{
    int  i = 0,     n = _array_size(array);
    for (i = 0; i < n; ++i) array[i] = 0.0;
    return TRUE;
}   // farrayClear(float [])



// copies the contents of the parameterized
// source array of floating-point numbers
// into the parameterized destination array
// of floating-point numbers, returing
// TRUE if successful, FALSE otherwise
BOOL farrayCopy(float src[], float dest[])
{
    int  i = 0, n = _array_size(src);
    if (n != _array_size(dest)) return FALSE;
    for (i = 0; i < n; ++i) dest[i] = src[i];
    return TRUE;
}   // arrayCopy(float [], float [])



// returns the maximum number in the
// parameterized array of floating-point numbers
float farrayMax(float array[])
{
    int   i   = 0,     n = _array_size(array);
    float max = MIN_FLOAT;
    for ( i   = 0; i < n; ++i)
      if (array[i] > max) max = array[i];
    return max;
}   // farrayMax(float [])



// returns the minimum number in the
// parameterized array of floating-point numbers
float farrayMin(float array[])
{
    int   i   = 0,     n = _array_size(array);
    float min = MAX_FLOAT;
    for ( i   = 0; i < n; ++i)
      if (array[i] < min) min = array[i];
    return min;
}   // farrayMin(float [])



// prints the parameterized array of floating-point numbers
// (with an optional label) to the screen
void farrayPrint(float array[], char label[])
{
    int  i = 0,     n = _array_size(array);
    if (label != NULL) printf("%s:\n", label);
    printf("{");
    if (n > 0) {
        printf("%f,\n", array[0]);
        for (i = 1; i < n - 1; ++i) printf(" %f,\n", array[i]);
    }
    else printf("EMPTY");
    printf(" %f}\n", array[i]);
}   // larrayPrint(float [], char [])



// sorts the parameterized array of floating-point numbers,
// returing TRUE if successful, FALSE otherwise
BOOL farraySort(float array[])
{
    int  i = 0, n = _array_size(array), done = FALSE;
    do {
        done = TRUE;
        --n;
        for (i = 0; i < n; ++i)
          if (array[i] > array[i + 1])
            if (!farraySwap(array, i, i + 1)) return FALSE;
            else done = FALSE;
    }  while (!done);
    return done;
}   // farraySort(float [])



// swaps the numbers at the parameterized indeces
// in the parameterized array of floating-point numbers,
// returing TRUE if successful, FALSE otherwise
BOOL farraySwap(float array[], int i, int j)
{
    float temp = 0.0;
    if ((!isBetween(i, 0, _array_size(array) - 1)) ||
        (!isBetween(j, 0, _array_size(array) - 1)))
      return FALSE;
    temp       = array[i];
    array[i]   = array[j];
    array[j]   = temp;
    return TRUE;
}   // farraySwap(float [], int, int)



// clears the parameterized array of long integers,
// returing TRUE if successful, FALSE otherwise
BOOL larrayClear(long array[])
{
    int  i = 0,     n = _array_size(array);
    for (i = 0; i < n; ++i) array[i] = 0L;
    return TRUE;
}   // larrayClear(long [])



// copies the contents of the parameterized
// source array of long integers into the
// parameterized destination array of long integers,
// returing TRUE if successful, FALSE otherwise
BOOL larrayCopy(float src[], float dest[])
{
    int  i = 0, n = _array_size(src);
    if (n != _array_size(dest)) return FALSE;
    for (i = 0; i < n; ++i) dest[i] = src[i];
    return TRUE;
}   // larrayCopy(long [], long [])



// returns the maximum number in the
// parameterized array of long integers
long larrayMax(long array[])
{
    int  i   = 0,     n = _array_size(array);
    long max = MIN_LONG;
    for (i   = 0; i < n; ++i)
      if (array[i] > max) max = array[i];
    return max;
}   // farrayMax(float [])



// returns the minimum number in the
// parameterized array of long integers
long larrayMin(long array[])
{
    int  i   = 0,     n = _array_size(array);
    long min = MAX_LONG;
    for (i   = 0; i < n; ++i)
      if (array[i] < min) min = array[i];
    return min;
}   // larrayMin(long [])



// prints the parameterized array of long integers
// (with an optional label) to the screen
void larrayPrint(long array[], char label[])
{
    int  i = 0,     n = _array_size(array);
    if (label != NULL) printf("%s:\n", label);
    printf("{");
    if (n > 0) {
        printf("%l,\n", array[0]);
        for (i = 1; i < n - 1; ++i) printf(" %l,\n", array[i]);
    }
    printf(" %l}\n", array[i]);
}   // larrayPrint(long [], char [])



// sorts the parameterized array of long integers,
// returing TRUE if successful, FALSE otherwise
BOOL larraySort(long array[])
{
    int  i = 0, n = _array_size(array), done = FALSE;
    do {
        done = TRUE;
        --n;
        for (i = 0; i < n; ++i)
          if (array[i] > array[i + 1])
            if (!larraySwap(array, i, i + 1)) return FALSE;
            else done = FALSE;
    }  while (!done);
    return done;
}   // larraySort(long [])



// swaps the numbers at the parameterized indeces
// in the parameterized array of long integers,
// returing TRUE if successful, FALSE otherwise
BOOL larraySwap(long array[], int i, int j)
{
    long temp = 0L;
    if ((!isBetween(i, 0, _array_size(array) - 1)) ||
        (!isBetween(j, 0, _array_size(array) - 1)))
      return FALSE;
    temp      = array[i];
    array[i]  = array[j];
    array[j]  = temp;
    return TRUE;
}   // larraySwap(long [], int, int)

#endif
