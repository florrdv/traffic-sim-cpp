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
    Crossroad(CrossroadDetails details1, CrossroadDetails details2) : details({details1, details2}) { _init = this; };

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
