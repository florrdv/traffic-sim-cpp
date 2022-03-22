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
#include "lib/DesignByContract.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>


 /**
 \n ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
 */
Simulation::Simulation() {
    _init = this;
    ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
}

/**
\n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
*/
Simulation::~Simulation() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    for (Road* road : roads) delete road;
}

/**
\n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
\n ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
*/
void Simulation::addRoad(Road* r) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    roads.push_back(r);
    ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
}

/**
\n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling roadName");
*/
Road* Simulation::findRoad(const std::string& roadName) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling findRoad");
    for (Road* r : roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

/**
\n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");
\n ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
*/
int Simulation::countVehicles() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");
    int amount = 0;
    for (Road* road : roads) amount += road->getVehicles().size();
    ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    return amount;
}

void Simulation::tickVehicleGenerators(Road* road) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");

    // If there's a generator running on the road and the cycle time 
    // has been exceeded, spawn a new vehicle
    VehicleGenerator* generator = road->getGenerator();

    bool shouldSpawn = freqCounter * SIM_TIME > generator->getFrequency();
    if (generator != nullptr && shouldSpawn) {
        road->spawnVehicle();
        freqCounter = 0;
    }

    freqCounter++;
}

void Simulation::tickTrafficLights(Road* road) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    
    // Get all traffic lights on the road
    std::vector<TrafficLight*> trafficLights = road->getTrafficLights();

    // Loop over all traffic lights
    for (TrafficLight* trafficLight : trafficLights) {
        // Check if we have to toggle the light
        bool shouldToggle = cycleCounter * SIM_TIME > trafficLight->getCycle(); 
        if (shouldToggle) {
            trafficLight->toggle();
            cycleCounter = 0;
        }

        // Get the first vehicle relative to the traffic light
        // To make vehicles decelerate or stop, we just need to perform the action
        // on the first vehicle driving towards the traffic light.
        Vehicle* firstVehicle = road->getFirstToTrafficLight(trafficLight);
        // No vehicles are driving towards the traffic light, continue to the next traffic light
        if (firstVehicle == nullptr) continue;

        // If the traffic light is green, all vehicles should accelerate
        if (trafficLight->isGreen()) firstVehicle->accelerate();
        else {
            // The light is red, let's check how far away the first vehicle
            // is from the traffic light
            double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

            // Stop the vehicle if it's in the braking zone
            if (distanceToLight < BRAKE_DISTANCE) firstVehicle->stop();
            // Force the vehicle to decelerate if it's in the deceleration zone
            else if (distanceToLight < DECELERATION_DISTANCE) firstVehicle->decelerate();
        }
    }

    cycleCounter++;
}

void Simulation::tickVehicles(Road* road, std::ostream& onStream) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");

    // Get all vehicles on the road
    std::vector<Vehicle*> vehicles = road->getVehicles();

    // Loop over all vehicles
    for (Vehicle* vehicle : vehicles) {
        // Tick the relevant vehicle
        vehicle->tick(road->getLeadingVehicle(vehicle));

        // Print all information on the vehicle in 
        // the requested format
        onStream << "Vehicle " << vehicle->getId() << std::endl;
        onStream << "-> Road: " << road->getName() << std::endl;
        onStream << "-> Position: " << vehicle->getPosition() << std::endl;
        onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
    }
}

/**
\n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
*/
void Simulation::writeOn(std::ostream& onStream, const double stopAt) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");

    // Loop while there are still vehicles
    // in the simulation
    while (countVehicles() > 0) {
        // Compute the current time and check if we should still
        // be running the simulation. We have a stopAt parameter for tests
        // using the Vehicle Generator feature.
        double currentTime = timestamp * SIM_TIME;
        if (stopAt != 0 && currentTime > stopAt) return;

        // Print the log entry header
        onStream << "-------------------------------------------" << std::endl;
        onStream << "Time: T+ " << currentTime << "s" << std::endl;

        // Loop over all roads
        for (Road* road : roads) {
            // Tick all entities on the road
            // we have these methods on the Simulation class as they control 
            // the general flow of the simulation, not the road itself.
            tickVehicleGenerators(road);
            tickTrafficLights(road);
            tickVehicles(road, onStream);

            road->cleanup();
        }

        // Increment relative 
        timestamp++;

        // Sleep until the next simulation tick
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(SIM_TIME * 1000 / SPEEDUP)));
    }
}


std::vector<Road*> Simulation::getRoads() const {
    return roads;
}
