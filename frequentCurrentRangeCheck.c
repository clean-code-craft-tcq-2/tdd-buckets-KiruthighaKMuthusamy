#include"frequentCurrentRange.h"

void printOnConsole(int readingslowRange,int readingshighRange,int count)
{      char buff[17];
       sprintf(buff,"%d-%d,%d\n",readingslowRange,readingshighRange,count);
       printf("%s",buff);
}
int countInContinuousRange(int lowRange,int highRange)

{
    return highRange-lowRange+1;
}
int findContinuousSamples(int *readings,size_t length)
{
    int lowRange = 0;
    int highRange = 0;
    int readingsCount = 0;
    int numOfContinuosSamples = 0;
	
    for (int i=1;i<length;i++)
    { 
		if( readings[i] - readings[i-1] > 1 )
        {   
		 highRange =i-1;         		
		 readingsCount = countInContinuousRange(lowRange,highRange);
		 printOnConsole(readings[lowRange],readings[highRange],readingsCount);
		 highRange = i;
                  lowRange = i;
		 numOfContinuosSamples++;
          
        }
        else if(i==length-1)
        {     
		   highRange = i;
	           readingsCount = countInContinuousRange(lowRange,highRange);
		   printOnConsole(readings[lowRange],readings[highRange],readingsCount);
		   numOfContinuosSamples++;
        }
           
    }
	return numOfContinuosSamples;
}

int checkRangeAndReadings(int *readings,int length)
{   int numOfContinuosSamples =0;
    arraySort(readings, length);
    numOfContinuosSamples=  findContinuousSamples(readings, length);
    return numOfContinuosSamples;
}

