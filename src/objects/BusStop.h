#ifndef PSE_TRAFFIC_SIM_BUSSTOP_H
#define PSE_TRAFFIC_SIM_BUSSTOP_H

#include <string>
#include "Entity.h"

class BusStop : Entity {
private:
    std::string name;

    int waitTime;

public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getWaitTime() const;

    void setWaitTime(int waitTime);
};


#endif //PSE_TRAFFIC_SIM_BUSSTOP_H
