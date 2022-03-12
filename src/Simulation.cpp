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

void Simulation::writeOn(std::ostream& onStream, int timestamp) {
    // SHOULD BE DIFFERENT BREAK STATEMENT
    if (timestamp>2) return;
    double speed = 16.6; //HARDCODED FOR NOW
    onStream << "Time: " << timestamp << std::endl;
    for (Road* r: roads) {
        int vehicleNumber = 0;
        for (Vehicle* v: r->getVehicles()) {
            onStream << "Vehicle " << vehicleNumber << std::endl;
            onStream << "-> Road: " << r->getName() << std::endl;
            onStream << "-> Position: " << v->getPosition() << std::endl;
            onStream << "-> Speed: " << speed << std::endl;
            vehicleNumber++;
        }
    }
    timestamp++;
    writeOn(onStream, timestamp);
}
