#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.h"
#include "../lib/TestingHelpers.h"
#include "../objects/Crossroad.h"
#include "../objects/Road.h"
#include "../lib/DesignByContract.h"

TEST(CrossroadTests, CrossroadGenerationHappyDay) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_EXIT({Crossroad(new CrossroadDetails { road1, 10 }, new CrossroadDetails { road2, 5 }); fprintf(stderr, "Done"); exit(0);},
                ::testing::ExitedWithCode(0), "Done");
}

TEST(CrossroadTests, CrossroadGenerationNegativePosition1) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, -10 }, new CrossroadDetails { road2, 5 }), "Position must be positive");
}

TEST(CrossroadTests, CrossroadGenerationNegativePosition2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, 10 }, new CrossroadDetails { road2, -20 }), "Position must be positive");
}

TEST(CrossroadTests, CrossroadGenerationInvalidPosition1) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, 110 }, new CrossroadDetails { road2, 5 }), "Position must be within road bounds");
}

TEST(CrossroadTests, CrossroadGenerationInvalidPosition2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, 10 }, new CrossroadDetails { road2, 90 }), "Position must be within road bounds");
}

TEST(CrossroadTests, CrossroadGenerationInvalidRoad1) {
    Road *road1 = nullptr;
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, 10 }, new CrossroadDetails { road2, 5 }), "Road can not be nullptr");
}

TEST(CrossroadTests, CrossroadGenerationInvalidRoad2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = nullptr;
    EXPECT_DEATH(Crossroad(new CrossroadDetails { road1, 10 }, new CrossroadDetails { road2, 5 }), "Road can not be nullptr");
}