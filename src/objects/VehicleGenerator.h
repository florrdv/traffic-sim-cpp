/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 5th March 2022 3:43:06 pm
 */

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
    /**
    \n REQUIRE(f>0, "Frequency must be strictly positive");
    \n ENSURE(_init == this, "_init reference must be set");
    */
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
