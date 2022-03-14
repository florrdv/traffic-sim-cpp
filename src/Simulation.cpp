#include "Simulation.h"

#include <iostream>
#include <chrono>
#include <thread>

#include "./data/Constants.cc"

void Simulation::addRoad(Road* r) {
    roads.push_back(r);
}

Road* Simulation::findRoad(const std::string& roadName) {
    for (Road* r : roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

void Simulation::writeOn(std::ostream& onStream) {
    int timestamp = 0;
    bool done = false;

    // TODO: fix dat de laatste iteration geen time cout
    while (!done) {
        done = true;
        onStream << "-------------------------------------------" << std::endl;
        onStream << "Time: T+ " << timestamp * SIM_TIME << "s" << std::endl;
        for (Road* road : roads) {
            std::vector<Vehicle*> vehicles = road->getVehicles();
            if (!vehicles.empty()) done = false;

            for (Vehicle* vehicle : vehicles) vehicle->tick(road->getLeadingVehicle(vehicle));
            road->cleanup();

            for (Vehicle* vehicle : vehicles) {
                onStream << "Vehicle " << vehicle->getId() << std::endl;
                onStream << "-> Road: " << road->getName() << std::endl;
                onStream << "-> Position: " << vehicle->getPosition() << std::endl;
                onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
            }
        }
        timestamp++;
        std::this_thread::sleep_for(std::chrono::milliseconds((int) (SIM_TIME * 1000 / SPEEDUP)));
    }
}
