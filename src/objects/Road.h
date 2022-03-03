#ifndef TRAFFICSIM_ROAD_H
#define TRAFFICSIM_ROAD_H

#include <string>
#include <vector>
#include "Vehicle.h"

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
    std::vector<TrafficLight*> trafficlights;
public:
    const std::vector<Vehicle *> &getVehicles() const;

    void setVehicles(const std::vector<Vehicle *> &vehicles);

    const std::vector<TrafficLight *> &getTrafficlights() const;

    void setTrafficlights(const std::vector<TrafficLight *> &trafficlights);
};



#endif //TRAFFICSIM_ROAD_H
