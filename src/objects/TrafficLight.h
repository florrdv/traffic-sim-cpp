#ifndef TRAFFICSIM_TRAFFICLIGHT_H
#define TRAFFICSIM_TRAFFICLIGHT_H

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains traffic light class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <string>
#include "Entity.h"

class TrafficLight: public Entity {
private:
    TrafficLight* _init;

    int cycle{};
    bool green=false;

    int cycleCount = 0;

public:
    // Constructors / destructors
    TrafficLight(double position): Entity(position) { _init = this; }

    // Regular methods

    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    */
    int getCycle() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    \n ENSURE(c>0, "Traffic light cycle must be strictly positive");
    */
    void setCycle(int cycles);
    
    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    */
    int getCycleCount() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    \n ENSURE(c>=0, "Traffic light cycle must be positive");
    */
    void setCycleCount(int cycleCount);

    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    */
    bool isGreen() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized properly");
    */
    void toggle();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
