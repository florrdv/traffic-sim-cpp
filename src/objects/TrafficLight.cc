/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains traffic light logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:38 pm
 */

#include "TrafficLight.h"
#include "../lib/DesignByContract.h"


/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
int TrafficLight::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return position;
}

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
\n ENSURE(p>=0, "Traffic light position cannot be a negative integer");
*/
void TrafficLight::setPosition(int p) {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    //TODO: Make sure the position is within the road length
    ENSURE(p>=0, "Traffic light position cannot be a negative integer");
    TrafficLight::position = p;
}

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
int TrafficLight::getCycle() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return cycle;
}

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
\n ENSURE(c>=0, "Traffic light cycle cannot be a negative integer");
*/
void TrafficLight::setCycle(int c) {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    ENSURE(c>=0, "Traffic light cycle cannot be a negative integer");
    TrafficLight::cycle = c;
}

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
void TrafficLight::toggle() {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    green = !green;
}

/**
\n REQUIRE(this->properlyInitialized(), "TrafficLight wasn't initialized when calling writeOn");
*/
bool TrafficLight::isGreen() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return green;
}
