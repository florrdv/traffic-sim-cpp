#include <cmath>
#include <gtest/gtest.h>
#include "Road.h"

TEST(RoadTests, LengthMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT_EQ(100.0, road.getLength());
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
    ASSERT_EQ(100.0, road.getLength());
    road.setName("test");
    ASSERT_EQ("test", road.getName());
}

TEST(RoadTests, VehiclesMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT(road.getVehicles().empty(), "there should be no vehicles on the road yet");
    Vehicle *v = new Vehicle(0.0, VehicleType::Personal);
    road.addVehicle(v);
    ASSERT_EQ(v, road.getVehicles()[0]);
}

TEST(RoadTests, GeneratorMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT(road.getGenerator() == nullptr, "there should be no generator on the road yet");
    VehicleGenerator *g = new VehicleGenerator(0.0, VehicleType::Personal);
    road.setGenerator(g);
    ASSERT_EQ(g, road.getGenerator());
}

TEST(RoadTests, TickTrafficLightsHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    sim.addRoad(road);
    int cycle = 10;
    TrafficLight* light = new TrafficLight(20.0, cycle);


    road->addTrafficLight(light);

    bool beforeTicks = light->isGreen();

    light->setCycleCount(ceil(cycle/gSimTime));
    sim.tickTrafficLights(road);

    EXPECT_NE(beforeTicks, light->isGreen());
}

TEST(RoadTests, TickTrafficLightsUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    TrafficLight* light = new TrafficLight(20.0, 20);
    road->addTrafficLight(light);

    EXPECT_DEATH(sim.tickTrafficLights(road), "not part of the simulation");

    delete road;
}

TEST(RoadTests, TickVehicleGeneratorsHappyDay) {
    int frequency = 10;

    Road road = Road("example", 100.0);
    VehicleGenerator* generator = new VehicleGenerator(frequency, VehicleType::Personal);
    road.setGenerator(generator);

    int expectedAfterTick = road.getVehicles().size();

    generator->setFrequencyCount(ceil(frequency/gSimTime));
    road.tickVehicleGenerators();

    EXPECT_EQ(expectedAfterTick, road.getVehicles().size() - 1);
}

