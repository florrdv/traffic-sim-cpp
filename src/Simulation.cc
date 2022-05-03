/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description:
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Tuesday, 1st March 2022 1:54:22 pm
 */

#include "Simulation.h"
#include "data/Constants.h"
#include "lib/DesignByContract.h"
#include "lib/json.hpp"
#include "lib/NullBuffer.h"
#include "objects/Crossroad.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>


Simulation::Simulation() {
    // Initialize random number generator
    srand((unsigned) time(0));

    _init = this;
    ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
}

Simulation::~Simulation() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    for (Road* road : roads) delete road;
}

std::vector<Road*> Simulation::getRoads() const {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    return roads;
}

void Simulation::addRoad(Road* r) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    REQUIRE(r != nullptr, "Road cannot be nullptr");
    roads.push_back(r);
    ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
}

Road* Simulation::findRoad(const std::string& roadName) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling findRoad");
    for (Road* r : roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

int Simulation::countVehicles() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");
    int amount = 0;
    for (Road* road : roads) amount += road->getVehicles().size();
    ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    return amount;
}

void Simulation::writeOn(std::ostream& onStream, const double stopAt, int speedup) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    // Loop while there are still vehicles
    // in the simulation
    while (countVehicles() > 0) {
        // Compute the current time and check if we should still
        // be running the simulation. We have a stopAt parameter for tests
        // using the Vehicle Generator feature.
        double currentTime = timestamp * gSimTime;
        if (stopAt != 0 && currentTime > stopAt) return;

        // Print the log entry header
        onStream << "-------------------------------------------" << std::endl;
        onStream << "Time: T+ " << currentTime << "s" << std::endl;

        // Loop over all roads
        for (Road* road : roads) {
            // Tick all entities on the road
            // we have these methods on the Simulation class as they control 
            // the general flow of the simulation, not the road itself.
            road->tick(onStream);
        }

        // Increment relative 
        timestamp++;

        // Sleep until the next simulation tick
         std::this_thread::sleep_for(std::chrono::milliseconds((int)(gSimTime * 1000 / (speedup*10000))));
    }
}

nlohmann::json Simulation::dumpState() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    nlohmann::json j;

    std::vector<nlohmann::json> vehiclesSerialized;
    for (Road* road : roads) {
        for (Vehicle* vehicle : road->getVehicles()) {
            nlohmann::json v;
            v["road"] = road->getName();
            v["type"] = vehicle->getType();
            v["position"] = vehicle->getPosition();

            vehiclesSerialized.push_back(v);
        }
    }

    std::vector<nlohmann::json> trafficLightsSerialized;
    for (Road* road : roads) {
        for (TrafficLight* trafficLight : road->getTrafficLights()) {
            nlohmann::json t;
            t["road"] = road->getName();
            t["position"] = trafficLight->getPosition();
            t["isGreen"] = trafficLight->isGreen();

            trafficLightsSerialized.push_back(t);
        }
    }

    j["vehicles"] = vehiclesSerialized;
    j["trafficLights"] = trafficLightsSerialized;

    return j;
}

void Simulation::writeToFile(std::ofstream& fileStream, const double stopAt) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    // Serialize all roads
    std::vector<nlohmann::json> roadsSerialized;
    for (Road* road : roads) {
        nlohmann::json roadSerialized;
        roadSerialized["name"] = road->getName();
        roadSerialized["length"] = road->getLength();

        roadsSerialized.push_back(roadSerialized);
    }

    // Serialize all bus stops
    std::vector<nlohmann::json> busStopsSerialized;
    for (Road* road : roads) {
       for (BusStop* busStop : road->getBusStops()) {
           nlohmann::json busStopSerialized;
           busStopSerialized["road"] = road->getName();
           busStopSerialized["position"] = busStop->getPosition();

            busStopsSerialized.push_back(busStopSerialized);
       }
    }

    // Serialize all crossroads
    std::vector<nlohmann::json> crossroadsSerialized;
    for (Road* road : roads) {
       for (Crossroad* crossroad : road->getCrossroads()) {
            std::pair<CrossroadDetails *, CrossroadDetails *> details = crossroad->getDetails();

            nlohmann::json road1Serialized;
            road1Serialized["name"] = details.first->road->getName();
            road1Serialized["position"] = details.first->position;

            nlohmann::json road2Serialized;
            road2Serialized["name"] = details.second->road->getName();
            road2Serialized["position"] = details.second->position;

            std::vector<nlohmann::json> crossroadSerialized = { road1Serialized, road2Serialized };
            crossroadsSerialized.push_back(crossroadSerialized);
       }
    }

    // Create the encapsulating JSON object
    nlohmann::json j;
    j["roads"] = roadsSerialized;
    j["busStops"] = busStopsSerialized;
    j["simTime"] = gSimTime;
    j["crossroads"] = crossroadsSerialized;

    // Create nullbuffer
    NullBuffer null_buffer;
    std::ostream null_stream(&null_buffer);

    // Create log container
    std::vector<nlohmann::json> logs;

    // Loop while there are still vehicles
    // in the simulation
    while (countVehicles() > 0) {
        // Compute the current time and check if we should still
        // be running the simulation. We have a stopAt parameter for tests
        // using the Vehicle Generator feature.
        double currentTime = timestamp * gSimTime;
        if (stopAt != 0 && currentTime > stopAt) break;

        logs.push_back(dumpState());

        // Loop over all roads
        for (Road* road : roads) {
            // Tick all entities on the road
            // we have these methods on the Simulation class as they control 
            // the general flow of the simulation, not the road itself.
            road->tick(null_stream);
        }


        // Increment relative 
        timestamp++;
    }

    // Set logs on master object
    j["logs"] = logs;

    // Grab the template
    std::ifstream ifs("../visualizer.html");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

    // Make sure the template was loaded correctly
    ASSERT(content.length() > 0, "Failed to read visualizer template");

    // Split file into header and footer
    int pos = content.find("{}");
    std::string header = content.substr(0, pos);
    std::string footer = content.substr(pos + 2, content.length());

    fileStream << header << std::setw(4) << j << footer << std::endl;
    fileStream.flush();
}