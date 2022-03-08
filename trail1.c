#include <stdio.h>
#include <assert.h>

int readings[] = {3,3,5,4,10,11,12};
_Bool checkLowerLimit(int lowerlimit,int readings)
{
    if (readings>=lowerlimit)
    return 1;
    else 
    return 0;

}
_Bool checkUpperLimit(int upperlimit,int readings)
{
    if(readings<=upperlimit)
    return 1;
    else 
    return 0;
}
int checkWithinRange(_Bool Lowerresult,_Bool Upperresult)
{
    if (Lowerresult && Upperresult)
    return(1);
    else
    return(0);
}

int countInContinuousRange(int lowerlimit, int upperlimit)
{
    int Count=0;
    for(int readingIterator = 0; readingIterator<= 8 ;readingIterator++)
    {
       _Bool Lowerresult = checkLowerLimit(lowerlimit,readings[readingIterator]);
    _Bool   Upperresult =  checkUpperLimit(upperlimit,readings[readingIterator]);
     Count +=  checkWithinRange(Lowerresult,Upperresult);
    }
   
     return Count;
}


int main()
{
	
int low = 3;
int high = 5;
char buff[5];
     assert((countInContinuousRange(3,5)==4)==1);
    int a = countInContinuousRange(low,high);
       sprintf(buff,"%d-%d,%d",low,high,a);
       printf("%s",buff);

    
}
