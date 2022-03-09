/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <map>
#include "XMLParser.h"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"
#include "../Simulation.h"

void XMLParser::validateNode(const pugi::xml_node& node, const std::string name) const {
    if (node.empty()) throw std::runtime_error("XML: no " + name + "child found");
}

int XMLParser::parsePositiveInteger(const std::string& s, const std::string name) const {
    int value;
    try {
        value = stoi(s);
        if (value < 0) throw std::runtime_error("XML: " + name + " must be positive");
    } catch (std::exception) {
        throw std::runtime_error("XML: "+ name + " must be an integer");
    }

    return value;
}

void XMLParser::parse(Simulation& sim) {
    // Load input file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");
    // Make sure the file was loaded correctly
    if (!result) throw std::runtime_error("XML: invalid file");

    // Parameters for validation
    std::map<std::string, Vehicle*> vehicles = {};
    std::map<std::string, TrafficLight*> trafficLights = {};

    // Loop over all nodes in the document
    // we just loaded
    for (pugi::xml_node node : doc) {
        // Extract the node's name, we'll use this to determine the 
        // type of node we're dealding with
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
            int roadLength = parsePositiveInteger(lengthNode.text().as_string(), "length");

            // Make road object
            Road* road = new Road();
            road->setName(roadName);
            road->setLength(roadLength);

            // Register road
            sim.addRoad(road);
        } else if (name == "VERKEERSLICHT") {
            // TODO: achraf fix pls
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
            int position = parsePositiveInteger(positionNode.text().as_string(), "position");
            int cycle = parsePositiveInteger(cycleNode.text().as_string(), "cycle");

            TrafficLight* trafficLight = new TrafficLight();
            trafficLights.insert({road, trafficLight});
 
        } else if (name == "VOERTUIG") {

            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node posNode = node.child("positie");

            // Check if the nodes exist
            validateNode(roadNode, "baan");
            validateNode(posNode, "positie");

            // Extract values
            std::string road = roadNode.text().as_string();
            int vehiclePos = parsePositiveInteger(posNode.text().as_string(), "position");

            // Create vehicle
            Vehicle* vehicle = new Vehicle();
            vehicles.insert({road, vehicle});

        } else {
            throw std::runtime_error("XML: unknown tag '" + name + "'");
        }

        // Let's continue parsing the data
        // We have to put every vehicle and traffic light
        // on a road, while makings sure that the road exists.
    }
}

