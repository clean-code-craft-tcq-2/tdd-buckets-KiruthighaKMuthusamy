#include"frequentCurrentRange.h"

void printOnConsole (rangeAndReadings* rangeAndNoOfReadings,int numOfContinuosSamples)
{
  char buff[17];
  sprintf (buff, "%d-%d,%d\n", rangeAndNoOfReadings[numOfContinuosSamples].lowerLimit, rangeAndNoOfReadings[numOfContinuosSamples].upperLimit, rangeAndNoOfReadings[numOfContinuosSamples].readingsCount);
 printf ("%s", buff);
}

void printErrorMessage ()
{
   fprintf(stderr, "Input is Invalid");
   exit(EXIT_FAILURE);
  
}
