int countInContinuousRange(int lowRange,int highRange)

{
    return highRange-lowRange;
}
int findContinuousSamples(int *readings,int length)
{
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
		   	   
        }
           
    }
	return numOfContinuosSamples;
}

int checkRangeAndReadings(int *readings,int length)
{   int numOfContinuosSamples =0;
    numOfContinuosSamples=  findContinuousSamples(readings, length);
    return numOfContinuosSamples;
}

