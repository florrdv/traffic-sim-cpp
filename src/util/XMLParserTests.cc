#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.cc"
#include "../lib/TestingHelpers.h"
#include "../util/XMLParser.h"

TEST(SimulationTests, InvalidSimulationTest1) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest1.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest1.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest1.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest2) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest2.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest2.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest3) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest3.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest3.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest4) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest4.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest4.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest5) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest5.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest5.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest6) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest6.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest6.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest7) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest7.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest7.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest8) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest8.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest8.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest9) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest9.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest9.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest9.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest10) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest10.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest10.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest10.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest11) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest11.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest11.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest11.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest12) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest12.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest12.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest12.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

TEST(SimulationTests, InvalidSimulationTest13) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidSimulationTest13.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest13.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidSimulationTest13.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, xmlPath);

    std::ofstream file(outPath);
    sim.writeOn(file);
    file.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

