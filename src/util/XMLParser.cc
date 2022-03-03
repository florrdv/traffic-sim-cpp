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

void XMLParser::validateNode(const pugi::xml_node& node, const std::string name) const {
    if (node.empty()) throw std::runtime_error("XML: no " + name + "child found");
}

int XMLParser::parseInteger(const std::string& s, const std::string name) const {
    int value;
    try {
        value = stoi(s);
    } catch (std::exception) {
        throw "XML: "+ name + " must be an integer";
    }

    return value;
}

void XMLParser::parse(Simulation& sim) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");

    if (!result) throw std::runtime_error("XML: invalid file");

    for (pugi::xml_node node : doc) {
        std::string name = node.name();
        if (name == "BAAN") {
            // Fetch nodes
            pugi::xml_node nameNode = node.child("naam");
            pugi::xml_node lengthNode = node.child("lengte");

            // Check if the nodes exist
            validateNode(nameNode, "name");
            validateNode(lengthNode, "length");

            // Extract values
            std::string roadName = nameNode.text().as_string();
            int roadLength = parseInteger(lengthNode.text().as_string(), "length");

            // Make road object
            Road* road = new Road;
            road->setName(roadName);
            road->setLength(roadLength);

            // Register road
            sim.addRoad(road);
        } else if (name == "VERKEERSLICHT") {
            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node positionNode = node.child("position");
            pugi::xml_node cycleNode = node.child("position");

            // Check if the nodes exist
            validateNode(roadNode, "road");
            validateNode(positionNode, "position");
            validateNode(cycleNode, "cycle");

            // Extract values
            std::string road = roadNode.text().as_string();
            int position = parseInteger(positionNode.text().as_string(), "position");
            int cycle = parseInteger(cycleNode.text().as_string(), "cycle");
 
        } else if (name == "VOERTUIG") {
            Vehicle vehicle;

            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node posNode = node.child("positie");

            // Check if the nodes exist
            validateNode(roadNode, "baan");
            validateNode(posNode, "positie");

            // Extract values
            std::string vehicleRoad = roadNode.text().as_string();
            int vehiclePos = parseInteger(posNode.text().as_string(), "position");

            // Set values
            vehicle.setRoad(vehicleRoad);
            vehicle.setPosition(vehiclePos);

            Road* r = sim.findRoad(vehicleRoad);
            if (r == NULL) {
                throw std::runtime_error("XML: road for vehicle not found");
            }

            r->setVehicles(*vehicle);

        } else {
            throw std::runtime_error("XML: Unknown tag '" + name + "'");
        }
    }

    
}

