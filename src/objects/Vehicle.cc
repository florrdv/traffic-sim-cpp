#include "Vehicle.h"

const std::string &Vehicle::getRoad() const {
    return road;
}

void Vehicle::setRoad(const std::string &r) {
    Vehicle::road = r;
}

int Vehicle::getPosition() const {
    return position;
}

void Vehicle::setPosition(int p) {
    Vehicle::position = p;
}