#include"conversion.h"

int calculateInternalMax (int A2D_resolution)
{
  return (pow (2, A2D_resolution) - 2);
}

float calculateResolution (float PhyMin, float PhyMax, float InternalMax)
{
  float PhyRange = PhyMax + (abs (PhyMin));
  return (PhyRange / InternalMax);
}

float executeConversion (int RawValue, compu_formula * coEfficients)
{
  float PhyValue = (coEfficients->resolution * RawValue + coEfficients->offset);
  return PhyValue;
}

float calculateRoundoffValue (float phyValue)
{
     float roundedValue = round(phyValue);     
     return roundedValue;
}

int calculateAbsoluteValue (float roundedPhyValue)
{
   int absValue = (int)abs(roundedPhyValue);
   return absValue;
}


int *conversionInternalToPhysical (float *rawValues,int arraysize, int A2D_resolution,float PhyMin, float PhyMax,void(*fpPrintErrorMessage)(void))
{

  compu_formula* compu_coEfficients = (compu_formula *) calloc (1, sizeof (compu_formula));
  float* phyValue =  (float *) calloc (arraysize, sizeof (float));
  float* roundedPhyValue =  (float *) calloc (arraysize, sizeof (float));
  int* absValue =  (int *) calloc (arraysize, sizeof (int));
  int InternalMax = calculateInternalMax (A2D_resolution);
  
  compu_coEfficients->offset = PhyMin;
  compu_coEfficients->resolution = calculateResolution(PhyMin, PhyMax, InternalMax);
  for (int i = 0; i < arraysize; i++)
    {
		if (rawValues[i]<=InternalMax)
		{
			phyValue[i] = executeConversion(rawValues[i], compu_coEfficients);
	     	roundedPhyValue[i] = calculateRoundoffValue(phyValue[i]);
            absValue[i] = calculateAbsoluteValue(roundedPhyValue[i]);
		}
	    else
			fpPrintErrorMessage();
    }

      
   return absValue;
}
 
rangeAndReadings* convertAndCollectRangs(float *rawValues,int arraysize,int A2D_resolution,float PhyMin, float PhyMax,void(*fpPrintOnConsole)(rangeAndReadings*,int) , void(*fpPrintErrorMessage)(void))
	{
		int * currentRange = conversionInternalToPhysical (rawValues, arraysize,  A2D_resolution, PhyMin, PhyMax,fpPrintErrorMessage);
		return (findRangeAndReadings (currentRange ,arraysize,fpValidateArray,fpPrintOnConsole,fpPrintErrorMessage) ; );
	}
