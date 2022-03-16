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

int Simulation::countVehicles() const {
    int amnt = 0;
    for (Road* road : roads) amnt += road->getVehicles().size();

    return amnt;
}

void Simulation::writeOn(std::ostream& onStream) {
    int timestamp = 0;
    int cycleCounter = 0;

    while (countVehicles() > 0) {
        // onStream << "-------------------------------------------" << std::endl;
        // onStream << "Time: T+ " << timestamp * SIM_TIME << "s" << std::endl;
        for (Road* road : roads) {
            std::vector<TrafficLight*> trafficLights = road->getTrafficlights();
            std::vector<Vehicle*> vehicles = road->getVehicles();
            for (TrafficLight* trafficLight : trafficLights) {
                if (cycleCounter > trafficLight->getCycle()) {
                    trafficLight->toggle();
                    cycleCounter = 0;
                }

                Vehicle* firstVehicle = road->getFirstToTrafficLight(trafficLight);
                if (firstVehicle == nullptr) continue;

                if (trafficLight->isGreen()) firstVehicle->accelerate();
                else {
                    double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

                    if (distanceToLight < DECELERATION_DISTANCE) {
                        if (distanceToLight < BRAKE_DISTANCE) firstVehicle->stop();
                        else firstVehicle->decelerate();
                    }
                }
            }

            for (Vehicle* vehicle : vehicles) {
                vehicle->tick(road->getLeadingVehicle(vehicle));

                // onStream << "Vehicle " << vehicle->getId() << std::endl;
                // onStream << "-> Road: " << road->getName() << std::endl;
                // onStream << "-> Position: " << vehicle->getPosition() << std::endl;
                // onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
            }

            print();

            road->cleanup();
        }
        timestamp++;
        cycleCounter++;
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(SIM_TIME * 1000 / SPEEDUP)));
    }
}

void Simulation::print() {
    int width = roads[0]->getLength();
    TrafficLight* t = roads[0]->getTrafficlights()[0];

    for (int i = 0; i < width; i++) {
        bool p = false;
        if (t->getPosition() == i) {
            if (t->isGreen()) std::cout << "g";
            else std::cout << "r";
            p = true;
        }
        for (auto v : roads[0]->getVehicles()) {

            if (v != nullptr && std::abs(v->getPosition() - i) < 2) {
                std::cout << "v";
            p = true;
            }
        }

        if (!p) std::cout << "-";

    }

    std::cout << std::endl;
}



