#include"frequentCurrentRange.h"

int * copyInputArray(int *readings, int length)
{
  int* duplicateArray=(int *)calloc(length, sizeof (int));
  for (int iterator = 0; iterator < length; iterator++)
    {
        duplicateArray[iterator] = readings[iterator];
        
    }
    return duplicateArray;
}


void swapIfInWrongOrder (int *firstElement, int *secondElement)
{
  if (*firstElement > *secondElement)
    {
      int temp = 0;
      temp = *firstElement;
      *firstElement = *secondElement;
      *secondElement = temp;
    }
}



void arraySort (int *duplicateArray, int length)
{
    for (int majorIndex = 0; majorIndex < length; majorIndex++)
    {
      for (int minorIndex = majorIndex + 1; minorIndex <= length - 1;
	   minorIndex++)
	{
	  swapIfInWrongOrder (&duplicateArray[majorIndex], &duplicateArray[minorIndex]);

	}
    }
     
    
}