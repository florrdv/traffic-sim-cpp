#include "Simulation.h"
#include <iostream>

void Simulation::addRoad(Road *r) {
    roads.push_back(r);
}

Road *Simulation::findRoad(const std::string& roadName) {
    for (Road* r: roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

void Simulation::writeOn(std::ostream& onStream) {
    onStream << "Printing simulation..." << std::endl;
    onStream << "[TO BE IMPLEMENTED]" << std::endl;
    onStream << "Time: " << timestamp << std::endl;
}
