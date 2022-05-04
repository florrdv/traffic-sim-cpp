/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:17:49 pm
 */

#include <gtest/gtest.h>
#include <fstream>

#include "../data/Constants.h"
#include "../lib/TestingHelpers.h"
#include "../util/XMLParser.h"

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

TEST(XMLParserTests, ParsingVehiclePositionOutOfBound) {
    std::string xmlPath = gTestInputFolder + "/ParsingVehiclePositionOutOfBound.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "Road not long enough");
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

TEST(XMLParserTests, ParsingTrafficLightPositionOutOfBound) {
    std::string xmlPath = gTestInputFolder + "/ParsingTrafficLightPositionOutOfBound.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "Road not long enough");
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

TEST(XMLParserTests, ParsingHappyDay) {
    std::string xmlPath = gTestInputFolder + "/ParsingHappyDay.xml";

    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_EXIT({
                    parser.parse(sim, xmlPath);
                    fprintf(stderr, "Parsed successfully");
                    exit(0);
                },
                ::testing::ExitedWithCode(0), "Parsed successfully");
}

TEST(XMLParserTests, NoRoadNameXML) {
    std::string xmlPath = gTestInputFolder + "/NoRoadName.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "no child found");
}

TEST(XMLPArserTests, UnknownVehicleType) {
    std::string xmlPath = gTestInputFolder + "/ParsingUnknownVehicleType.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown vehicle type");
}

TEST(XMLParserTests, ParsingBusStopNoRoad) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopNoRoad.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "no child found");
}

TEST(XMLParserTests, ParsingBusStopNoPosition) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopNoPosition.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "no child found");
}

TEST(XMLParserTests, ParsingBusStopNoWaitTime) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopNoWaitTime.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "no child found");
}

TEST(XMLParserTests, ParsingBusStopNegativePosition) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopNegativePosition.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be positive");
}

TEST(XMLParserTests, ParsingBusStopWaitTimeNegative) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopWaitTimeNegative.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingBusStopWaitTimeZero) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopWaitTimeZero.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingBusStopUndefinedRoad) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopUndefinedRoad.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingBusStopPositionOutOfBound) {
    std::string xmlPath = gTestInputFolder + "/ParsingBusStopPositionOutOfBound.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "Road not long enough");
}

TEST(XMLParserTests, ParsingCrossroadOneRoad) {
    std::string xmlPath = gTestInputFolder + "/ParsingCrossroadOneRoad.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "no child found");
}

TEST(XMLParserTests, ParsingCrossroadNegativePosition) {
    std::string xmlPath = gTestInputFolder + "/ParsingCrossroadNegativePosition.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "must be strictly positive");
}

TEST(XMLParserTests, ParsingCrossroadUndefinedRoad) {
    std::string xmlPath = gTestInputFolder + "/ParsingCrossroadUndefinedRoad.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "unknown road");
}

TEST(XMLParserTests, ParsingCrossroadInvalidRoadCombination) {
    std::string xmlPath = gTestInputFolder + "/ParsingCrossroadInvalidRoadCombination.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "invalid road combination");
}

TEST(XMLParserTests, ParsingCrossroadPositionOutOfBound) {
    std::string xmlPath = gTestInputFolder + "/ParsingCrossroadPositionOutOfBound.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    EXPECT_DEATH(parser.parse(sim, xmlPath), "Position must be within road bounds");
}

TEST(XMLParserTests, ParsingValidNode) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    pugi::xml_node roadNode = *it;


    pugi::xml_node nameNode = roadNode.child("naam");

    EXPECT_EXIT({
                    parser.validateNode(nameNode, "naam");
                    fprintf(stderr, "Done");
                    exit(0);
                },
                ::testing::ExitedWithCode(0), "Done");

    pugi::xml_node lengthNode = roadNode.child("lengte");

    EXPECT_EXIT({
                    parser.validateNode(lengthNode, "lengte");
                    fprintf(stderr, "Done");
                    exit(0);
                },
                ::testing::ExitedWithCode(0), "Done");
}

