#include <gtest/gtest.h>
#include <fstream>

#include "data/Constants.cc"
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

