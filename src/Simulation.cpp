// TODO: add fancy header thing

#include "Simulation.h"
#include "lib/DesignByContract.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>


/**
\n ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
*/
Simulation::Simulation() {
    _init = this;
    ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling addRoad");
*/
Simulation::~Simulation() {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling addRoad");
    for (Road* road : roads) delete road;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling addRoad");
\n ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
*/
void Simulation::addRoad(Road* r) {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling addRoad");
    roads.push_back(r);
    ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling roadName");
*/
Road* Simulation::findRoad(const std::string& roadName) {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling roadName");
    for (Road* r : roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling countVehicles");
\n ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
*/
int Simulation::countVehicles() {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling countVehicles");
    int amount = 0;
    for (Road* road : roads) amount += road->getVehicles().size();
    ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    return amount;
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");
*/
void Simulation::writeOn(std::ostream& onStream) {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling writeOn");

    int timestamp = 0;
    int cycleCounter = 0;
    int freqCounter = 0;

    while (countVehicles() > 0) {
         onStream << "-------------------------------------------" << std::endl;
         onStream << "Time: T+ " << timestamp * SIM_TIME << "s" << std::endl;
        for (Road* road : roads) {
            std::vector<VehicleGenerator*> generators = road->getGenerators();
            for (VehicleGenerator* generator: generators) {
                if (freqCounter * SIM_TIME > generator->getFrequency()) {
                    Vehicle * v= new Vehicle;
                    v->setPosition(0);
                    road->addVehicle(v);
                    freqCounter = 0;
                }
            }
            std::vector<TrafficLight*> trafficLights = road->getTrafficlights();
            std::vector<Vehicle*> vehicles = road->getVehicles();
            for (TrafficLight* trafficLight : trafficLights) {
                if (cycleCounter * SIM_TIME > trafficLight->getCycle()) {
                    trafficLight->toggle();
                    cycleCounter = 0;
                }

                Vehicle* firstVehicle = road->getFirstToTrafficLight(trafficLight);
                if (firstVehicle == nullptr) continue;
                if (trafficLight->isGreen()) firstVehicle->accelerate();
                else {
                    double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

                    if (distanceToLight < DECELERATION_DISTANCE) {
                        firstVehicle->decelerate();
                    }
                    if (distanceToLight < BRAKE_DISTANCE && distanceToLight > BRAKE_DISTANCE / 2) {
                        firstVehicle->stop();
                    }
                }
            }

            for (Vehicle* vehicle : vehicles) {
                vehicle->tick(road->getLeadingVehicle(vehicle));
                 onStream << "Vehicle " << vehicle->getId() << std::endl;
                 onStream << "-> Road: " << road->getName() << std::endl;
                 onStream << "-> Position: " << vehicle->getPosition() << std::endl;
                 onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
            }
            print(timestamp * SIM_TIME);
            road->cleanup();
        }
        timestamp++;
        cycleCounter++;
        freqCounter++;
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(SIM_TIME * 1000)));
    }
}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling print");
*/
void Simulation::print(double time) {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling print");

    clear();

    std::cout << "Time: T+ " << std::to_string(time) << std::endl;
    for (Road* road : roads) {
        std::cout << road->getName() << std::endl;
        int width = road->getLength();

        char* repr = new char[width];
        for (int i = 0; i < width; i++) repr[i] = '-';

        for (TrafficLight* trafficLight : road->getTrafficlights()) {
            repr[(int)trafficLight->getPosition()] = trafficLight->isGreen() ? 'G' : 'R';
        }

        for (Vehicle* vehicle : road->getVehicles()) {
            repr[(int)vehicle->getPosition()] = 'V';
        }

        for (int i = 0; i < width; i++) std::cout << repr[i];
        std::cout << std::endl << std::endl;
    }

}

/**
\n REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling printForVisualizer");
*/
void Simulation::printForVisualizer() {
    REQUIRE(this->properlyInitialized(), "TicTacToe wasn't initialized when calling printForVisualizer");

    int timestamp = 0;
    int cycleCounter = 0;
    int freqCounter = 0;

    while (countVehicles() > 0) {
        std::cout << R"({"time": )" << timestamp*SIM_TIME << ",";
        for (Road *road: roads) {
            std::cout << R"("roads":[{"name":")" << road->getName() << "\",";
            std::cout << R"("length":)" << road->getLength() << ",";
//            std::vector<VehicleGenerator *> generators = road->getGenerators();
//            for (VehicleGenerator *generator: generators) {
//                if (freqCounter * SIM_TIME > generator->getFrequency()) {
//                    Vehicle *v = new Vehicle;
//                    v->setPosition(0);
//                    road->addVehicle(v);
//                    freqCounter = 0;
//                }
//            }
            std::cout << R"("cars":[)";
            std::vector<Vehicle *> vehicles = road->getVehicles();
            for (Vehicle *vehicle: vehicles) {
                vehicle->tick(road->getLeadingVehicle(vehicle));
                std::cout << R"({"x":)" << vehicle->getPosition() << "}";
                if (vehicle != vehicles.back()) std::cout << ",";
            }
            std::cout << "],";

            std::cout << R"("lights":[)";
            std::vector<TrafficLight *> trafficLights = road->getTrafficlights();
            for (TrafficLight *trafficLight: trafficLights) {
                if (cycleCounter*SIM_TIME > trafficLight->getCycle()) {
                    trafficLight->toggle();
                    cycleCounter = 0;
                }
                std::cout << R"({"x":)" << trafficLight->getPosition() << R"(,"green":)" << trafficLight->isGreen() << R"(})";
                if (trafficLight != trafficLights.back()) std::cout << ",";
                Vehicle *firstVehicle = road->getFirstToTrafficLight(trafficLight);
                if (firstVehicle == nullptr) continue;
                if (trafficLight->isGreen()) firstVehicle->accelerate();
                else {
                    double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

                    if (distanceToLight < DECELERATION_DISTANCE) {
                        firstVehicle->decelerate();
                    }
                    if (distanceToLight < BRAKE_DISTANCE && distanceToLight > BRAKE_DISTANCE / 2) {
                        firstVehicle->stop();
                    }
                }
            }
            road->cleanup();
        }
        std::cout << "]}]}"<< std::endl;
        timestamp++;
        cycleCounter++;
        freqCounter++;
        std::this_thread::sleep_for(std::chrono::milliseconds((int) (SIM_TIME * 1000)));
    }
}

void Simulation::clear() {
    // Clear console
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif  //finish
}


