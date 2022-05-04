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
#include "TrafficLight.h"
#include "../lib/NullBuffer.h"

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
    BusStop *busStop = new BusStop(10, 10);
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
    BusStop *busStop = new BusStop(200, 10);
    EXPECT_DEATH(road.addBusStop(busStop), "Road not long enough for");
}

TEST(RoadTests, VehicleGeneratorMutationHappyDay) {
    Road road = Road("example", 100.0);
    VehicleGenerator* generator = new VehicleGenerator(10, VehicleType::Personal);
    EXPECT_EQ(nullptr, road.getGenerator());

    road.setGenerator(generator);
    EXPECT_EQ(generator, road.getGenerator());
}

TEST(RoadTests, VehicleGeneratorMutationInvalid) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.setGenerator(nullptr), "Cannot add empty generator to road");
}

TEST(RoadTests, CrossroadMutationHappyDay) {
    Road* road1 = new Road("john", 100.0);
    Road* road2 = new Road("doe", 100.0);

    EXPECT_EQ(road1->getCrossroads().size(), 0);

    Crossroad* crossroad = new Crossroad(new CrossroadDetails{ road1, 25 }, new CrossroadDetails{ road2, 25 });
    road1->addCrossroad(crossroad);

    EXPECT_EQ(crossroad, road1->getCrossroads()[0]);

    delete road1;
    delete road2;
}

TEST(RoadTests, CrossroadMutationInvalid) {
    Road road1 = Road("john", 100.0);

    EXPECT_DEATH(road1.addCrossroad(nullptr), "Crossroad cannot be nullptr");
}

TEST(RoadTests, TrafficLightMutationHappyDay) {
    Road road = Road("example", 100.0);
    EXPECT_EQ(road.getTrafficLights().size(), 0);
    TrafficLight* light = new TrafficLight(20.0, 10);
    road.addTrafficLight(light);
    EXPECT_EQ(light, road.getTrafficLights()[0]);
}

TEST(RoadTests, TrafficLightMutationInvalid) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.addTrafficLight(nullptr), "Cannot add empty traffic light to road");
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

TEST(RoadTests, TickBusStopsHappyDay) {
    NullBuffer null_buffer;
    std::ostream null_stream(&null_buffer);

    Road road = Road("example", 100.0);
    int waitTime = 2;
    BusStop* busStop = new BusStop(50, waitTime);
    Vehicle* bus = new Vehicle(49.9, VehicleType::Bus);
    road.addBusStop(busStop);
    road.addVehicle(bus);

    int requiredTicks = std::round((double) waitTime / (double) gSimTime);

    for (int i = 0; i < requiredTicks / 2; i++) {road.tickBusStops(); road.tickVehicles(null_stream);}
    EXPECT_TRUE(bus->getPosition() < busStop->getPosition());

    // 50 tick margin
    for (int i = 0; i < requiredTicks / 2 + 50; i++) {road.tickBusStops(); road.tickVehicles(null_stream);}
    EXPECT_TRUE(bus->getPosition() > busStop->getPosition());
}

TEST(RoadTests, GetFirstToTrafficLightHappyDay) {
    Road road = Road("example", 100.0);
    TrafficLight* trafficLight = new TrafficLight(20.0, 10);
    Vehicle* vehicle = new Vehicle(10, VehicleType::Personal);
    road.addVehicle(vehicle);
    road.addTrafficLight(trafficLight);

    EXPECT_EQ(road.getFirstToTrafficLight(trafficLight), vehicle);
}

TEST(RoadTests, GetFirstToTrafficLightInvalid) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.getFirstToTrafficLight(nullptr), "Traffic light cannot be nullptr");
}

TEST(RoadTests, GetFirstToTrafficLightUnknown) {
    Road road = Road("example", 100.0);
    TrafficLight* trafficLight = new TrafficLight(20.0, 10);
    EXPECT_DEATH(road.getFirstToTrafficLight(trafficLight), "Traffic light must be on road");
}

TEST(RoadTests, GetFirstBusToBusStopHappyDay) {
    Road road = Road("example", 100.0);
    BusStop* busStop = new BusStop(20, 20);
    Vehicle* vehicle = new Vehicle(10, VehicleType::Bus);
    road.addVehicle(vehicle);
    road.addBusStop(busStop);

    EXPECT_EQ(road.getFirstBusToBusStop(busStop), vehicle);
}

TEST(RoadTests, GetFirstBusToBusStopInvalid) {
    Road road = Road("example", 100.0);
    EXPECT_DEATH(road.getFirstBusToBusStop(nullptr), "Bus stop cannot be nullptr");
}

TEST(RoadTests, GetFirstBusToBusStopUnknown) {
    Road road = Road("example", 100.0);
    BusStop* busStop = new BusStop(20, 20);

    EXPECT_DEATH(road.getFirstBusToBusStop(busStop), "Bus stop must be on road");
}

TEST(RoadTests, GetLeadingVehicleHappyDay) {
    Road road = Road("example", 100.0);
    Vehicle* vehicle1 = new Vehicle(10, VehicleType::Personal);
    Vehicle* vehicle2 = new Vehicle(20, VehicleType::Personal);
    road.addVehicle(vehicle1);
    road.addVehicle(vehicle2);

    EXPECT_EQ(road.getLeadingVehicle(vehicle1), vehicle2);
}

TEST(RoadTests, GetLeadingVehicleInvalid) {
    Road road = Road("example", 100.0);

    EXPECT_DEATH(road.getLeadingVehicle(nullptr), "Vehicle may not be a nullptr");
}

TEST(RoadTests, GetLeadingVehicleUnknown) {
    Road road = Road("example", 100.0);
    Vehicle* vehicle1 = new Vehicle(10, VehicleType::Personal);

    EXPECT_DEATH(road.getLeadingVehicle(vehicle1), "Vehicle must be on road");
}

TEST(RoadTests, SpawnVehicleHappyDay) {
    Road road = Road("example", 100.0);
    EXPECT_EQ(road.getVehicles().size(), 0);
    road.spawnVehicle(VehicleType::Personal);
    EXPECT_EQ(road.getVehicles().size(), 1);
}
