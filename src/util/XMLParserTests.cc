#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.cc"
#include "../lib/TestingHelpers.h"
#include "../util/XMLParser.h"

TEST(XMLParserTests, ParsingRoadBoundaries) {
    std::string xmlPath = gTestInputFolder + "/ParsingRoadBoundaries.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "road boundaries");
}


TEST(XMLParserTests, ParsingRoadLengthNegative) {
    std::string xmlPath = gTestInputFolder + "/ParsingRoadLengthNegative.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingRoadLengthZero) {
    std::string xmlPath = gTestInputFolder + "/ParsingRoadLengthZero.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingVehicleRoadUnknown) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehicleRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleNegativePosition) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehicleNegativePosition.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be positive");
}

TEST(XMLParserTests, ParsingVehicleOverlap) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehicleOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingVehicleGeneratorRoadUnknown) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehicleGeneratorRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingVehicleGeneratorMultiple) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehicleGeneratorMultiple.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "multiple vehicle generators");
}

TEST(XMLParserTests, ParsingTrafficLightsOverlap) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightsOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "same position");
}

TEST(XMLParserTests, ParsingTrafficLightRoadUnknown) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightRoadUnknown.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingTrafficLightCycleNegative) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightCycleNegative.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingTrafficLightCycleZero) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightCycleZero.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}


TEST(XMLParserTests, ParsingTrafficLightDecelerationOverlap) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightDecelerationOverlap.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "deceleration zone");
}

