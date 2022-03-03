#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include <string>
#include <vector>
#include "objects/Road.h"

class Simulation {
private:
    std::vector<Road*> roads;
public:
    void addRoad(Road* r);
};


#endif //TRAFFICSIM_SIMULATION_H
