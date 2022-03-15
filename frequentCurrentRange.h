#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct RangeAndReadings
{
  int upperLimit;
  int lowerLimit;
  int readingsCount;

} rangeAndReadings;

rangeAndReadings* findRangeAndReadings (int *readings, int length);
void swapIfInWrongOrder (int *firstElement, int *secondElement);
rangeAndReadings* findContinuousSamples (int *readings, int length);
int countInContinuousRange (int lowRange, int highRange);
void printOnConsole (rangeAndReadings* output,int numOfContinuosSamples);



