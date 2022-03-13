#include "Simulation.h"

#include <iostream>
#include <chrono>
#include <thread>

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
    while (true) {
        double speed = 16.6; //HARDCODED FOR NOW
        onStream << "Time: " << timestamp << std::endl;
        for (Road* road : roads) {
            int vehicleNumber = 0;
            for (Vehicle* vehicle : road->getVehicles()) {
                vehicle->tick(road->getLeadingVehicle(vehicle));
                onStream << "Vehicle " << vehicleNumber << std::endl;
                onStream << "-> Road: " << road->getName() << std::endl;
                onStream << "-> Position: " << vehicle->getPosition() << std::endl;
                onStream << "-> Speed: " << speed << std::endl;
                vehicleNumber++;
            }
        }
        timestamp++;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
