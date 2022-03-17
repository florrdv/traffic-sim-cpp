/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#include "Road.h"
#include "../lib/DesignByContract.h"

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
const std::string& Road::getName() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return name;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::setName(const std::string& n) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    Road::name = n;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
int Road::getLength() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return length;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::setLength(int l) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    Road::length = l;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
const std::vector<Vehicle*>& Road::getVehicles() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return vehicles;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::addVehicle(Vehicle* v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    v->setId(vehicles.size());
    vehicles.push_back(v);
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::addTrafficLight(TrafficLight* t) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    trafficLights.push_back(t);
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
const std::vector<TrafficLight*>& Road::getTrafficlights() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return trafficLights;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
const std::vector<VehicleGenerator*>& Road::getGenerators() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return generators;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::addGenerator(VehicleGenerator* g) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    generators.push_back(g);
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
Vehicle* Road::getLeadingVehicle(Vehicle* v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    Vehicle* leadingVehicle = nullptr;
    for (Vehicle* candidate : vehicles) {
        if (candidate->getPosition() <= v->getPosition()) continue;

        if (leadingVehicle == nullptr) leadingVehicle = candidate;
        else if (leadingVehicle->getPosition() - v->getPosition() > candidate->getPosition() - v->getPosition()) leadingVehicle = candidate;
    }

    return leadingVehicle;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Road::cleanup() {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    std::vector<Vehicle*>::iterator vehicle = vehicles.begin();

    while (vehicle != vehicles.end()) {
        if ((*vehicle)->getPosition() > length) {
            vehicles.erase(vehicle);
        } else ++vehicle;
    }
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
Vehicle* Road::getFirstToTrafficLight(TrafficLight* t) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    int trafficLightPosition = t->getPosition();
    Vehicle* firstVehicle = nullptr;
    for (Vehicle* vehicle : vehicles) {
        double distanceToLight = ((double)trafficLightPosition) - vehicle->getPosition();
        if (firstVehicle == nullptr) {
            if (distanceToLight > 0) firstVehicle = vehicle;
            continue;
        }
        
        double previousDistanceToLight = ((double)trafficLightPosition) - firstVehicle->getPosition();

        if (distanceToLight > 0 && distanceToLight && distanceToLight < previousDistanceToLight) firstVehicle = vehicle;
    }
    return firstVehicle;
}
