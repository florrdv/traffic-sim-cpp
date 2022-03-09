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
#include "TrafficLight.h"

class Road {
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getLength() const;

    void setLength(int length);

private:
    std::string name;
    int length;

    std::vector<Vehicle*> vehicles;
    std::vector<TrafficLight*> trafficLights;

public:
    const std::vector<Vehicle *> &getVehicles() const;

    void addVehicle(Vehicle *v);

    const std::vector<TrafficLight *> &getTrafficlights() const;

    void addTrafficLight(TrafficLight *t);
};



#endif //TRAFFICSIM_ROAD_H
