#include "Entity.h"
#include "../lib/DesignByContract.h"

Entity::Entity(double p) {
    REQUIRE(p>=0, "Entity position cannot be a negative integer");
    
    position = p;
    _init = this;

    ENSURE(_init == this, "_init reference must be set");
}

double Entity::getPosition() const {
    REQUIRE(this->properlyInitialized(), "Entity was not properly initialized");
    return position;
}

void Entity::setPosition(double p) {
    REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    REQUIRE(p>=0, "Entity position must be a positive double");
    position = p;
    ENSURE(position == p, "Position was not set properly");
}