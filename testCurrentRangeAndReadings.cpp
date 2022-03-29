#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include"conversion.h"


void stubPrintErrorMessage ()
{
   printf("Input is Invalid");
  // exit(EXIT_FAILURE);  -- removed this to make BUILD and RUN pass
  
}
void isActualOutputExpectedOutputsame(rangeAndReadings *expectedOutput,rangeAndReadings *actualOutput,int arrayLength)
{
	for(int i=0;i<arrayLength;i++)
	{
	REQUIRE(expectedOutput[i].upperLimit == actualOutput[i].upperLimit);
	REQUIRE(expectedOutput[i].lowerLimit == actualOutput[i].lowerLimit);
	REQUIRE(expectedOutput[i].readingsCount == actualOutput[i].readingsCount);
	}
}


/**************************************************Test Case Week1*******************************************************/


TEST_CASE("Checks the charging current range and its occurences with large unsorted samples") {                                      //SAME TEST CASE  PASSED for the model input given
	int chargingCurrentSamples[] = {3,3,5,4,10,11,12};
       rangeAndReadings expectedOutput[2] ={{5,3,4},{12,10,3}};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&printErrorMessage);
	isActualOutputExpectedOutputsame(expectedOutput,actualOutput,2);
	}
// Attempt 5: 	
TEST_CASE("Checks the charging current range for invalid Array") {                                      //SAME TEST CASE  PASSED for invalid Array
	int chargingCurrentSamples[] = {3,3,5,4,10,11,121444};
    rangeAndReadings expectedOutput[1] ={0,0,0};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&stubPrintErrorMessage);
	isActualOutputExpectedOutputsame(expectedOutput,actualOutput,1);
		}
// Attempt 6: 	
TEST_CASE("Checks the charging current range for invalid Array ie negative value") {                                      //SAME TEST CASE  PASSED for invalid Array
	int chargingCurrentSamples[] = {3,3,-5,4,10,11,4};
    rangeAndReadings expectedOutput[1] ={0,0,0};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&stubPrintErrorMessage);
	isActualOutputExpectedOutputsame(expectedOutput,actualOutput,1);
		}
		
/**************************************************Test Case Week2(Tried BDD*)*******************************************************/



SCENARIO("convert 12bit A2D Internal Values to absolute Physical values (0 - 4094)-----> (0Amps to 10Amps)")
{
    GIVEN("an array of values from 0 to 4094 ")
    {
        float arr[7] = {0,250,540,1000,1500,2500.3758,4094};
        int expectedOutput[7] = {0,1,1,2,4,6,9,10};

        WHEN("Internal value to Physical Value conversion function conversion InternalToPhysical() is called with input array, Resolution and Physical range")
        {
            int actualOutput = conversionInternalToPhysical (arr,7,12,0,10,&printErrorMessage);
            THEN("The Physical value array is returned for the given internal array input ")
            {
                for(int i=0;i<arrayLength;i++)
	            {
		      REQUIRE(expectedOutput[i] == actualOutput[i];
		    }
            }
        }
    }
}

SCENARIO("convert 10bit A2D Internal Values to absolute Physical values (0 - 1022)-----> (-15Amps to 15Amps)")
{
    GIVEN("an array of values from 0 to 1022 ")
    {
        float arr[7] = {0,250,540,1000,750,1022,900};
        int expectedOutput[7] = {15,8,1,14,4,7,15,11};

        WHEN("Internal value to Physical Value conversion function conversion InternalToPhysical() is called with input array, Resolution and Physical range")
        {
            int actualOutput = conversionInternalToPhysical (arr,7,10,-15,15,&printErrorMessage);
            THEN("The Physical value array is returned for the given internal array input ")
            {                
	          for(int i=0;i<arrayLength;i++)
	            {
		      REQUIRE(expectedOutput[i] == actualOutput[i];
		    }
            }
        }
    }
}

SCENARIO("Checks the charging current range and its occurences with given raw  internal values")
{
    GIVEN("an array of raw values from 0 to 4094 ")
    {
        float arr[7] = {0,250,540,1000,1500,2500.3758,4094};
        rangeAndReadings expectedOutput[4] = {{0,2,4},{4,4,1},{6,6,1},{9,10,2}};
        WHEN("calculate range and readings function convertAndCollectRangs() is called with raw value input array, Resolution and Physical range")
        {
           rangeAndReadings *actualOutput = convertAndCollectRangs (arr,7,10,-15,15,&validateArray,&printOnConsole,&printErrorMessage);
            THEN("The Physical range and readings are returned for the given internal array input ")
            {
                isActualOutputExpectedOutputsame(expectedOutput,actualOutput,4);
            }
        }
    }
}
