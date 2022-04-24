#ifndef PSE_TRAFFIC_SIM_BUSSTOP_H
#define PSE_TRAFFIC_SIM_BUSSTOP_H

#include <string>
#include "Entity.h"

class BusStop : public Entity {
private:
    BusStop* _init;

    std::string name;

    int waitTime;

public:
    BusStop(double position, int w) : Entity(position), waitTime(w) { _init = this; };

    const std::string &getName() const;

    void setName(const std::string &name);

    int getWaitTime() const;

    void setWaitTime(int waitTime);
};


#endif //PSE_TRAFFIC_SIM_BUSSTOP_H
