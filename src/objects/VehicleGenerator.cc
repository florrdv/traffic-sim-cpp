#include "VehicleGenerator.h"
#include "../lib/DesignByContract.h"


int VehicleGenerator::getFrequency() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequency;
}


void VehicleGenerator::setFrequency(int frequency_) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    ENSURE(frequency_ >0, "Vehicle generator frequency must be strictly positive");
    frequency = frequency_;
}

int VehicleGenerator::getFrequencyCount() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequencyCount;
}

void VehicleGenerator::setFrequencyCount(int count) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    ENSURE(count >= 0, "Vehicle generator frequency count must be positive");
    frequencyCount = count;
}


VehicleType VehicleGenerator::getType() const {
    return type;
}