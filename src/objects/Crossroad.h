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
    std::pair<CrossroadDetails, CrossroadDetails> details;

    Crossroad* _init;

public:
    /**
    \n ENSURE(details1.road != nullptr, "Road can not be nullptr");
    \n ENSURE(details2.road != nullptr, "Road can not be nullptr");
    \n ENSURE(details1.position >= 0, "Position must be positive");
    \n ENSURE(details2.position >= 0, "Position must be positive");
    */
    Crossroad(CrossroadDetails details1, CrossroadDetails details2);

    /**
    \n REQUIRE(this->properlyInitialized(), "Crossroad wasn't initialized properly");
    \n ENSURE(false, "Requested road not found");
    */
    int getPositionForRoad(Road* road);

private:
    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
