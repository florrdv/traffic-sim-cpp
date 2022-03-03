//============================================================================
// Name        : XMLParser.cc
// Author      : Achraf Yandouzi, Flor Ronsmans De Vry
// Description : XML Parser
//============================================================================

#include "XMLParser.h"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"
#include "../Simulation.h"

#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");

    if (!result) throw "XML: Invalid XML structure";

    for (pugi::xml_node tool : doc) {
        std::string name = tool.name();
        if (name == "BAAN") {
            std::cout << "Found road" << std::endl;
        }
        else if (name == "VERKEERSLICHT") {
            std::cout << "Found traffic light" << std::endl;
            std::cout << "Found vehicle" << std::endl;
        } else {
            throw "XML: Unknown tag '" + name + "'";
        }
    }
}
