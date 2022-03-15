#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include"frequentCurrentRange.h"

int checkRangeAndReadings(int *readings,int length);
// Attempt 1. 
/* TEST_CASE("Checks the charging current range and its occurences with small samples") {                                      //FAILED
	int chargingCurrentSamples[] = {4,5};
	int expectedNumOfRange = 1;
	int actualNumOfRange = checkRangeAndReadings(chargingCurrentSamples,2);
	REQUIRE(expectedNumOfRange == actualNumOfRange);
} */ //The above test failed because the actualNumOfRange is not properly incremented

// Attempt 2. 
TEST_CASE("Checks the charging current range and its occurences with small samples") {                                      //SAME TEST CASE 
	int chargingCurrentSamples[] = {4,5};
        rangeAndReadings expectedOutput[1] ={4,5,2};
	rangeAndReadings *actualOutput = findRangeAndReadings (chargingCurrentSamples,2);
	REQUIRE(expectedOutput[0].upperLimit == actualOutput[0].upperLimit);
	REQUIRE(expectedOutput[0].lowerLimit == actualOutput[.].lowerLimit);
	REQUIRE(expectedOutput[0].readingsCount == actualOutput[0].readingsCount);
	}
