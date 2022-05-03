/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#include <cmath>
#include <gtest/gtest.h>
#include "Road.h"

TEST(RoadTests, RoadGenerationHappyDay) {
    EXPECT_EXIT({Road("example", 100.0); fprintf(stderr, "Done"); exit(0);},
                ::testing::ExitedWithCode(0), "Done");
}

TEST(RoadTests, RoadGenerationZeroLength) {
    EXPECT_DEATH(Road("example", 0), "Road length must be strictly positive");
}

TEST(RoadTests, RoadGenerationNegativeLength) {
    EXPECT_DEATH(Road("example", -10), "Road length must be strictly positive");
}

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

TEST(RoadTests, VehicleMutationInvalid) {
    Road road = Road("example", 100.0);
    Vehicle* vehicle = nullptr;

    EXPECT_DEATH(road.addVehicle(vehicle), "Cannot add empty vehicle to road");
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
    VehicleGenerator *generator = new VehicleGenerator(20.0, VehicleType::Personal);
    road.setGenerator(generator);
    ASSERT_EQ(generator, road.getGenerator());
}

TEST(RoadTests, BusStopMutationHappyDay) {
    Road road = Road("example", 100.0);
    ASSERT(road.getBusStops().size() == 0, "there should be no bus stops on the road yet");
    BusStop *busStop = new BusStop(10, VehicleType::Personal);
    road.addBusStop(busStop);

    ASSERT_EQ(road.getBusStops().size(), 1);
    ASSERT_EQ(road.getBusStops()[0], busStop);
}

TEST(RoadTests, BusStopMutationInvalid) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.addBusStop(nullptr), "Bus stop cannot be nullptr");
}

TEST(RoadTests, BusStopMutationInvalidPosition) {
    Road road = Road("example", 100.0);
    ASSERT(road.getBusStops().size() == 0, "there should be no bus stops on the road yet");
    BusStop *busStop = new BusStop(200, VehicleType::Personal);
    EXPECT_DEATH(road.addBusStop(busStop), "Road not long enough for");
}

TEST(RoadTests, VehicleGeneratorMutationHappyDay) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.addBusStop(nullptr), "Bus stop cannot be nullptr");
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