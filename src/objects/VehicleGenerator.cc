/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 4th March 2022 3:43:06 pm
 */

#include "VehicleGenerator.h"
#include "../lib/DesignByContract.h"


int VehicleGenerator::getFrequency() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequency;
}


void VehicleGenerator::setFrequency(int f) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    ENSURE(f > 0, "Vehicle generator frequency must be strictly positive");
    frequency = f;
    ENSURE(frequency == f, "Frequency was not set properly");
}

int VehicleGenerator::getFrequencyCount() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequencyCount;
}

void VehicleGenerator::setFrequencyCount(int c) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    ENSURE(c >= 0, "Vehicle generator frequency count must be positive");
    frequencyCount = c;
    ENSURE(frequencyCount == c, "Frequency count was not set properly");
}


VehicleType VehicleGenerator::getType() const {
    return type;
}

VehicleGenerator::VehicleGenerator(int f, VehicleType t): Entity(0.0), type(t), frequency(f) {
    REQUIRE(f>0, "Frequency must be strictly positive");

    _init = this;
    ENSURE(properlyInitialized(), "_init reference must be set");
}
