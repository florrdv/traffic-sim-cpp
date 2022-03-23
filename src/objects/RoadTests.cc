#include <gtest/gtest.h>
#include "Road.h"

TEST(RoadTests, LengthMutationHappyDay) {
    Road road = Road("example", 100.0);

    road.setLength(5);
    ASSERT_EQ(5, road.getLength());
}

TEST(RoadTests, LengthMutationZero) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.setLength(0), "strictly positive");
}

TEST(RoadTests, LengthMutationNegative) {
    Road road = Road("example", 100.0);

    EXPECT_DEATH(road.setLength(-20), "strictly positive");
}

TEST(RoadTests, NameMutationHappyDay) {
    Road road = Road("example", 100.0);

    road.setName("test");
    ASSERT_EQ("test", road.getName());
}

TEST(RoadTests, VehiclesMutationHappyDay) {
    Road road = Road("example", 100.0);

    Vehicle* v = new Vehicle(0.0);
    road.addVehicle(v);
    ASSERT_EQ(v, road.getVehicles()[0]);
}

TEST(RoadTests, GeneratorMutationHappyDay) {
    Road road = Road("example", 100.0);

    VehicleGenerator* g = new VehicleGenerator(0.0);
    road.setGenerator(g);
    ASSERT_EQ(g, road.getGenerator());
}




