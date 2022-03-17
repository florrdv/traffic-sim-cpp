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
#include "../objects/VehicleGenerator.h"
#include "../Simulation.h"
#include "../lib/DesignByContract.h"

#include <map>

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void XMLParser::validateNode(const pugi::xml_node &node, const std::string& name) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    if (node.empty()) throw std::runtime_error("XML: no " + name + " child found");
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
\n ENSURE(value>=0, "Parsed integer cannot be negative");
*/
int XMLParser::parsePositiveInteger(const std::string &s, const std::string& name) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    int value;
    try {
        value = stoi(s);
        if (value < 0) throw std::runtime_error("XML: " + name + " must be positive");
    } catch (std::exception &e) {
        throw std::runtime_error("XML: " + name + " must be an integer");
    }
    ENSURE(value>=0, "Parsed integer cannot be negative");
    return value;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void XMLParser::parse(Simulation &sim) {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    // Load input file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");
    // Make sure the file was loaded correctly
    if (!result) throw std::runtime_error("XML: invalid file");

    // Parameters for validation
    std::map<std::string, std::vector<TrafficLight *>> trafficLights = {};
    std::map<std::string, std::vector<Vehicle *>> vehicles = {};
    std::map<std::string, std::vector<VehicleGenerator *>> generators = {};

    // Loop over all nodes in the document
    // we just loaded
    for (pugi::xml_node node: doc) {
        // Extract the node's name, we'll use this to determine the
        // type of node we're dealing with
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

            // Create road object
            Road *road = new Road();
            road->setName(roadName);
            road->setLength(roadLength);

            // Register road
            sim.addRoad(road);
        } else if (name == "VERKEERSLICHT") {
            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node positionNode = node.child("positie");
            pugi::xml_node cycleNode = node.child("cyclus");

            // Check if the nodes exist
            validateNode(roadNode, "road");
            validateNode(positionNode, "position");
            validateNode(cycleNode, "cycle");

            // Extract values
            std::string road = roadNode.text().as_string();
            int pos = parsePositiveInteger(positionNode.text().as_string(), "position");
            int cycle = parsePositiveInteger(cycleNode.text().as_string(), "cycle");

            // Create traffic light object
            TrafficLight *trafficLight = new TrafficLight();
            trafficLight->setPosition(pos);
            trafficLight->setCycle(cycle);

            if (trafficLights.find(road) == trafficLights.end()) trafficLights.insert({road, {}});
            trafficLights[road].push_back(trafficLight);

        } else if (name == "VOERTUIG") {
            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node posNode = node.child("positie");

            // Check if the nodes exist
            validateNode(roadNode, "baan");
            validateNode(posNode, "positie");

            // Extract values
            std::string road = roadNode.text().as_string();
            int pos = parsePositiveInteger(posNode.text().as_string(), "position");

            // Create vehicle object
            Vehicle *vehicle = new Vehicle();
            vehicle->setPosition(pos);

            if (vehicles.find(road) == vehicles.end()) vehicles.insert({road, {}});
            vehicles[road].push_back(vehicle);

        } else if (name == "VOERTUIGGENERATOR") {
            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node freqNode = node.child("frequentie");

            // Check if the nodes exist
            validateNode(roadNode, "baan");
            validateNode(freqNode, "frequentie");

            // Extract values
            std::string road = roadNode.text().as_string();
            int freq = parsePositiveInteger(freqNode.text().as_string(), "frequency");

            // Create vehicle generator object
            VehicleGenerator *generator = new VehicleGenerator();
            generator->setFrequency(freq);

            if (generators.find(road) == generators.end()) generators.insert({road, {}});
            generators[road].push_back(generator);
        } else {
            throw std::runtime_error("XML: unknown tag '" + name + "'");
        }
    }


    // Let's continue parsing the data
    // We have to put every vehicle and traffic light
    // on a road, while making sure that the road exists.

    // Vehicles
    for (std::pair<std::string, std::vector<Vehicle *>> p: vehicles) {
        Road *road = sim.findRoad(p.first);
        if (road == nullptr) throw std::runtime_error("XML: unknown road " + p.first);

        // Register the vehicle
        for (Vehicle *v: p.second) road->addVehicle(v);
    }

    // Traffic lights
    for (std::pair<std::string, std::vector<TrafficLight *>> p: trafficLights) {
        Road *road = sim.findRoad(p.first);
        if (road == nullptr) throw std::runtime_error("XML: unknown road " + p.first);

        // Register the traffic light
        for (TrafficLight *t: p.second) road->addTrafficLight(t);
    }

    // Vehicle generators
    for (std::pair<std::string, std::vector<VehicleGenerator *>> p: generators) {
        Road *road = sim.findRoad(p.first);
        if (road == nullptr) throw std::runtime_error("XML: unknown road " + p.first);

        for (VehicleGenerator *g: p.second) road->addGenerator(g);
    }
}

