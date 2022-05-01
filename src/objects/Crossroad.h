#ifndef PSE_TRAFFIC_SIM_CROSSROAD_H
#define PSE_TRAFFIC_SIM_CROSSROAD_H


#include <utility>
#include <string>

class Road;
struct CrossroadDetails {
    Road* road;
    int position;

    CrossroadDetails(Road *r, int p) : road(r), position(p) {}
};

class Crossroad {
    std::pair<CrossroadDetails, CrossroadDetails> details;

public:
    Crossroad(CrossroadDetails details1, CrossroadDetails details2) : details({details1, details2}) {};
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
