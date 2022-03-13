/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:38 pm
 */

#include "Vehicle.h"

#include <cmath>

#include "../lib/DesignByContract.h"

double Vehicle::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");

    return position;
}

void Vehicle::setPosition(int p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");

    Vehicle::position = p;
}

double Vehicle::getLength() const {
    return length;
}

double Vehicle::getSpeed() const {
    return speed;
}


void Vehicle::updateSpeed() {
    double newSpeed = speed + acceleration * simTime < 0;
    if (newSpeed < 0) position -= speed * speed / (2 * acceleration);
    else {
        speed = newSpeed;
        position += speed * simTime + acceleration * simTime * simTime / 2;
    }
}

void Vehicle::updateAcceleration(Vehicle* leadingVehicle) {
    double delta = 0;
    if (leadingVehicle != nullptr) {
        double followDistance = leadingVehicle->getPosition() - position - leadingVehicle->getLength();
        double speedDifference = speed - leadingVehicle->getSpeed();

            delta = followMin + std::max(0.0, speed + speed * speedDifference / (2 * std::sqrt(accelerationMax * brakeMax)));
    }

    acceleration = accelerationMax * (1 - std::pow(speed / speedMax, 4)) - delta * delta;
}

void Vehicle::tick(Vehicle* leadingVehicle) {
    updateSpeed();
    updateAcceleration(leadingVehicle);
}
