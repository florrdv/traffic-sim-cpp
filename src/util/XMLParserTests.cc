#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.cc"
#include "../lib/TestingHelpers.h"
#include "../util/XMLParser.h"

TEST(XMLParserTests, ParsingRoadBoundaries) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest1.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest1.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest1.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "road boundaries");
}


TEST(XMLParserTests, ParsingRoadLengthNegative) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest3.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest3.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest3.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingRoadLengthZero) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest4.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest4.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest4.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingVehicleRoadUnknown) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest10.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest10.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest10.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleGeneratorRoadUnknown) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest11.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest11.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest11.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleGeneratorMultiple) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest12.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest12.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest12.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "multiple vehicle generators");
}

TEST(XMLParserTests, ParsingVehiclesNegativePosition) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest2.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest2.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest2.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be positive");
}

TEST(XMLParserTests, ParsingVehiclesOverlap) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest5.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest5.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest5.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingTrafficLightsOverlap) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest6.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest6.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest6.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingTrafficLightRoadUnknown) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest7.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest7.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest7.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingTrafficLightCycleNegative) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest8.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest8.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest8.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingTrafficLightCycleZero) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest9.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest9.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest9.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}


TEST(XMLParserTests, ParsingTrafficLightDecelerationOverlap) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/InvalidXMLParserTest13.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest13.txt";

    std::string xmlPath = TEST_INPUT_FOLDER + "/InvalidXMLParserTest13.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "deceleration zone");
}

