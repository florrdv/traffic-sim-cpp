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

const std::string &Road::getName() const {
    return name;
}

void Road::setName(const std::string &n) {
    Road::name = n;
}

int Road::getLength() const {
    return length;
}

void Road::setLength(int l) {
    Road::length = l;
}

const std::vector<Vehicle *> &Road::getVehicles() const {
    return vehicles;
}

void Road::addVehicle(Vehicle *v) {
    vehicles.push_back(v);
}

void Road::addTrafficLight(TrafficLight *t) {
    trafficLights.push_back(t);
}

const std::vector<TrafficLight *> &Road::getTrafficlights() const {
    return trafficLights;
}