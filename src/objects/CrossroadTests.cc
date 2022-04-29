#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.h"
#include "../lib/TestingHelpers.h"
#include "../objects/Crossroad.h"
#include "../lib/DesignByContract.h"

TEST(CrossroadTests, PositionMutationHappyDay) {
    Crossroad crossroad = Crossroad(0.0, 10);
    EXPECT_EQ(0, busStop.getPosition());
    busStop.setPosition(20);
    EXPECT_EQ(20, busStop.getPosition());
}
