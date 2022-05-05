/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 10th March 2022 5:12:46 pm
 */

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_

#include <gtest/gtest_prod.h>

class Entity {
    FRIEND_TEST(EntityTests, EntityGenerationHappyDay);
    FRIEND_TEST(EntityTests, EntityGenerationNegativePosition);
    FRIEND_TEST(EntityTests, PositionMutationHappyDay);
    FRIEND_TEST(EntityTests, PositionMutationNegative);
    FRIEND_TEST(EntityTests, GetSetPosition);
private:
    Entity* _init;

    double position = 0;

protected:
    /**
    \n REQUIRE(p>=0, "Entity position cannot be a negative integer")
    \n ENSURE(properlyInitialized(), "_init reference must be set");
    */
    Entity(double p);

public:
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n REQUIRE(p>=0, "Entity position cannot be a negative integer");
    \n ENSURE(std::abs(position - p) < std::numeric_limits<double>::epsilon(), "Position was not set properly");
    */
    void setPosition(double p);

    /**
    \n REQUIRE(this->properlyInitialized(), "Entity wasn't initialized properly");
    */
    double getPosition() const;

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_
