#include "VehicleGenerator.h"
#include "../lib/DesignByContract.h"

/**
\n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
*/
int VehicleGenerator::getFrequency() const {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    return frequency;
}

/**
\n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
\n ENSURE(frequency_ >0, "Vehicle generator frequence must be strictly greater than 0");
*/
void VehicleGenerator::setFrequency(int frequency_) {
    REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    ENSURE(frequency_ >0, "Vehicle generator frequence must be strictly greater than 0");
    frequency = frequency_;
}