/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:38 pm
 */

#include "Vehicle.h"
#include "../lib/DesignByContract.h"

int Vehicle::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");

    return position;
}

void Vehicle::setPosition(int p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    
    Vehicle::position = p;
}

void Vehicle::tick() {

}