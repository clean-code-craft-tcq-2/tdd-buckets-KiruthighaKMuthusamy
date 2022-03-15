#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include"frequentCurrentRange.h"


// Attempt 1. 
/* TEST_CASE("Checks the charging current range and its occurences with small samples") {                                      //FAILED
	int chargingCurrentSamples[] = {4,5};
	int expectedNumOfRange = 1;
	int actualNumOfRange = checkRangeAndReadings(chargingCurrentSamples,2);
	REQUIRE(expectedNumOfRange == actualNumOfRange);
} */ //The above test failed because the actualNumOfRange is not properly incremented

// Attempt 2. 
TEST_CASE("Checks the charging current range and its occurences with small  samples") {                                      //SAME TEST CASE  PASSED
	int chargingCurrentSamples[] = {4,5};
        rangeAndReadings expectedOutput[1] ={5,4,2};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,2,&validateArray,&printOnConsole,&printErrorMessage);
	REQUIRE(expectedOutput[0].upperLimit == actualOutput[0].upperLimit);
	REQUIRE(expectedOutput[0].lowerLimit == actualOutput[0].lowerLimit);
	REQUIRE(expectedOutput[0].readingsCount == actualOutput[0].readingsCount);
	}

TEST_CASE("Checks the charging current range and its occurences with large sorted samples") {                                      //SAME TEST CASE  PASSED for the model input given
	int chargingCurrentSamples[] = {3,3,4,5,10,11,12};
        rangeAndReadings expectedOutput[2] ={{3,5,2},{10,12}};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&printErrorMessage);
	REQUIRE(expectedOutput[0].upperLimit == actualOutput[0].upperLimit);
	REQUIRE(expectedOutput[0].lowerLimit == actualOutput[0].lowerLimit);
	REQUIRE(expectedOutput[0].readingsCount == actualOutput[0].readingsCount);
	REQUIRE(expectedOutput[1].upperLimit == actualOutput[1].upperLimit);
	REQUIRE(expectedOutput[1].lowerLimit == actualOutput[1].lowerLimit);
	REQUIRE(expectedOutput[1].readingsCount == actualOutput[1].readingsCount);
	}
	
	
TEST_CASE("Checks the charging current range and its occurences with large unsorted samples") {                                      //SAME TEST CASE  PASSED for the model input given
	int chargingCurrentSamples[] = {3,3,5,4,10,11,12};
        rangeAndReadings expectedOutput[2] ={{3,5,2},{10,12}};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&printErrorMessage);
	REQUIRE(expectedOutput[0].upperLimit == actualOutput[0].upperLimit);
	REQUIRE(expectedOutput[0].lowerLimit == actualOutput[0].lowerLimit);
	REQUIRE(expectedOutput[0].readingsCount == actualOutput[0].readingsCount);
	REQUIRE(expectedOutput[1].upperLimit == actualOutput[1].upperLimit);
	REQUIRE(expectedOutput[1].lowerLimit == actualOutput[1].lowerLimit);
	REQUIRE(expectedOutput[1].readingsCount == actualOutput[1].readingsCount);
	}
	
	TEST_CASE("Checks the charging current range for invalid Array") {                                      //SAME TEST CASE  PASSED for invalid Array
	int chargingCurrentSamples[] = {3,3,5,4,10,11,121444};
    rangeAndReadings expectedOutput[1] ={{(int)"/0",(int)"/0",(int)"/0"}};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,7,&validateArray,&printOnConsole,&printErrorMessage);
	REQUIRE(expectedOutput[0].upperLimit == actualOutput[0].upperLimit);
	REQUIRE(expectedOutput[0].lowerLimit == actualOutput[0].lowerLimit);
	REQUIRE(expectedOutput[0].readingsCount == actualOutput[0].readingsCount);
		}
