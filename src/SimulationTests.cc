#include <gtest/gtest.h>
#include <fstream>

#include "data/Constants.cc"
#include "lib/TestingHelpers.h"
#include "util/XMLParser.h"
#include "Simulation.h"


TEST(SimulationTests, ValidSimulationTest1) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest1.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest1.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest1.xml";
    
    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest2) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest2.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest2.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest3) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest3.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest3.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest4) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest4.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest4.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest5) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest5.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest5.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest6) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest6.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest6.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest7) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest7.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest7.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, ValidSimulationTest8) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/ValidSimulationTest8.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/ValidSimulationTest8.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/ValidSimulationTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file, 50);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

