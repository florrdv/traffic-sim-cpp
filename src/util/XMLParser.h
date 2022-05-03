/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:17:49 pm
 */

#include "../Simulation.h"

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_


#include <iostream>
#include <string>
#include "../lib/pugixml/pugixml.hpp"
#include "../objects/BusStop.h"
#include "../objects/Crossroad.h"

class XMLParser {
    FRIEND_TEST(XMLParserTests, ParsingValidNode);
    FRIEND_TEST(XMLParserTests, ParsingInvalidNode);
    FRIEND_TEST(XMLParserTests, ParsingPositiveIntegerHappyDay);
    FRIEND_TEST(XMLParserTests, ParsingPositiveIntegerNegative);
    FRIEND_TEST(XMLParserTests, ParsingRoadHappyDay);

private:
    XMLParser* _init;

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    void validateNode(const pugi::xml_node& node, const std::string& name) const;
    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(value>=0, "Parsed integer cannot be negative");
    */
    int parsePositiveInteger(const std::string& s, const std::string& name, const bool strictlyPositive) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(road != nullptr, "Road has to be generated");
    */
    Road* parseRoad(const pugi::xml_node& node);
    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(vehicle != nullptr, "Road has to be generated");
    */
    Vehicle* parseVehicle(const pugi::xml_node& node);
    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(trafficLight != nullptr, "Road has to be generated");
    */
    TrafficLight* parseTrafficLight(const pugi::xml_node& node);
    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(generator != nullptr, "Road has to be generated");
    */
    VehicleGenerator* parseVehicleGenerator(const pugi::xml_node& node);

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    \n ENSURE(busStop != nullptr, "Road has to be generated";
    */
    BusStop *parseBusStop(const pugi::xml_node &node);

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    std::pair<std::pair<std::string, int>, std::pair<std::string, int>> parseCrossRoad(const pugi::xml_node &node) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    std::string parseRoadReference(const pugi::xml_node& node);

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    std::pair<std::string, std::string> parseRoadReferences(const pugi::xml_node &node);

    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    VehicleType parseVehicleType(const pugi::xml_node& node);

public:
    // Constructors / destructors
    XMLParser() { _init = this; };

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "XMLParser wasn't initialized properly");
    */
    void parse(Simulation& sim, const std::string file);

    // Safety specific
    const bool properlyInitialized() const { return _init == this; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_
