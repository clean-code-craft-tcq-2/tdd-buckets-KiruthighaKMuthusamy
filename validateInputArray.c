#include"frequentCurrentRange.h"

bool validateArray(int *readings,int length)
{
     for (int iterator = 0; iterator < length; iterator++)
    {
       if (!((readings[iterator] >=0 ) &&  (readings[iterator] <= 65535))) // This check whether the input is within uint16 and not a NULL 
       { 
           return false;
           
       }
        
    }
    
    return true;
}
