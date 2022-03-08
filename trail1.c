#include <stdio.h>
#include <assert.h>

int readings[] = {3,3,5,4,10,11,12};

int countInContinuousRange(int lowerlimit, int upperlimit)
{
    int Count=0;
    for(int readingIterator = 0; readingIterator<= 8 ;readingIterator++)
    {
  /*  if ((readings[readingIterator]>=lowerlimit ) && (readings[readingIterator]<=upperlimit ))
    {
        Count++;
    }*/
    }
   
     return Count;
}


int main()
{
	
int low = 3;
int high = 5;
//char buff[5];
  
    int a = countInContinuousRange(low,high);
   //   printf("%d\n",a);
     //  assert((countInContinuousRange(3,5)==4)==1);
       sprintf(buff,"%d-%d,%d",low,high,a);
       printf("%s",buff);
  /*    FILE *fp;
  
    fp = fopen("Record.csv","a");
    fwrite(&buff, sizeof(buff), 1, fp);
    fclose(fp);*/
    
}
