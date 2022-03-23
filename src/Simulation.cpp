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



Simulation::Simulation() {
    _init = this;
    ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
}


Simulation::~Simulation() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    for (Road* road : roads) delete road;
}


void Simulation::addRoad(Road* r) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
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


void Simulation::writeOn(std::ostream& onStream, const double stopAt) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");

    int timestamp = 0;
    int cycleCounter = 0;
    int freqCounter = 0;

    while (countVehicles() > 0) {
        double currentTime = timestamp * SIM_TIME;
        if (stopAt != 0 && currentTime > stopAt) return;

        onStream << "-------------------------------------------" << std::endl;
        onStream << "Time: T+ " << currentTime << "s" << std::endl;
        for (Road* road : roads) {
            VehicleGenerator* generator = road->getGenerator();
            if (generator != nullptr && freqCounter * SIM_TIME > generator->getFrequency()) {
                Vehicle* v = new Vehicle;
                v->setPosition(0);
                road->addVehicle(v);
                freqCounter = 0;
            }
            std::vector<TrafficLight*> trafficLights = road->getTrafficLights();
            std::vector<Vehicle*> vehicles = road->getVehicles();
            for (TrafficLight* trafficLight : trafficLights) {
                if (cycleCounter * SIM_TIME > trafficLight->getCycle()) {
                    trafficLight->toggle();
                    cycleCounter = 0;
                }

                Vehicle* firstVehicle = road->getFirstToTrafficLight(trafficLight);
                if (firstVehicle == nullptr) continue;
                if (trafficLight->isGreen()) firstVehicle->accelerate();
                else {
                    double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

                    if (distanceToLight < BRAKE_DISTANCE) firstVehicle->stop();
                    else if (distanceToLight < DECELERATION_DISTANCE) firstVehicle->decelerate();
                }
            }

            for (Vehicle* vehicle : vehicles) {
                vehicle->tick(road->getLeadingVehicle(vehicle));
                onStream << "Vehicle " << vehicle->getId() << std::endl;
                onStream << "-> Road: " << road->getName() << std::endl;
                onStream << "-> Position: " << vehicle->getPosition() << std::endl;
                onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
            }
            road->cleanup();
        }
        timestamp++;
        cycleCounter++;
        freqCounter++;
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(SIM_TIME * 1000 / SPEEDUP)));
    }
}


std::vector<Road*> Simulation::getRoads() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    return roads;
}
