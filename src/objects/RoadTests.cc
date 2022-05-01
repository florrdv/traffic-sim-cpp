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
    Vehicle *vehicle = new Vehicle(0.0, VehicleType::Personal);
    road.addVehicle(vehicle);
    ASSERT_EQ(vehicle, road.getVehicles()[0]);
}

TEST(RoadTests, VehiclesMutationInvalidPosition) {
    Road road = Road("example", 100.0);
    ASSERT(road.getVehicles().empty(), "there should be no vehicles on the road yet");
    Vehicle *vehicle = new Vehicle(200.0, VehicleType::Personal);
    EXPECT_DEATH(road.addVehicle(vehicle), "Road not long enough for");
}

TEST(RoadTests, GeneratorMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT(road.getGenerator() == nullptr, "there should be no generator on the road yet");
    VehicleGenerator *generator = new VehicleGenerator(0.0, VehicleType::Personal);
    road.setGenerator(generator);
    ASSERT_EQ(generator, road.getGenerator());
}

TEST(RoadTests, GeneratorMutationInvalidPosition) {
    Road road = Road("example", 100.0);
    ASSERT(road.getGenerator() == nullptr, "there should be no generator on the road yet");
    VehicleGenerator *generator = new VehicleGenerator(200.0, VehicleType::Personal);
    EXPECT_DEATH(road.setGenerator(generator), "Road not long enough for");
}

TEST(RoadTests, BusStopMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT(road.getBusStops().size() == 0, "there should be no bus stops on the road yet");
    BusStop *busStop = new BusStop(10, VehicleType::Personal);
    road.addBusStop(busStop);

    ASSERT_EQ(road.getBusStops().size(), 1);
    ASSERT_EQ(road.getBusStops()[0], busStop);
}

TEST(RoadTests, BusStopMutationInvalidPosition) {
    Road road = Road("example", 100.0);
    ASSERT(road.getBusStops().size() == 0, "there should be no bus stops on the road yet");
    BusStop *busStop = new BusStop(10, VehicleType::Personal);
    EXPECT_DEATH(road.addBusStop(busStop), "Road not long enough for");
}

TEST(RoadTests, TickTrafficLightsHappyDay) {
    Road road = Road("example", 100.0);
    int cycle = 10;
    TrafficLight* light = new TrafficLight(20.0, cycle);


    road.addTrafficLight(light);

    bool beforeTicks = light->isGreen();

    light->setCycleCount(ceil(cycle/gSimTime));
    road.tickTrafficLights();

    EXPECT_NE(beforeTicks, light->isGreen());
}

TEST(RoadTests, TickVehicleGeneratorsHappyDay) {
    int frequency = 10;

    Road road = Road("example", 100.0);
    VehicleGenerator* generator = new VehicleGenerator(frequency, VehicleType::Personal);
    road.setGenerator(generator);

    unsigned int expectedAfterTick = road.getVehicles().size();

    generator->setFrequencyCount(ceil(frequency/gSimTime));
    road.tickVehicleGenerators();

    EXPECT_EQ(expectedAfterTick, road.getVehicles().size() - 1);
}

