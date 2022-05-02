#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_

#include <gtest/gtest_prod.h>

class Entity {
    FRIEND_TEST(EntityTests, PositionMutationHappyDay);
    FRIEND_TEST(EntityTests, PositionMutationNegative);
    FRIEND_TEST(EntityTests, GetSetPosition);
private:
    Entity* _init;

    double position{};

    // Safety specific
    bool properlyInitialized() const { return _init == this; }

protected:
    /**
    \n ENSURE(p>=0, "Entity position cannot be a negative integer")
    */
    Entity(double p);

public:
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(p>=0, "Entity position cannot be a negative integer");
    \n ENSURE(position == p, "Position was not set properly");
    */
    void setPosition(double p);

    /**
    \n REQUIRE(this->properlyInitialized(), "Entity wasn't initialized properly");
    */
    double getPosition() const;


};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_
