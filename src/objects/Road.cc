//============================================================================
// Name        : Road.cc
// Author      : Achraf Yandouzi, Flor Ronsmans De Vry
// Description : Road
//============================================================================

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

void Road::setVehicles(const Vehicle &v) {
    vehicles.push_back(v);
}

const std::vector<TrafficLight *> &Road::getTrafficlights() const {
    return trafficlights;
}

void Road::setTrafficlights(const std::vector<TrafficLight *> &l) {
    Road::trafficlights = l;
}
