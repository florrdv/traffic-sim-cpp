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

class TrafficLight {
private:
    TrafficLight* _init;

    int position{};
    int cycle{};
    bool green=false;

public:
    // Constructors / destructors
    TrafficLight() { _init = this; }

    // Regular methods
/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
    int getPosition() const;
/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
\n ENSURE(p>=0, "Traffic light position must be positive");
*/
    void setPosition(int position);

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
    int getCycle() const;

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
\n ENSURE(c>=0, "Traffic light cycle must be strictly positive");
*/
    void setCycle(int cycles);

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
    bool isGreen() const;

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
    void toggle();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
