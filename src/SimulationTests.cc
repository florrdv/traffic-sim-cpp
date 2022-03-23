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
    Road* road = new Road();
    road->setName("example");

    sim.addRoad(road);

    EXPECT_EQ(road, sim.findRoad("example"));
}

TEST(SimulationTests, CountVehiclesHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road();
    road->setName("example");
    sim.addRoad(road);

    Vehicle* vehicle = new Vehicle;
    road->addVehicle(vehicle);

    EXPECT_EQ(1, sim.countVehicles());
}

TEST(SimulationTests, TickTrafficLightsHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road();
    sim.addRoad(road);
    TrafficLight* light = new TrafficLight();
    
    int cycle = 10;

    light->setCycle(cycle);
    road->addTrafficLight(light);

    bool beforeTicks = light->isGreen();

    light->setCycleCount(ceil(cycle/gSimTime));
    sim.tickTrafficLights(road);

    EXPECT_NE(beforeTicks, light->isGreen());
}

TEST(SimulationTests, TickTrafficLightsUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road();
    TrafficLight* light = new TrafficLight();
    
    EXPECT_DEATH(sim.tickTrafficLights(road), "not part of the simulation");

    delete road;
}

TEST(SimulationTests, TickVehicleGeneratorsHappyDay) {
    Simulation sim = Simulation();
    Road* road = new Road();
    sim.addRoad(road);
    VehicleGenerator* generator = new VehicleGenerator();
    road->setGenerator(generator);

    int frequency = 10;
    generator->setFrequency(frequency);

    int expectedAfterTick = sim.countVehicles()+1;

    generator->setFrequencyCount(ceil(frequency/gSimTime));
    sim.tickVehicleGenerators(road);

    EXPECT_EQ(expectedAfterTick, sim.countVehicles());
}

TEST(SimulationTests, TickVehicleGeneratorsUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road();
    VehicleGenerator* generator = new VehicleGenerator();
    road->setGenerator(generator);

    EXPECT_DEATH(sim.tickVehicleGenerators(road), "not part of the simulation");

    delete road;
}

TEST(SimulationTests, TickVehiclesUnknownRoad) {
    Simulation sim = Simulation();
    Road* road = new Road();
    Vehicle* vehicle = new Vehicle();
    vehicle->setPosition(20);
    road->addVehicle(vehicle);


    EXPECT_DEATH(sim.tickVehicles(road, std::cout), "not part of the simulation");

    delete road;
}