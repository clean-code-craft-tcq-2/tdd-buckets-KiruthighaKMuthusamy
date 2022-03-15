#include"frequentCurrentRange.h"

int countInContinuousRange (int lowRange, int highRange)
{
  return highRange - lowRange + 1;
}


void storeCalculatedRageReadings(int upperReadings,int lowerReadings,int readingsCount,int numOfContinuosSamples, rangeAndReadings *output)
{
   	  output[numOfContinuosSamples].upperLimit = upperReadings;
	  output[numOfContinuosSamples].lowerLimit = lowerReadings;
	  output[numOfContinuosSamples].readingsCount = readingsCount;
	  
}


rangeAndReadings* findContinuousSamples (int *readings, int length)
{
  rangeAndReadings *output =
    (rangeAndReadings *) calloc (10, sizeof (rangeAndReadings));

  int lowRange = 0, highRange = 0, readingsCount = 0, numOfContinuosSamples =
    0;

  for (int i = 1; i < length; i++)
    {
      if (readings[i] - readings[i - 1] > 1)
	{
	  highRange = i - 1;
	  readingsCount = countInContinuousRange (lowRange, highRange);
	  storeCalculatedRageReadings(readings[highRange],readings[lowRange],readingsCount,numOfContinuosSamples,output);
      printOnConsole (output,numOfContinuosSamples); 
	  numOfContinuosSamples++;
	  highRange = i;
	  lowRange = i;
	}
      else if (i == length - 1)
	{
	  highRange = i;
	  readingsCount = countInContinuousRange (lowRange, highRange);
          storeCalculatedRageReadings(readings[highRange],readings[lowRange],readingsCount,numOfContinuosSamples,output);
	  printOnConsole (output,numOfContinuosSamples);
	  numOfContinuosSamples++;
	}


    }
  return output;
}

rangeAndReadings* findRangeAndReadings (int *readings, int length)
{
    rangeAndReadings* numOfContinuosSamples = 0;
  numOfContinuosSamples = findContinuousSamples (readings, length);
  return numOfContinuosSamples;
  
   
}
