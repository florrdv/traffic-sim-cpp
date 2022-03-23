#ifndef TRAFFICSIM_VEHICLEGENERATOR_H
#define TRAFFICSIM_VEHICLEGENERATOR_H

#include <iostream>

class VehicleGenerator {
private:
    VehicleGenerator* _init;

    int frequency{};
    int frequencyCount = 0;
    double position{};

public:
    // Constructors / destructors
    VehicleGenerator() {_init = this;}

    // General methods
    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    int getFrequency() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(frequency_ >0, "Vehicle generator frequence must be strictly positive");
    */
    void setFrequency(int frequency_);

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    */
    int getFrequencyCount() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "VehicleGenerator was not properly initialized");
    \n ENSURE(count >=0, "Vehicle generator frequence must be positive");
    */
    void setFrequencyCount(int count);

    // Safety specific
    bool properlyInitialized() const {return _init == this;}

};


#endif //TRAFFICSIM_VEHICLEGENERATOR_H
