#include <gtest/gtest.h>
#include <fstream>
#include <cmath>

#include "data/Constants.h"
#include "lib/TestingHelpers.h"
#include "util/XMLParser.h"
#include "Simulation.h"


TEST(SimulationTests, ValidSimulationTest1) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest1.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest1.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest1.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 0, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest2) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest2.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest2.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 0, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest3) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest3.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest3.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest4) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest4.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest4.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest5) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest5.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest5.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest6) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest6.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest6.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest7) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest7.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest7.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest8) {
    std::string outPath = gTestOutputFolder + "/ValidSimulationTest8.txt";
    std::string inPath = gTestInputFolder + "/ValidSimulationTest8.txt";

    std::string xmlPath = gTestInputFolder + "/ValidSimulationTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50, 500);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, RoadMutationHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    road->setName("example");

    sim.addRoad(road);

    EXPECT_EQ(road, sim.findRoad("example"));
}

TEST(SimulationTests, CountVehiclesHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    road->setName("example");
    sim.addRoad(road);

    Vehicle* vehicle = new Vehicle(0.0, VehicleType::Personal);
    road->addVehicle(vehicle);

    EXPECT_EQ(1, sim.countVehicles());
}

TEST(SimulationTests, TickTrafficLightsHappyDay) {
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

TEST(SimulationTests, TickTrafficLightsUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    TrafficLight* light = new TrafficLight(20.0, 20);
    road->addTrafficLight(light);

    EXPECT_DEATH(sim.tickTrafficLights(road), "not part of the simulation");

    delete road;
}

TEST(SimulationTests, TickVehicleGeneratorsHappyDay) {
    int frequency = 10;

    Simulation sim = Simulation();
    Road* road = new Road("example", 100.0);
    sim.addRoad(road);
    VehicleGenerator* generator = new VehicleGenerator(frequency, VehicleType::Personal);
    road->setGenerator(generator);

    int expectedAfterTick = sim.countVehicles()+1;

    generator->setFrequencyCount(ceil(frequency/gSimTime));
    sim.tickVehicleGenerators(road);

    EXPECT_EQ(expectedAfterTick, sim.countVehicles());
}

TEST(SimulationTests, TickVehicleGeneratorsUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 20.0);
    VehicleGenerator* generator = new VehicleGenerator(10, VehicleType::Personal);
    road->setGenerator(generator);

    EXPECT_DEATH(sim.tickVehicleGenerators(road), "not part of the simulation");

    delete road;
}

TEST(SimulationTests, TickVehiclesUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road("example", 10.0);
    Vehicle* vehicle = new Vehicle(20.0, VehicleType::Personal);
    road->addVehicle(vehicle);


    EXPECT_DEATH(sim.tickVehicles(road, std::cout), "not part of the simulation");

    delete road;
}

TEST(SimulationTests, GetSetRoads) {
    Simulation sim = Simulation();
    REQUIRE(sim.getRoads().empty(), "simulation should not have roads yet");
    Road* road = new Road("example", 10.0);
    sim.addRoad(road);
    REQUIRE(sim.getRoads().size()==1, "added road was not detected");
    REQUIRE(sim.findRoad("example")==road, "could not find road with added name");
}
