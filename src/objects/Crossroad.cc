/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 13th April 2022 4:11:12 pm
 */

#include "Crossroad.h"
#include "Road.h"
#include "../lib/DesignByContract.h"

int Crossroad::getPositionForRoad(Road* road) const {
    REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    REQUIRE(road != nullptr, "Road can not be nullptr");
    REQUIRE(road == details.first->road || road == details.second->road, "Road must be part of crossroad");

    if (details.first->road == road) return details.first->position;
    else return details.second->position;
}

Crossroad::Crossroad(CrossroadDetails* details1, CrossroadDetails* details2) : details({details1, details2}) {
    REQUIRE(details1 != nullptr, "Crossroad can not be nullptr");
    REQUIRE(details2 != nullptr, "Crossroad can not be nullptr");
    REQUIRE(details1->road != nullptr, "Road can not be nullptr");
    REQUIRE(details2->road != nullptr, "Road can not be nullptr");
    REQUIRE(details1->position >= 0, "Position must be positive");
    REQUIRE(details2->position >= 0, "Position must be positive");
    REQUIRE(details1->road->getLength() >= details1->position, "Position must be within road bounds");
    REQUIRE(details2->road->getLength() >= details2->position, "Position must be within road bounds");

    _init = this;

    ENSURE(properlyInitialized(), "_init reference must be set");
}

std::pair<CrossroadDetails*, CrossroadDetails*> Crossroad::getDetails() const {
    REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    return details;
}
