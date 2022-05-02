#ifndef PSE_TRAFFIC_SIM_CROSSROAD_H
#define PSE_TRAFFIC_SIM_CROSSROAD_H


#include <utility>
#include <string>

class Road;
struct CrossroadDetails {
    Road* road;
    int position;
};

class Crossroad {
private:
    std::pair<CrossroadDetails, CrossroadDetails> details;

    Crossroad* _init;

    // Safety specific
    bool properlyInitialized() const { return _init == this; }

public:
    /**
    \n REQUIRE(details1.road != nullptr, "Road can not be nullptr");
    \n REQUIRE(details2.road != nullptr, "Road can not be nullptr");
    \n REQUIRE(details1.position >= 0, "Position must be positive");
    \n REQUIRE(details2.position >= 0, "Position must be positive");
    \n REQUIRE(details1.road->getLength() >= details1.position, "Position must be within road bounds");
    \n REQUIRE(details2.road->getLength() >= details2.position, "Position must be within road bounds");
    \n ENSURE(_init == this, "_init reference must be set");
    */
    Crossroad(CrossroadDetails details1, CrossroadDetails details2);

    /**
    \n REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    \n ENSURE(false, "Requested road not found");
    */
    int getPositionForRoad(Road* road);
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
