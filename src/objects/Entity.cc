#include "Entity.h"
#include "../lib/DesignByContract.h"

/**
\n REQUIRE(this->properlyInitialized(), "Entity was not properly initialized");
*/
double Entity::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Entity was not properly initialized");
    return position;
}

/**
\n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
\n ENSURE(p>=0, "Entity position cannot be a negative integer");
*/
void Entity::setPosition(double p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    ENSURE(p>=0, "Entity position must be a positive integer");
    position = p;
}