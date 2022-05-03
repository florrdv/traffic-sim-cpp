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
    EXPECT_EXIT({
                    Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 5});
                    fprintf(stderr, "Done");
                    exit(0);
                },
                ::testing::ExitedWithCode(0), "Done");
}

TEST(CrossroadTests, CrossroadGenerationInvalidDetails1) {
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(new Crossroad(nullptr, new CrossroadDetails{road2, 5}), "Crossroad can not be nullptr");
}

TEST(CrossroadTests, CrossroadGenerationInvalidDetails2) {
    Road *road1 = new Road("foo", 100);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 20}, nullptr), "Crossroad can not be nullptr");
}

TEST(CrossroadTests, CrossroadGenerationNegativePosition1) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, -10}, new CrossroadDetails{road2, 5}),
                 "Position must be positive");
}

TEST(CrossroadTests, CrossroadGenerationNegativePosition2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, -20}),
                 "Position must be positive");
}

TEST(CrossroadTests, CrossroadGenerationInvalidPosition1) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 110}, new CrossroadDetails{road2, 5}),
                 "Position must be within road bounds");
}

TEST(CrossroadTests, CrossroadGenerationInvalidPosition2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 90}),
                 "Position must be within road bounds");
}

TEST(CrossroadTests, CrossroadGenerationInvalidRoad1) {
    Road *road1 = nullptr;
    Road *road2 = new Road("bar", 80);
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 5}), "Road can not be nullptr");
}

TEST(CrossroadTests, CrossroadGenerationInvalidRoad2) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = nullptr;
    EXPECT_DEATH(Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 5}), "Road can not be nullptr");
}

TEST(CrossroadTests, CrossroadGetPositionForRoadHappyDay) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);

    Crossroad *crossroad = new Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 5});

    EXPECT_EQ(10, crossroad->getPositionForRoad(road1));
    EXPECT_EQ(5, crossroad->getPositionForRoad(road2));
}

TEST(CrossroadTests, CrossroadDetailsGetter) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);

    CrossroadDetails *detail1 = new CrossroadDetails{road1, 10};
    CrossroadDetails *detail2 = new CrossroadDetails{road2, 5};

    Crossroad *crossroad = new Crossroad({detail1, detail2});

    std::pair<CrossroadDetails *, CrossroadDetails *> fetchedDetails = crossroad->getDetails();

    EXPECT_EQ(fetchedDetails.first, detail1);
    EXPECT_EQ(fetchedDetails.second, detail2);
}

TEST(CrossroadTests, CrossroadClone) {
    Road *road1 = new Road("foo", 100);
    Road *road2 = new Road("bar", 80);

    Crossroad *crossroad = new Crossroad(new CrossroadDetails{road1, 10}, new CrossroadDetails{road2, 5});
    Crossroad *clone = crossroad->clone();

    EXPECT_EQ(clone->getDetails().first->road->getName(), crossroad->getDetails().first->road->getName());
    EXPECT_EQ(clone->getDetails().second->road->getName(), crossroad->getDetails().second->road->getName());

    EXPECT_EQ(clone->getDetails().first->position, crossroad->getDetails().first->position);
    EXPECT_EQ(clone->getDetails().second->position, crossroad->getDetails().second->position);
}