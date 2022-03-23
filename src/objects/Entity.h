#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_

#include <gtest/gtest_prod.h>

class Entity {
    FRIEND_TEST(EntityTests, PositionMutationHappyDay);
    FRIEND_TEST(EntityTests, PositionMutationNegative);
private:
    Entity* _init;

    double position{};

protected:
    // Constructors / destructors
    Entity(double p): position(p) { _init = this; };

    // Regular methods
public:
    /**
    \n REQUIRE(this->properlyInitialized(), "Entity wasn't initialized properly");
    */
    void setPosition(double p);
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(p>=0, "Entity position cannot be a negative integer");
    */
    double getPosition() const;

private:
    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_OBJECTS_ENTITY_H_