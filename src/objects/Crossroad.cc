#include "Crossroad.h"
#include "../lib/DesignByContract.h"

int Crossroad::getPositionForRoad(Road* road) {
    REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");

    if (details.first.road == road) return details.first.position;
    if (details.second.road == road) return details.second.position;
    
    ENSURE(false, "Requested road not found");
}

Crossroad::Crossroad(CrossroadDetails details1, CrossroadDetails details2) : details({details1, details2}) {
    ENSURE(details1.road != nullptr, "Road can not be nullptr");
    ENSURE(details2.road != nullptr, "Road can not be nullptr");
    ENSURE(details1.position >= 0, "Position must be positive");
    ENSURE(details2.position >= 0, "Position must be positive");

    _init = this;
}
