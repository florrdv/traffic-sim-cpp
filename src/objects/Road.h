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
#include <vector>

#include "Vehicle.h"
#include "VehicleGenerator.h"
#include "TrafficLight.h"
#include "../lib/DesignByContract.h"

class Road {
private:
    Road* _init;

    std::string name;
    int length;

    std::vector<Vehicle*> vehicles;
    std::vector<TrafficLight*> trafficLights;
    VehicleGenerator* generator=nullptr;

public:
    // Constructors / destructors
    Road() { _init = this; }
    ~Road() {
        REQUIRE(this->properlyInitialized(), "Road wasn't initialized when calling destructor");
        for (Vehicle* vehicle : vehicles) delete vehicle;
        for (TrafficLight* trafficLight : trafficLights) delete trafficLight;
        delete generator;
    }

    // Regular methods
    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::string &getName() const;
    
    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void setName(const std::string &name);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    int getLength() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void setLength(int length);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<Vehicle *> &getVehicles() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void addVehicle(Vehicle *v);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    Vehicle* getLeadingVehicle(Vehicle *v);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    Vehicle* getFirstToTrafficLight(TrafficLight *trafficLight) const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    const std::vector<TrafficLight *> &getTrafficLights() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void addTrafficLight(TrafficLight *t);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    VehicleGenerator* getGenerator() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void setGenerator(VehicleGenerator *g);

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void cleanup();

    /**
    \n REQUIRE(this->properlyInitialized(), "Road wasn't initialized properly");
    */
    void spawnVehicle();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};



#endif //TRAFFICSIM_ROAD_H
