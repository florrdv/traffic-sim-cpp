#include <gtest/gtest.h>
#include "Road.h"

TEST(RoadTests, LengthMutationHappyDay) {
    Road road = Road();

    road.setLength(5);
    ASSERT_EQ(5, road.getLength());
}

TEST(RoadTests, LengthMutationZero) {
    Road road = Road();
    EXPECT_DEATH(road.setLength(0), "strictly positive");
}

TEST(RoadTests, LengthMutationNegative) {
    Road road = Road();

    EXPECT_DEATH(road.setLength(-20), "strictly positive");
}

TEST(RoadTests, NameMutationHappyDay) {
    Road road = Road();

    road.setName("test");
    ASSERT_EQ("test", road.getName());
}

TEST(RoadTests, VehiclesMutationHappyDay) {
    Road road = Road();

    Vehicle* v = new Vehicle();
    road.addVehicle(v);
    ASSERT_EQ(v, road.getVehicles()[0]);
}

TEST(RoadTests, GeneratorMutationHappyDay) {
    Road road = Road();

    VehicleGenerator* g = new VehicleGenerator();
    road.setGenerator(g);
    ASSERT_EQ(g, road.getGenerator());
}




