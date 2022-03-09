struct RangeAndReadings
{
     int LowerSample;
     int UpperSample;
     int RangeCount
};

int countInContinuousRange(int lowRange,int highRange)

{
    return highRange-lowRange;
}
RangeAndReadings* findContinuousSamples(int *readings,int length)
{   struct RangeAndReadings currentRangeReadings[15];
    int lowRange = 0;
    int highRange = 0;
    int readingsCount = 0;
    int numOfContinuosSamples = 0;
	
    for (int i=1;i<length;i++)
    { 
	 if(i==length-1)
        {     
		   highRange = i;
	         readingsCount = countInContinuousRange(lowRange,highRange);
		 numOfContinuosSamples++;
		 currentRangeReadings[numOfContinuosSamples].LowerSample = readingsCount[lowRange];
		 currentRangeReadings[numOfContinuosSamples].UpperSample = readingsCount[highRange];
		 currentRangeReadings[numOfContinuosSamples].RangeCount = readingsCount;
        }
           
    }
	return currentRangeReadings;
}

RangeAndReadings* checkRangeAndReadings(int *readings,int length)
{  
   return(  findContinuousSamples(readings, length));
    
}

