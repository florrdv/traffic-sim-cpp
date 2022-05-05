/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: 
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 1st March 2022 10:27:21 pm
 */

#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include "objects/Road.h"
#include "lib/json.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest_prod.h>

class Simulation {
    FRIEND_TEST(SimulationTests, CountVehiclesHappyDay);
    FRIEND_TEST(SimulationTests, WriteOnHappyDay);

private:
    Simulation* _init; //!use pointer to myself to verify whether I am properly initialized

    std::vector<Road *> roads;
    std::vector<Crossroad *> crossroads;
    int timestamp = 0;

    /**
    \n REQUIRE(properlyInitialized(), "constructor must end in properlyInitialized state");
    \n ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    */
    int countVehicles() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");
    */
    nlohmann::json dumpState() const;
public:
    Simulation();
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    */
    ~Simulation();

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    \n REQUIRE(r != nullptr, "Road cannot be nullptr");
    \n REQUIRE(find(roads.begin(), roads.end(), r) == roads.end(), "Cannot add road multiple times");
    \n ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
    */
    void addRoad(Road* r);

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addCrossroad");
    \n REQUIRE(c != nullptr, "Crossroad cannot be nullptr");
    \n REQUIRE(find(crossroads.begin(), crossroads.end(), c) == crossroads.end(), "Crossroad cannot be added multiple times");
    \n ENSURE(find(crossroads.begin(), crossroads.end(), c) != crossroads.end(), "Crossroad wasn't added to roads vector");
    */
    void addCrossroad(Crossroad* c);

    /**
    \n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    Road* findRoad(const std::string& roadName) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    */
    std::vector<Road*> getRoads() const;

    /**
    \n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    void writeOn(std::ostream& onStream, const double stopAt = 0.0, int speedup = 1);

    /**
    \n REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");
    */
    void writeToFile(std::ofstream& fileStream, const double stopAt = 0.0);
    
    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};

// Closing of the ``header guard''.
#endif
