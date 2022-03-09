#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include <string>
#include <vector>
#include "objects/Road.h"

class Simulation {
private:
    bool _init = false;

    std::vector<Road*> roads;
public:
    // Constructors / destructors
    Simulation() { _init = true; };
    ~Simulation() {
        for (Road* road : roads) delete road;
    }
    
    // Regular methods
    void addRoad(Road* r);
    Road* findRoad(const std::string& roadName);

    // Safety specific
    bool properlyInitialized() { return _init; }
};


#endif //TRAFFICSIM_SIMULATION_H
