#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int checkRangeAndReadings(int *readings,int length);
void arraySort(int *readings,size_t length);
void swapIfInWrongOrder (int *firstElement,int *secondElement);
int findContinuousSamples(int *readings,size_t length);
int countInContinuousRange(int lowRange,int highRange);
void printOnConsole(int readingslowRange,int readingshighRange,int count);

