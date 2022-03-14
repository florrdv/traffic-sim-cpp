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

const std::string &Road::getName() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return name;
}

void Road::setName(const std::string &n) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    Road::name = n;
}

int Road::getLength() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return length;
}

void Road::setLength(int l) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    Road::length = l;
}

const std::vector<Vehicle *> &Road::getVehicles() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return vehicles;
}

void Road::addVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    v->setId(vehicles.size());
    vehicles.push_back(v);
}

void Road::addTrafficLight(TrafficLight *t) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    trafficLights.push_back(t);
}

const std::vector<TrafficLight *> &Road::getTrafficlights() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");

    return trafficLights;
}

const std::vector<VehicleGenerator *> &Road::getGenerators() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return generators;
}

void Road::addGenerator(VehicleGenerator *g) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    generators.push_back(g);
}

Vehicle* Road::getLeadingVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    Vehicle* leadingVehicle = nullptr;
    for (Vehicle* candidate : vehicles) { 
        if (candidate->getPosition() <= v->getPosition()) continue;

        if (leadingVehicle == nullptr) leadingVehicle = candidate;
        else if (leadingVehicle->getPosition() - v->getPosition() > candidate->getPosition() - v->getPosition()) leadingVehicle = candidate;
    }

    return leadingVehicle;
}

void Road::cleanup() { 
    std::vector<Vehicle *>::iterator vehicle = vehicles.begin();

    while (vehicle != vehicles.end()) {
        if ((*vehicle)->getPosition() > length) {
            vehicles.erase(vehicle);
        } else ++vehicle;
    }
}