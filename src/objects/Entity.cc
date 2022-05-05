/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 10th March 2022 5:12:46 pm
 */

#include <algorithm>
#include <limits>
#include "Entity.h"
#include "../lib/DesignByContract.h"

Entity::Entity(double p) {
    REQUIRE(p>=0, "Entity position cannot be a negative integer");
    
    position = p;
    _init = this;

    ENSURE(properlyInitialized(), "_init reference must be set");
}

double Entity::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Entity was not properly initialized");
    return position;
}

void Entity::setPosition(double p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    REQUIRE(p>=0, "Entity position must be a positive double");
    position = p;

    ENSURE(std::abs(position - p) < std::numeric_limits<double>::epsilon(), "Position was not set properly");
}