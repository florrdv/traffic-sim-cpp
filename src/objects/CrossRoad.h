#ifndef PSE_TRAFFIC_SIM_CROSSROAD_H
#define PSE_TRAFFIC_SIM_CROSSROAD_H


#include <utility>
#include <string>

class CrossRoad : std::pair<std::pair<std::string, int>, std::pair<std::string, int>> {

public:
    CrossRoad(std::pair<std::string, int> firstIntersection, std::pair<std::string, int> secondIntersection);
};


#endif //PSE_TRAFFIC_SIM_CROSSROAD_H
