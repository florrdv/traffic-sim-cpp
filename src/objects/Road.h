/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

#ifndef TRAFFICSIM_ROAD_H
#define TRAFFICSIM_ROAD_H

#include <string>
#include <utility>
#include <vector>

#include "Vehicle.h"
#include "VehicleGenerator.h"
#include "TrafficLight.h"
#include "BusStop.h"
#include "Crossroad.h"
#include "../lib/DesignByContract.h"

class Road {
    FRIEND_TEST(RoadTests, TickVehicleGeneratorsHappyDay);
    FRIEND_TEST(RoadTests, TickTrafficLightsHappyDay);
    FRIEND_TEST(RoadTests, SpawnVehicleHappyDay);
    FRIEND_TEST(RoadTests, TickBusStopsHappyDay);

private:
    Road *_init;

    std::string name;
    double length;

    std::vector<Vehicle *> vehicles;
    std::vector<TrafficLight *> trafficLights;
    std::vector<BusStop *> busStops;
    std::vector<Crossroad *> crossroads;

    VehicleGenerator *generator = nullptr;

    /**
    \n ENSURE(properlyInitialized(), "Road wasn't initialized properly");
    */
    void tickTrafficLights();

    /**
    \n ENSURE(properlyInitialized(), "Road wasn't initialized properly");
    */
    void tickVehicleGenerators();

    /**
    /n ENSURE(properlyInitialized(), "Road wasn't initialized properly");
    */
    void tickBusStops();

    /**
    \n ENSURE(properlyInitialized(), "Road wasn't initialized properly");
    */
    void tickVehicles(std::ostream &stream);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void cleanup();

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(countAfter == countBefore + 1, "Vehicle was not spawned correctly");
    */
    void spawnVehicle(const VehicleType &type);

public:
    // Constructors / destructors
    /**
    \n REQUIRE(l > 0, "Road length must be strictly positive");
    \n ENSURE(_init == this, "_init reference must be set");
    */
    Road(std::string n, double l);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly when calling destructor");
    */
    ~Road() {
        REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly when calling destructor");
        for (Vehicle *vehicle : vehicles) delete vehicle;
        for (TrafficLight *trafficLight : trafficLights) delete trafficLight;
        for (Crossroad *crossroad : crossroads) delete crossroad;
        for (BusStop *busStop : busStops) delete busStop;
        delete generator;
    }

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::string &getName() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(!name.empty(), "Road name cannot be empty");
    \n ENSURE(Road::name == n, "Road name was not set properly");
    */
    void setName(const std::string &name);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    double getLength() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(l>0, "Length must be strictly positive");
    \n ENSURE(Road::length == l, "Road length was not set properly");
    */
    void setLength(double length);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<Vehicle *> &getVehicles() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<BusStop *> &getBusStops() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(v != nullptr, "Cannot add empty vehicle to road");
    \n REQUIRE(v->getPosition() < length, "Road not long enough for vehicle");
    \n ENSURE(std::find(vehicles.begin(), vehicles.end(), v) != vehicles.end(), "Vehicle was not added properly");
    */
    void addVehicle(Vehicle *v);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(vehicle != nullptr, "Vehicle may not be a nullptr");
    \n REQUIRE(std::find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end(), "Vehicle must be on road");
    */
    Vehicle *getLeadingVehicle(Vehicle *vehicle) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(trafficLight != nullptr, "Traffic light cannot be nullptr");
    \n REQUIRE(std::find(trafficLights.begin(), trafficLights.end(), trafficLight) != trafficLights.end(), "Traffic light has to be on road");
    */
    Vehicle *getFirstToTrafficLight(TrafficLight *trafficLight) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(busStop != nullptr, "Bus stop cannot be nullptr");
    \n REQUIRE(std::find(busStops.begin(), busStops.end(), busStop) != busStops.end(), "Bus stop must be on road");
    */
    Vehicle *getFirstBusToBusStop(BusStop *busStop) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<TrafficLight *> &getTrafficLights() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(trafficLight != nullptr, "Cannot add empty traffic light to road");
    \n REQUIRE(trafficLight->getPosition() < length, "Road not long enough for traffic light");
    \n ENSURE(std::find(trafficLights.begin(), trafficLights.end(), trafficLight) != trafficLights.end(), "Traffic light was not added properly");
    */
    void addTrafficLight(TrafficLight *trafficLight);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    VehicleGenerator *getGenerator() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(g != nullptr, "Cannot add empty generator to road");
    \n ENSURE(generator == g, "Generator was not set properly");
     */
    void setGenerator(VehicleGenerator *g);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
     */
    const std::vector<Crossroad *> &getCrossroads() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(c != nullptr, "Crossroad cannot be nullptr");
    \n REQUIRE(c->getPositionForRoad(this) < length, "Road not long enough for crossroad");
    \n ENSURE(std::find(crossroads.begin(), crossroads.end(), c) != crossroads.end(), "Crossroad was not added properly");
     */
    void addCrossroad(Crossroad *c);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(b != nullptr, "Bus stop cannot be nullptr");
    \n REQUIRE(b->getPosition() < length, "Road not long enough for bus stop");
    \n ENSURE(std::find(busStops.begin(), busStops.end(), b) != busStops.end(), "Bus was not added properly");
    */
    void addBusStop(BusStop *b);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
     */
    void tick(std::ostream &stream);

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_ROAD_H
