/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#include "Road.h"
#include "../lib/DesignByContract.h"


const std::string &Road::getName() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return name;
}


void Road::setName(const std::string &n) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(!name.empty(), "Road name cannot be empty");
    Road::name = n;
}


double Road::getLength() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return length;
}


void Road::setLength(double l) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(l > 0, "Length must be strictly positive");
    Road::length = l;
}


const std::vector<Vehicle *> &Road::getVehicles() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return vehicles;
}


void Road::addVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(v != nullptr, "Cannot add empty vehicle to road");
    v->setId(vehicles.size());
    vehicles.push_back(v);
}


void Road::addTrafficLight(TrafficLight *t) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(t != nullptr, "Cannot add empty traffic light to road");
    trafficLights.push_back(t);
}


const std::vector<TrafficLight *> &Road::getTrafficLights() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return trafficLights;
}


VehicleGenerator *Road::getGenerator() const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    return generator;
}


void Road::setGenerator(VehicleGenerator *g) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    ENSURE(g != nullptr, "Cannot add empty generator to road");
    generator = g;
}


Vehicle *Road::getLeadingVehicle(Vehicle *v) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    Vehicle *leadingVehicle = nullptr;
    for (Vehicle *candidate: vehicles) {
        if (candidate->getPosition() <= v->getPosition()) continue;
        if (leadingVehicle == nullptr ||
            leadingVehicle->getPosition() - v->getPosition() > candidate->getPosition() - v->getPosition())
            leadingVehicle = candidate;
    }
    return leadingVehicle;
}


void Road::cleanup() {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    std::vector<Vehicle *>::iterator vehicle = vehicles.begin();
    while (vehicle != vehicles.end()) {
        if ((*vehicle)->getPosition() > length) {
            vehicles.erase(vehicle);
        } else ++vehicle;
    }
}


Vehicle *Road::getFirstToTrafficLight(TrafficLight *t) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    int trafficLightPosition = t->getPosition();
    Vehicle *firstVehicle = nullptr;
    for (Vehicle *vehicle: vehicles) {
        double distanceToLight = ((double) trafficLightPosition) - vehicle->getPosition();
        if (firstVehicle == nullptr) {
            if (distanceToLight > 0) firstVehicle = vehicle;
            continue;
        }

        double previousDistanceToLight = ((double) trafficLightPosition) - firstVehicle->getPosition();

        if (distanceToLight > 0 && distanceToLight < previousDistanceToLight) firstVehicle = vehicle;
    }
    return firstVehicle;
}


Vehicle *Road::getFirstBusToBusStop(BusStop *b) const {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    int busStopPosition = b->getPosition();
    Vehicle *firstBus = nullptr;
    for (Vehicle *bus: vehicles) {
        if (bus->getType() != Bus) continue;
        double distanceToStop = ((double) busStopPosition) - bus->getPosition();
        if (firstBus == nullptr) {
            if (distanceToStop > 0) firstBus = bus;
            continue;
        }

        double previousDistanceToBusStop = ((double) busStopPosition) - firstBus->getPosition();

        if (distanceToStop > 0 && distanceToStop < previousDistanceToBusStop) firstBus = bus;
    }
    return firstBus;
}


void Road::spawnVehicle(const VehicleType &type) {
    REQUIRE(this->properlyInitialized(), "Road was not properly initialized");
    Vehicle *v = new Vehicle(0, VehicleType::Personal);
    addVehicle(v);
}

void Road::tickTrafficLights() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    // Loop over all traffic lights
    for (TrafficLight *trafficLight: trafficLights) {
        int cycleCount = trafficLight->getCycleCount();
        // Check if we have to toggle the light
        bool shouldToggle = cycleCount * gSimTime > trafficLight->getCycle();
        if (shouldToggle) {
            trafficLight->toggle();
            trafficLight->setCycleCount(0);
        } else trafficLight->setCycleCount(cycleCount + 1);

        // Get the first vehicle relative to the traffic light
        // To make vehicles decelerate or stop, we just need to perform the action
        // on the first vehicle driving towards the traffic light.
        Vehicle *firstVehicle = getFirstToTrafficLight(trafficLight);
        // No vehicles are driving towards the traffic light, continue to the next traffic light
        if (firstVehicle == nullptr) continue;

        // If the traffic light is green, all vehicles should accelerate
        if (trafficLight->isGreen()) firstVehicle->accelerate();
        else {
            // The light is red, let's check the distance from the first vehicle to the traffic light
            double distanceToLight = trafficLight->getPosition() - firstVehicle->getPosition();

            // Stop the vehicle if it's in the braking zone
            if (distanceToLight < gBrakeDistance) firstVehicle->stop();
                // Force the vehicle to decelerate if it's in the deceleration zone
            else if (distanceToLight < gDecelerationDistance) firstVehicle->decelerate();
        }
    }
}


void Road::tickBusStops() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    for (BusStop *busStop: busStops) {
        int waitTime = busStop->getWaitTime();
        // Get the first bus relative to the bus stop
        Vehicle *firstBus = getFirstBusToBusStop(busStop);
        // Check if there's a bus that can move again
        if (busStop->getBus() != nullptr) {
            if (waitTime * gSimTime > busStop->getTimeCount()) {
                busStop->removeBus();
                busStop->setTimeCount(0);
            } else busStop->setTimeCount(waitTime + 1);
        }

        // No busses are driving towards the bus stop, continue to the next bus stop
        if (firstBus == nullptr) continue;

        // Check the distance from the first bus to the bus stop
        double distanceToStop = busStop->getPosition() - firstBus->getPosition();

        // Stop the bus if it's in the braking zone
        if (distanceToStop < gBrakeDistance) {
            firstBus->stop();
            busStop->setBus(firstBus);
        }
            // Force the bus to decelerate if it's in the deceleration zone
        else if (distanceToStop < gDecelerationDistance) firstBus->decelerate();
    }
}

void Road::tickVehicles(std::ostream &onStream) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    // Loop over all vehicles
    for (Vehicle *vehicle: vehicles) {
        // Tick the relevant vehicle
        vehicle->tick(getLeadingVehicle(vehicle));

        // Print all information on the vehicle in
        // the requested format
        onStream << "Vehicle " << vehicle->getId() << std::endl;
        onStream << "-> Road: " << getName() << std::endl;
        onStream << "-> Position: " << vehicle->getPosition() << std::endl;
        onStream << "-> Speed: " << vehicle->getSpeed() << std::endl;
    }
}

void Road::tickVehicleGenerators() {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    // If there's a generator running on the road and the cycle time
    // has been exceeded, spawn a new vehicle
    if (generator == nullptr) return;

    // Get the frequency count for the generator
    int freqCount = generator->getFrequencyCount();
    bool shouldSpawn = freqCount * gSimTime > generator->getFrequency();

    // Spawn a vehicle if necessary
    if (shouldSpawn) {
        spawnVehicle(generator->getType());
        generator->setFrequencyCount(0);
    } else generator->setFrequencyCount(freqCount + 1);
}

void Road::tick(std::ostream &stream) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    tickVehicleGenerators();
    tickTrafficLights();
    tickBusStops();
    tickVehicles(stream);

    cleanup();
}

const std::vector<BusStop *> &Road::getBusStops() const {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    return busStops;
}

const std::vector<Crossroad *> &Road::getCrossroads() const {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    return crossRoads;
}

void Road::setCrossroads(const std::vector<Crossroad *> &c) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    Road::crossRoads = c;
}

void Road::addCrossroad(Crossroad *c) {
    REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    Road::crossRoads.push_back(c);
}
