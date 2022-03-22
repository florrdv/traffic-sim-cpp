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
    VehicleGenerator* generator;
public:
    // Constructors / destructors
    Road() { _init = this; }
    ~Road() {
        REQUIRE(this->properlyInitialized(), "Road wasn't initialized when calling destructor");
        for (Vehicle* vehicle : vehicles) delete vehicle;
        for (TrafficLight* trafficLight : trafficLights) delete trafficLight;
    }

    // Regular methods
    const std::string &getName() const;
    void setName(const std::string &name);

    int getLength() const;
    void setLength(int length);

    const std::vector<Vehicle *> &getVehicles() const;
    void addVehicle(Vehicle *v);
    Vehicle* getLeadingVehicle(Vehicle *v);
    Vehicle* getFirstToTrafficLight(TrafficLight *trafficLight) const;

    const std::vector<TrafficLight *> &getTrafficlights() const;
    void addTrafficLight(TrafficLight *t);

    const VehicleGenerator* getGenerator() const;
    void addGenerator(VehicleGenerator *g);

    void cleanup();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};



#endif //TRAFFICSIM_ROAD_H
