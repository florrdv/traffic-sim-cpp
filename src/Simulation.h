/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: 
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 1st March 2022 10:27:21 pm
 */


// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include "objects/Road.h"

#include <string>
#include <vector>

class Simulation {
private:
    Simulation* _init; //!use pointer to myself to verify whether I am properly initialized

    std::vector<Road*> roads;

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");
    \n ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    */
    int countVehicles();
public:
    /**
    \n ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    Simulation();
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    */
    ~Simulation();

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    \n ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
    */
    void addRoad(Road* r);
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling roadName");
    */
    Road* findRoad(const std::string& roadName);

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    */
    std::vector<Road*> getRoads();
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    */
    void writeOn(std::ostream& onStream, const double stopAt = 0.0);

    // Safety specific
    bool properlyInitialized() { return _init == this; }

};

// Closing of the ``header guard''.
#endif
