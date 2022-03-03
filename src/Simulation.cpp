#include "Simulation.h"

void Simulation::addRoad(Road *r) {
    roads.push_back(r);
}

Road *Simulation::findRoad(string roadName) {
    for (Road* r: roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}
