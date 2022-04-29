#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.h"
#include "../lib/TestingHelpers.h"
#include "../objects/Crossroad.h"
#include "../objects/Road.h"
#include "../lib/DesignByContract.h"

TEST(CrossroadTests, PositionMutationHappyDay) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    Crossroad crossroad = Crossroad(CrossroadDetails(road1, 10), CrossroadDetails(road2, 5));

    //TODO: Figure out what to test
}
