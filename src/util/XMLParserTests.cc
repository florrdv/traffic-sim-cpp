#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.cc"
#include "../lib/TestingHelpers.h"
#include "../util/XMLParser.h"

TEST(XMLParserTests, ParsingRoadBoundaries) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingRoadBoundaries.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "road boundaries");
}


TEST(XMLParserTests, ParsingRoadLengthNegative) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingRoadLengthNegative.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingRoadLengthZero) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingRoadLengthZero.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingVehicleRoadUnknown) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingVehicleRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleNegativePosition) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingVehicleNegativePosition.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be positive");
}

TEST(XMLParserTests, ParsingVehicleOverlap) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingVehicleOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingVehicleGeneratorRoadUnknown) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingVehicleGeneratorRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleGeneratorMultiple) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingVehicleGeneratorMultiple.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "multiple vehicle generators");
}

TEST(XMLParserTests, ParsingTrafficLightsOverlap) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingTrafficLightsOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingTrafficLightRoadUnknown) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingTrafficLightRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingTrafficLightCycleNegative) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingTrafficLightCycleNegative.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingTrafficLightCycleZero) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingTrafficLightCycleZero.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}


TEST(XMLParserTests, ParsingTrafficLightDecelerationOverlap) {
    std::string xmlPath = TEST_INPUT_FOLDER + "/ParsingTrafficLightDecelerationOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "deceleration zone");
}

