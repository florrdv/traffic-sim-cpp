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

#include "../data/Constants.cc"
#include "../objects/Road.h"
#include "../objects/TrafficLight.h"
#include "../objects/Vehicle.h"
#include "../objects/VehicleGenerator.h"
#include "../Simulation.h"
#include "../lib/DesignByContract.h"

#include <map>

 // Een verkeerssituatie is consistent als:
 // • Elk voertuig staat op een bestaande baan.                              OK UNTESTED
 // • Elk verkeerslicht staat op een bestaande baan.                         OK UNTESTED
 // • Elke voertuiggenerator staat op een bestaande baan.                    OK UNTESTED
 // • De positie van elk voertuig is kleiner dan de lengte van de baan.      OK UNTESTED
 // • De positie van elk verkeerslicht is kleiner dan de lengte van de baan. OK UNTESTED
 // • Er is maximaal ´e´en voertuiggenerator op elke baan.                   OK UNTESTED
 // • Een verkeerslicht mag zich niet in de vertraagafstand van een ander    OK UNTESTED
 // verkeerslicht bevinden (zie Appendix B).

  /**
  \n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
  */
void XMLParser::validateNode(const pugi::xml_node& node, const std::string& name) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    ASSERT(!node.empty(), ("XML: no " + name + " child found").c_str());
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
\n ENSURE(value>=0, "Parsed integer cannot be negative");
*/
int XMLParser::parsePositiveInteger(const std::string& s, const std::string& name, const bool strictlyPositive = false) const {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    int value;
    try {
        value = stoi(s);
        ASSERT((strictlyPositive && value > 0) || !strictlyPositive,  ("XML: " + name + " must be strictly positive").c_str());
        ASSERT(value >= 0, ("XML: " + name + " must be positive").c_str());
    }
    catch (std::exception& e) {
        ASSERT(false, ("XML: " + name + " must be an integer").c_str());
    }
    ENSURE(value >= 0, "Parsed integer cannot be negative");
    return value;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void XMLParser::parse(Simulation& sim, const std::string file) {
    REQUIRE(this->properlyInitialized(), "Parser was not properly initialized");
    // Load input file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file.c_str());
    // Make sure the file was loaded correctly
    ASSERT(result, "XML: invalid file");

    // Parameters for validation
    std::map<std::string, std::vector<TrafficLight*>> trafficLights = {};
    std::map<std::string, std::vector<Vehicle*>> vehicles = {};
    std::map<std::string, std::vector<VehicleGenerator*>> generators = {};

    // Loop over all nodes in the document
    // we just loaded
    for (pugi::xml_node node : doc) {
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
            int roadLength = parsePositiveInteger(lengthNode.text().as_string(), "length", true);

            // Create road object
            Road* road = new Road();
            road->setName(roadName);
            road->setLength(roadLength);

            // Register road
            sim.addRoad(road);
        }
        else if (name == "VERKEERSLICHT") {
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
            int cycle = parsePositiveInteger(cycleNode.text().as_string(), "cycle", true);

            // Create traffic light object
            TrafficLight* trafficLight = new TrafficLight();
            trafficLight->setPosition(pos);
            trafficLight->setCycle(cycle);

            if (trafficLights.find(road) == trafficLights.end()) trafficLights.insert({ road, {} });
            trafficLights[road].push_back(trafficLight);

        }
        else if (name == "VOERTUIG") {
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
            Vehicle* vehicle = new Vehicle();
            vehicle->setPosition(pos);

            if (vehicles.find(road) == vehicles.end()) vehicles.insert({ road, {} });
            vehicles[road].push_back(vehicle);

        }
        else if (name == "VOERTUIGGENERATOR") {
            // Fetch nodes
            pugi::xml_node roadNode = node.child("baan");
            pugi::xml_node freqNode = node.child("frequentie");

            // Check if the nodes exist
            validateNode(roadNode, "baan");
            validateNode(freqNode, "frequentie");

            // Extract values
            std::string road = roadNode.text().as_string();
            int freq = parsePositiveInteger(freqNode.text().as_string(), "frequency", true);

            // Create vehicle generator object
            VehicleGenerator* generator = new VehicleGenerator();
            generator->setFrequency(freq);

            if (generators.find(road) == generators.end()) generators.insert({ road, {} });
            generators[road].push_back(generator);
        }
        else {
            ASSERT(false, ("XML: unknown tag '" + name + "'").c_str());
        }
    }


    // Let's continue parsing the data
    // We have to put every vehicle and traffic light
    // on a road, while making sure that the road exists.

    // Vehicles
    for (std::pair<std::string, std::vector<Vehicle*>> p : vehicles) {
        Road* road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());

        // Register the vehicle
        for (Vehicle* v : p.second) {
            ASSERT(v->getPosition() <= road->getLength(), "XML: vehicle outside of road boundaries");
            road->addVehicle(v);
        }
    }

    for (Road* road : sim.getRoads()) {
        std::vector<Vehicle*> vehicles = road->getVehicles();
        for (int vehicleIndexOne = 0; vehicleIndexOne < vehicles.size(); vehicleIndexOne++) {
            Vehicle* vehicleOne = vehicles[vehicleIndexOne];
            for (int vehicleIndexTwo = 0; vehicleIndexTwo < vehicles.size(); vehicleIndexTwo++) {
                if (vehicleIndexOne == vehicleIndexTwo) continue;

                Vehicle* vehicleTwo = vehicles[vehicleIndexTwo];
                ASSERT(vehicleTwo->getPosition() != vehicleOne->getPosition(), "XML: vehicles cannot be on the same position");
            }
        }
    }

    // Traffic lights
    for (std::pair<std::string, std::vector<TrafficLight*>> p : trafficLights) {
        Road* road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());

        // Register the traffic light
        for (TrafficLight* t : p.second) {
            ASSERT(t->getPosition() <= road->getLength(), "XML: traffic light outside of road boundaries");
            road->addTrafficLight(t);
        }
    }

    for (Road* road : sim.getRoads()) {
        std::vector<TrafficLight*> placedTrafficLights = road->getTrafficlights();
        for (int trafficLightIndexOne = 0; trafficLightIndexOne < placedTrafficLights.size(); trafficLightIndexOne++) {
            TrafficLight* trafficLightOne = placedTrafficLights[trafficLightIndexOne];
            for (int trafficLightIndexTwo = 0; trafficLightIndexTwo < placedTrafficLights.size(); trafficLightIndexTwo++) {
                if (trafficLightIndexOne == trafficLightIndexTwo) continue;

                TrafficLight* trafficLightTwo = placedTrafficLights[trafficLightIndexTwo];
                ASSERT(!(trafficLightTwo->getPosition() > (trafficLightOne->getPosition() - DECELERATION_DISTANCE) && trafficLightTwo->getPosition() < trafficLightOne->getPosition()), "XML: traffic light in deceleration zone of other traffic light");
                ASSERT(trafficLightTwo->getPosition() != trafficLightOne->getPosition(), "XML: traffic lights cannot be on the same position");
            }
        }
    }

    // Vehicle generators
    for (std::pair<std::string, std::vector<VehicleGenerator*>> p : generators) {
        Road* road = sim.findRoad(p.first);
        ASSERT(road != nullptr, ("XML: unknown road " + p.first).c_str());
        ASSERT(p.second.size() <= 1, ("XML: multiple vehicle generators on road " + p.first).c_str());

        for (VehicleGenerator* g : p.second) road->setGenerator(g);
    }
}

