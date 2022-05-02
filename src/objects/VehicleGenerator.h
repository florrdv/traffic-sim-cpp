#ifndef TRAFFICSIM_VEHICLEGENERATOR_H
#define TRAFFICSIM_VEHICLEGENERATOR_H

#include <iostream>
#include "Entity.h"
#include "Vehicle.h"

class VehicleGenerator: public Entity {
private:
    VehicleGenerator* _init;

    VehicleType type;
    int frequency{};
    int frequencyCount = 0;

public:
    // Constructors / destructors
    VehicleGenerator(int f, VehicleType t);
    // General methods
    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(_init == this, "_init reference must be set");
    */
    int getFrequency() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(f >0, "Vehicle generator frequency must be strictly positive");
    \n ENSURE(frequency == f, "Frequency was not set properly");
    */
    void setFrequency(int f);

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    int getFrequencyCount() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    VehicleType getType() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(c >=0, "Vehicle generator frequency c must be positive");
    \n ENSURE(frequencyCount == c, "Frequency count was not set properly");
    */
    void setFrequencyCount(int c);

    // Safety specific
    bool properlyInitialized() const {return _init == this;}

};


#endif //TRAFFICSIM_VEHICLEGENERATOR_H