TEST(XMLParserTests, ParsingInvalidNode) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    pugi::xml_node node = *it;

    pugi::xml_node counterfeitChild = node.child("foo");

    EXPECT_DEATH(parser.validateNode(counterfeitChild, "foo"), "XML: no child found for foo");
}


TEST(XMLParserTests, ParsingPositiveIntegerHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    pugi::xml_node node = *it;

    pugi::xml_node lengthNode = node.child("lengte");
    std::string lengthString = lengthNode.text().as_string();

    EXPECT_EQ(10, parser.parsePositiveInteger(lengthString, "lengte", true));
}

TEST(XMLParserTests, ParsingPositiveIntegerNegative) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    it++;
    pugi::xml_node vehicleNode = *it;

    pugi::xml_node positionNode = vehicleNode.child("positie");
    std::string positionString = positionNode.text().as_string();

    EXPECT_DEATH(parser.parsePositiveInteger(positionString, "positie", true), "strictly positive");
}

TEST(XMLParserTests, ParsingRoadHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    pugi::xml_node roadNode = *it;

    Road *road = parser.parseRoad(roadNode);

    EXPECT_EQ("Middelheimlaan", road->getName());
    EXPECT_EQ(10, road->getLength());
}

TEST(XMLParserTests, ParsingVehicleHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 2);

    pugi::xml_node vehicleNode = *it;

    Vehicle *vehicle = parser.parseVehicle(vehicleNode);

    EXPECT_EQ(10, vehicle->getPosition());
}

TEST(XMLParserTests, ParsingTrafficLightHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 3);

    pugi::xml_node trafficLightNode = *it;

    TrafficLight *trafficLight = parser.parseTrafficLight(trafficLightNode);

    EXPECT_EQ(90, trafficLight->getPosition());
    EXPECT_EQ(15, trafficLight->getCycle());
}

TEST(XMLParserTests, ParsingVehicleGeneratorHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 4);

    pugi::xml_node vehicleGeneratorNode = *it;

    VehicleGenerator *vehicleGenerator = parser.parseVehicleGenerator(vehicleGeneratorNode);

    EXPECT_EQ(3, vehicleGenerator->getFrequency());
    EXPECT_EQ(VehicleType::Police, vehicleGenerator->getType());
}

TEST(XMLParserTests, ParsingBusStopHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 5);

    pugi::xml_node busStopNode = *it;

    BusStop *busStop = parser.parseBusStop(busStopNode);

    EXPECT_EQ(90, busStop->getPosition());
    EXPECT_EQ(20, busStop->getWaitTime());
}

TEST(XMLParserTests, ParsingCrossroadHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 6);

    pugi::xml_node crossroadNode = *it;

    std::pair<std::pair<std::string, int>, std::pair<std::string, int>> crossroad = parser.parseCrossroad(
            crossroadNode);

    EXPECT_EQ(crossroad.first.first, "Middelheimlaan");
    EXPECT_EQ(crossroad.first.second, 250);

    EXPECT_EQ(crossroad.second.first, "Groenenborgerlaan");
    EXPECT_EQ(crossroad.second.second, 500);
}

TEST(XMLParserTests, ParsingRoadReferenceHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 2);

    pugi::xml_node vehicleNode = *it;

    std::string road = parser.parseRoadReference(vehicleNode);

    EXPECT_EQ("Middelheimlaan", road);
}

TEST(XMLParserTests, ParsingVehicleTypeHappyDay) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 4);

    pugi::xml_node vehicleGeneratorNode = *it;

    pugi::xml_node vehicleTypeNode = vehicleGeneratorNode.child("type");

    VehicleType type = parser.parseVehicleType(vehicleTypeNode);

    EXPECT_EQ(type, VehicleType::Police);
}

TEST(XMLParserTests, ParsingCrossroadDuplicate) {
    std::string xmlPath = gTestInputFolder + "/Miscellaneous.xml";
    Simulation sim = Simulation();

    XMLParser parser;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    ASSERT(result, "XML: invalid file");

    pugi::xml_node_iterator it = doc.begin();
    std::advance(it, 7);

    pugi::xml_node crossroadNode = *it;

    EXPECT_DEATH(parser.parseCrossroad(crossroadNode), "invalid road combination");
}
