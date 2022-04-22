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
#include <gtest/gtest_prod.h>

class Simulation {
    FRIEND_TEST(SimulationTests, CountVehiclesHappyDay);
    FRIEND_TEST(SimulationTests, WriteOnHappyDay);

private:
    Simulation* _init; //!use pointer to myself to verify whether I am properly initialized

    std::vector<Road*> roads;
    int timestamp = 0;

    /**
    \n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    int countVehicles();
public:
    /**
    \n REQUIRE(gSpeedMax > 0, "gSpeedMax must be strictly positive");
    \n REQUIRE(gAccelerationMax > 0, "gAccelerationMax must be strictly positive");
    \n REQUIRE(gBrakeMax > 0, "gBrakeMax must be strictly positive");
    \n REQUIRE(gBrakeDistance >= 0, "gBrakeDistance must be positive");
    \n REQUIRE(gFollowMin >= 0, "gFollowMin must be positive");
    \n REQUIRE(gSimTime > 0, "gSimTime must be strictly positive");
    \n REQUIRE(gDecelerationDistance >= 0, "gDecelerationDistance must be positive");
    \n REQUIRE(gDecelerationFactor > 0, "gDecelerationFactor must be strictly positive");
    \n ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    Simulation();
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    */
    ~Simulation();

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    \n ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
    */
    void addRoad(Road* r);

    /**
    \n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    Road* findRoad(const std::string& roadName);

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    */
    std::vector<Road*> getRoads() const;

    /**
    \n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    void writeOn(std::ostream& onStream, const double stopAt = 0.0, int speedup = 1);

    // Safety specific
    bool properlyInitialized() const { return _init == this; }

};

// Closing of the ``header guard''.
#endif
