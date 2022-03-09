#include"frequentCurrentRange.h"

void swapIfInWrongOrder (int *firstElement,int *secondElement)
{	 
    if(*firstElement > *secondElement)
            {
    int temp = 0;
	 temp = *firstElement;
     *firstElement = *secondElement;
     *secondElement = temp;
            }
}


void arraySort(int *readings,int length)
{ 
    for (int majorIndex = 0; majorIndex<length; majorIndex++)
    {
        for (int minorIndex = majorIndex+1; minorIndex<=length-1; minorIndex++)
        {
			swapIfInWrongOrder(&readings[majorIndex], &readings[minorIndex]);
			
        }
    }
}
