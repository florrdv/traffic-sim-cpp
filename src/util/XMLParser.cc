<<<<<<< HEAD
/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */


=======
//============================================================================
// Name        : XMLParser.cc
// Author      : Achraf Yandouzi, Flor Ronsmans De Vry
// Description : XML Parser
//============================================================================
>>>>>>> 19de6e576cb907168f9abce66ac8f1dc0051a882

#include "XMLParser.h"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"

#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");

    if (!result) throw std::runtime_error("XML: invalid file");

    for (pugi::xml_node tool : doc) {
        std::string name = tool.name();
        if (name == "BAAN") {
            std::cout << "Found road" << std::endl;
        } else if (name == "VERKEERSLICHT") {
            std::cout << "Found traffic light" << std::endl;
<<<<<<< HEAD
        } else if (name == "VOERTUIG") {
=======
>>>>>>> 19de6e576cb907168f9abce66ac8f1dc0051a882
            std::cout << "Found vehicle" << std::endl;
        } else {
            throw std::runtime_error("XML: Unknown tag '" + name + "'");
        }
    }

    
}
