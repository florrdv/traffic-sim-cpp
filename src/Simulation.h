#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include <string>
#include <vector>
#include "objects/Road.h"

class Simulation {
private:
    std::vector<Road*> roads;
public:
    Simulation() {};
    void addRoad(Road* r);
    Road* findRoad(const std::string& roadName);
};


#endif //TRAFFICSIM_SIMULATION_H
