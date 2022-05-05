/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 13th April 2022 4:11:12 pm
 */

#ifndef PSE_TRAFFIC_SIM_CROSSROAD_H
#define PSE_TRAFFIC_SIM_CROSSROAD_H


#include <utility>
#include <string>

class Road;
struct CrossroadDetails {
    Road* road;
    int position;
};

class Crossroad {
private:
    std::pair<CrossroadDetails*, CrossroadDetails*> details;

    Crossroad* _init;
public:
    /**
    \n REQUIRE(details1 != nullptr, "Crossroad can not be nullptr");
    \n REQUIRE(details2 != nullptr, "Crossroad can not be nullptr");
    \n REQUIRE(details1.road != nullptr, "Road can not be nullptr");
    \n REQUIRE(details2.road != nullptr, "Road can not be nullptr");
    \n REQUIRE(details1.position >= 0, "Position must be positive");
    \n REQUIRE(details2.position >= 0, "Position must be positive");
    \n REQUIRE(details1.road->getLength() >= details1.position, "Position must be within road bounds");
    \n REQUIRE(details2.road->getLength() >= details2.position, "Position must be within road bounds");
    \n ENSURE(properlyInitialized(), "_init reference must be set");
    */
    Crossroad(CrossroadDetails* details1, CrossroadDetails* details2);

    /**
    \n REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly when calling destructor");
    */
    ~Crossroad() {
        delete details.first;
        delete details.second;
    }

    /**
    \n REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    \n REQUIRE(road != nullptr, "Road cannot be nullptr");
    \n REQUIRE(road == details.first->road || road == details.second->road, "Road must be part of crossroad");
    */
    int getPositionForRoad(Road* road) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    */
    std::pair<CrossroadDetails*, CrossroadDetails*> getDetails() const;

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
