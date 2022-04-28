#ifndef PSE_TRAFFIC_SIM_CROSSROAD_H
#define PSE_TRAFFIC_SIM_CROSSROAD_H


#include <utility>
#include <string>

class Road;
struct CrossRoadDetails {
    Road* road;
    int position;
};

class CrossRoad {
    std::pair<CrossRoadDetails, CrossRoadDetails> details;

public:
    CrossRoad(CrossRoadDetails details1, CrossRoadDetails details2) : details({details1, details2}) {};
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
