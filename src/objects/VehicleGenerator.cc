#include "VehicleGenerator.h"
#include "../lib/DesignByContract.h"

int VehicleGenerator::getFrequency() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequency;
}

void VehicleGenerator::setFrequency(int frequency_) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    frequency = frequency_;
}
