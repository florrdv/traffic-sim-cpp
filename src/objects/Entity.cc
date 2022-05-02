#include "Entity.h"
#include "../lib/DesignByContract.h"

Entity::Entity(double p) {
    ENSURE(p>=0, "Entity position cannot be a negative integer");
    
    position = p;
    _init = this;
}

double Entity::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Entity was not properly initialized");
    return position;
}

void Entity::setPosition(double p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    ENSURE(p>=0, "Entity position must be a positive double");
    position = p;
    ENSURE(position == p, "Position was not set properly");
}