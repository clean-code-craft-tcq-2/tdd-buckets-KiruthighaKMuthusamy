#include"frequentCurrentRange.h"

void printOnConsole (rangeAndReadings* output,int numOfContinuosSamples)
{
  char buff[17];
  sprintf (buff, "%d-%d,%d\n", output[numOfContinuosSamples].lowerLimit, output[numOfContinuosSamples].upperLimit, output[numOfContinuosSamples].readingsCount);
 printf ("%s", buff);
}

