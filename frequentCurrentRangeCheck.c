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
rangeAndReadings* findContinuousSamples (int *readings, int length, void(*fpPrintOnConsole)(rangeAndReadings*,int))
{
  rangeAndReadings *rangeAndNoOfReadings =
    (rangeAndReadings *) calloc (10, sizeof (rangeAndReadings));

  int  numOfContinuosSamples = 0;

  
  for (int i = 0; i < length-1 ; i++)
    {
      if (readings[i+1] - readings[i] <= 1)
	{
	 
	  rangeAndNoOfReadings [numOfContinuosSamples].upperLimit = readings[i+1] ;
	  rangeAndNoOfReadings [numOfContinuosSamples].readingsCount++;

	}
      else
	{
	    
	          numOfContinuosSamples++;
	          rangeAndNoOfReadings [numOfContinuosSamples].readingsCount++;
		  rangeAndNoOfReadings [numOfContinuosSamples].lowerLimit = readings[i+1] ;
		  rangeAndNoOfReadings [numOfContinuosSamples].upperLimit = readings[i+1] ;
	 
	}

    }
    fpPrintOnConsole (rangeAndNoOfReadings ,numOfContinuosSamples);
  return rangeAndNoOfReadings;
}

rangeAndReadings* findRangeAndReadings (int *readings, int length,bool(*fpValidateArray)(int* ,int ),void(*fpPrintOnConsole)(rangeAndReadings*,int) , void(*fpPrintErrorMessage)(void))
{
    rangeAndReadings* numOfContinuosSamples ;
    bool validation = fpValidateArray(readings,length);
  if(validation ==true)  
  {
   int* duplicateArray = copyInputArray(readings,  length);
  sortInputArray(duplicateArray, length);
   numOfContinuosSamples = findContinuousSamples (duplicateArray, length,fpPrintOnConsole);
  return numOfContinuosSamples;
  }
  else
  {
      fpPrintErrorMessage();
	    rangeAndReadings *nullOutput =
    (rangeAndReadings *) calloc (1, sizeof (rangeAndReadings));
      nullOutput[0].upperLimit = 0;
      nullOutput[0].lowerLimit =  0;
      nullOutput[0].readingsCount = 0;
	  return nullOutput;
  }
	  
   
}
