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



int TrafficLight::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return position;
}


void TrafficLight::setPosition(int p) {
    REQUIRE(this->properlyInitialized(), "TrafficLight was not properly initialized");
    ENSURE(p>=0, "Traffic light position must be positive");
    TrafficLight::position = p;
}

int TrafficLight::getCycle() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return cycle;
}


void TrafficLight::setCycle(int c) {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    ENSURE(c>0, "Traffic light cycle must be strictly positive");
    TrafficLight::cycle = c;
}


void TrafficLight::toggle() {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    green = !green;
}


bool TrafficLight::isGreen() const {
    REQUIRE(this->properlyInitialized(), "Traffic light was not properly initialized");
    return green;
}

void TrafficLight::setCycleCount(int count) {
    cycleCount = count;
};

int TrafficLight::getCycleCount() const {
    return cycleCount;
};