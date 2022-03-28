#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct computation_formula
{
  float resolution;
  float offset;
} compu_formula;

int calculateInternalMax (int A2D_resolution);
float calculateResolution (float PhyMin, float PhyMax, float InternalMax);
float executeConversion (int RawValue, compu_formula * coEfficients);
float calculateRoundoffValue (float phyValue);
int createAbsoluteArray (float roundedPhyValue);
int *conversionInternalToPhysical (float *rawValues,int arraysize, int A2D_resolution,float PhyMin, float PhyMax,void(*fpPrintErrorMessage)(void));
