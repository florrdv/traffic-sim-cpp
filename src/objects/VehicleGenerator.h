#ifndef TRAFFICSIM_VEHICLEGENERATOR_H
#define TRAFFICSIM_VEHICLEGENERATOR_H

#include <iostream>
#include "Entity.h"
#include "Vehicle.h"

class VehicleGenerator: public Entity {
private:
    VehicleGenerator* _init;

    VehicleType vehicleType;
    int frequency{};
    int frequencyCount = 0;

public:
    // Constructors / destructors
    VehicleGenerator(int freq, VehicleType t): Entity(0.0), vehicleType(t), frequency(freq) {_init = this;}

    // General methods
    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    int getFrequency() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(frequency_ >0, "Vehicle generator frequency must be strictly positive");
    */
    void setFrequency(int frequency_);

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    int getFrequencyCount() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(count >=0, "Vehicle generator frequency count must be positive");
    */
    void setFrequencyCount(int count);

    // Safety specific
    bool properlyInitialized() const {return _init == this;}

};


#endif //TRAFFICSIM_VEHICLEGENERATOR_H
