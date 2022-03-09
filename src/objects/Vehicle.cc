#include "Vehicle.h"

int Vehicle::getPosition() const {
    return position;
}

void Vehicle::setPosition(int p) {
    Vehicle::position = p;
}