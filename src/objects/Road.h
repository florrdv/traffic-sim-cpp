#ifndef TRAFFICSIM_ROAD_H
#define TRAFFICSIM_ROAD_H

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 5:12:46 pm
 */

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

private:
    Road *_init;

    std::string name;
    double length;

    std::vector<Vehicle *> vehicles;
    std::vector<TrafficLight *> trafficLights;
    std::vector<BusStop *> busStops;
    std::vector<Crossroad *> crossRoads;

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
    */
    void spawnVehicle(const VehicleType &type);

public:
    // Constructors / destructors
    /**
    \n ENSURE(l >= 0, "Road length must be positive");
    */
    Road(std::string n, double l);

    ~Road() {
        REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly when calling destructor");
        for (Vehicle *vehicle: vehicles) delete vehicle;
        for (TrafficLight *trafficLight: trafficLights) delete trafficLight;
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
    */
    void setName(const std::string &name);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    double getLength() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(l>0, "Length must be strictly positive");
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
    \n REQUIRE(v->getPosition() < length, "Road not long enough for vehicle");

    \n ENSURE(v != nullptr, "Cannot add empty vehicle to road");
    */
    void addVehicle(Vehicle *v);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    Vehicle *getLeadingVehicle(Vehicle *v);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    Vehicle *getFirstToTrafficLight(TrafficLight *trafficLight) const;

    /**
    \n
    */
    Vehicle *getFirstBusToBusStop(BusStop *busStop) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<TrafficLight *> &getTrafficLights() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(t->getPosition() < length, "Road not long enough for traffic light");
    \n ENSURE(t != nullptr, "Cannot add empty traffic light to road");
    */
    void addTrafficLight(TrafficLight *t);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    VehicleGenerator *getGenerator() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n ENSURE(g != nullptr, "Cannot add empty generator to road");
     */
    void setGenerator(VehicleGenerator *g);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
     */
    const std::vector<Crossroad *> &getCrossroads() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(c->getPositionForRoad(this) > length, "Road not long enough for crossroad");
     */
    void addCrossroad(Crossroad *c);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    \n REQUIRE(b->getPosition() < length, "Road not long enough for bus stop");
     */
    void addBusStop(BusStop *c);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
     */
    void tick(std::ostream &stream);

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_ROAD_H
