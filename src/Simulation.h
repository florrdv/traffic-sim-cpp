#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include <string>
#include <vector>
#include "objects/Road.h"

class Simulation {
private:
    Simulation* _init;

    std::vector<Road*> roads;
public:
    // Constructors / destructors
    Simulation() { _init = this; };
    ~Simulation() {
        for (Road* road : roads) delete road;
    }

    // Regular methods
    void addRoad(Road* r);
    Road* findRoad(const std::string& roadName);

    void writeOn(std::ostream& onStream, int timestamp=0);

    // Safety specific
    bool properlyInitialized() { return _init == this; }

};


#endif //TRAFFICSIM_SIMULATION_H
