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
#include "../lib/DesignByContract.h"

#include <cmath>
#include <iostream>

double Vehicle::getLength() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return length;
}

double Vehicle::getSpeed() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return speed;
}

int Vehicle::getId() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return id;
}

void Vehicle::setId(int id_) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    ENSURE(id_ >= 0, "Vehicle ID cannot be a negative integer");
    Vehicle::id = id_;
    ENSURE(Vehicle::id == id_, "Vehicle ID was not set properly");
}

VehicleType Vehicle::getType() const {
    return type;
}

void Vehicle::updateSpeed() {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    double newSpeed = speed + acceleration * simTime;
    if (newSpeed < 0) {
        setPosition(getPosition() - std::pow(speed, 2) / (2 * acceleration));
        speed = 0.0;
    } else {
        speed = newSpeed;
        setPosition(getPosition() + speed * simTime + acceleration * std::pow(simTime, 2) / 2);
    }
    ENSURE(speed >= 0, "Vehicle speed must be positive");
}

void Vehicle::updateAcceleration(Vehicle *leadingVehicle) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    double delta = 0;
    if (leadingVehicle != nullptr) {
        double followDistance = leadingVehicle->getPosition() - getPosition() - leadingVehicle->getLength();
        double speedDifference = speed - leadingVehicle->getSpeed();

        delta = (followMin +
                 std::max(0.0, speed + speed * speedDifference / (2 * std::sqrt(accelerationMax * brakeMax)))) /
                followDistance;
    }
    acceleration = accelerationMax * (1 - std::pow(speed / speedMax, 4)) - delta * delta;
    ENSURE(acceleration <= accelerationMax, "Vehicle acceleration cannot be greater than max acceleration");
}

void Vehicle::tick(Vehicle *leadingVehicle) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    updateSpeed();
    updateAcceleration(leadingVehicle);
}

void Vehicle::stop() {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    acceleration = -brakeMax * speed / speedMax;
}

void Vehicle::decelerate() {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    speedMax = decelerationFactor * speedMaxLimit;
}

void Vehicle::accelerate() {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    speedMax = speedMaxLimit;
}

double Vehicle::getAcceleration() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return acceleration;
}

double Vehicle::getDecelerationFactor() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return decelerationFactor;
}

double Vehicle::getSpeedMax() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    return speedMax;
}

Vehicle::Vehicle(double position, VehicleType t) : Entity(position), type(t) {
    REQUIRE(position >= 0, "Position has to be positive");
    
    VehicleConstant constants = gVehicleConstants.at(t);
    length = constants.gVehicleLength;
    speedMax = constants.gSpeedMax;
    speedMaxLimit = constants.gSpeedMax;
    accelerationMax = constants.gAccelerationMax;
    brakeMax = constants.gBrakeMax;
    followMin = constants.gFollowMin;
    simTime = gSimTime;
    decelerationDistance = gDecelerationDistance;
    decelerationFactor = gDecelerationFactor;

    _init = this;
    ENSURE(_init == this, "_init reference must be set");
}