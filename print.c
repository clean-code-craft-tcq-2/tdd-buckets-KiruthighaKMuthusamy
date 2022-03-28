#include"frequentCurrentRange.h"

void printOnConsole (rangeAndReadings* input,int numOfContinuosSamples)
			 
{
    for (int i = 0; i <= numOfContinuosSamples; i++)
    {
  char buff[17];
  sprintf (buff, "%d-%d,%d\n", input[i].lowerLimit, input[i].upperLimit, input[i].readingsCount);
  printf ("%s", buff);
    }
}
void printErrorMessage ()
{
   printf("Input is Invalid");
  exit(EXIT_FAILURE);
  
}

