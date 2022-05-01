#include "Crossroad.h"
#include "../lib/DesignByContract.h"

int Crossroad::getPositionForRoad(Road* road) {
    REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");

    if (details.first.road == road) return details.first.position;
    if (details.second.road == road) return details.second.position;
    
    ENSURE(false, "Requested road not found");
}