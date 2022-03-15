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

rangeAndReadings* checkRangeAndReadings (int *readings, int length,bool(*fpValidateArray)(int* ,int ),void(*fpPrintOnConsole)(rangeAndReadings*,int) , void(*fpPrintErrorMessage)(void))
bool validateArray(int *readings,int length);
int * copyInputArray(int *readings, int length);
void sortInputArray (int *duplicateArray, int length);
void swapIfInWrongOrder (int *firstElement, int *secondElement);
rangeAndReadings* findContinuousSamples (int *readings, int length, void(*fpPrintOnConsole)(rangeAndReadings*,int));
void storeCalculatedRageReadings(int upperReadings,int lowerReadings,int readingsCount,int numOfContinuosSamples, rangeAndReadings *output);
int countInContinuousRange (int lowRange, int highRange);
void printOnConsole (rangeAndReadings* output,int numOfContinuosSamples);
void printErrorMessage ();


