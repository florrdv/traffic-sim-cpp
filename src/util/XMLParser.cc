/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include "XMLParser.h"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"
#include "../Simulation.h"

#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse(Simulation& sim) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");

    if (!result) throw std::runtime_error("XML: invalid file");

    for (pugi::xml_node node : doc) {
        std::string name = node.name();
        if (name == "BAAN") {
            // Make road object
            Road road;

            // Fetch nodes
            pugi::xml_node nameNode = node.child("naam");
            pugi::xml_node lengthNode = node.child("lengte");

            // Check if the nodes exist
            if (nameNode.empty()) throw std::runtime_error("XML: no name child found");
            if (lengthNode.empty()) throw std::runtime_error("XML: no length child found");

            // Extract values
            std::string roadName = nameNode.text().as_string();
            std::string roadLengthRaw = lengthNode.text().as_string();

            // Validate values
            int roadLength;
            try {
                roadLength = std::stoi(roadLengthRaw);
            } catch (std::exception) { throw std::runtime_error("XML: length must be a string"); }
 
            road.setName(roadName);
            road.setLength(roadLength);

            sim.addRoad(road);
        } else if (name == "VERKEERSLICHT") {
            std::cout << "Found traffic light" << std::endl;
        } else if (name == "VOERTUIG") {
            std::cout << "Found vehicle" << std::endl;
        } else {
            throw std::runtime_error("XML: Unknown tag '" + name + "'");
        }
    }

    
}
