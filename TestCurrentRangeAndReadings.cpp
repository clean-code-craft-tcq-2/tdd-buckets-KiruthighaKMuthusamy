#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"

int checkRangeAndReadings(int *readings,int length);

TEST_CASE("Checks the charging current range and its occurences with small samples") {
	int chargingCurrentSamples[] = {4,5};
	int expectedNumOfRange = 1;
	int actualNumOfRange = checkRangeAndReadings(chargingCurrentSamples,2);
	REQUIRE(expectedNumOfRange == actualNumOfRange);
}
