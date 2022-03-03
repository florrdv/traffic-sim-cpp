#include "Vehicle.h"

const std::string &Vehicle::getRoad() const {
    return road;
}

void Vehicle::setRoad(const std::string &road) {
    Vehicle::road = road;
}

int Vehicle::getPosition() const {
    return position;
}

void Vehicle::setPosition(int position) {
    Vehicle::position = position;
}