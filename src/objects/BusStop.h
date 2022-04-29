#ifndef PSE_TRAFFIC_SIM_BUSSTOP_H
#define PSE_TRAFFIC_SIM_BUSSTOP_H

#include <string>
#include "Entity.h"
#include "Vehicle.h"

class BusStop : public Entity {
private:
    BusStop* _init;

    Vehicle* bus = nullptr;

    int timeCount = 0;

    std::string name;

    int waitTime;

public:
    BusStop(double position, int w) : Entity(position), waitTime(w) { _init = this; };

    const std::string &getName() const;

    void setName(const std::string &name);

    int getTimeCount() const;

    void setTimeCount(int timeCount);

    int getWaitTime() const;

    void setWaitTime(int waitTime);

    Vehicle *getBus() const;

    void setBus(Vehicle *bus);

    void removeBus();
};


#endif //PSE_TRAFFIC_SIM_BUSSTOP_H
