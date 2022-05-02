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

    int waitTime;

public:
    BusStop(double position, int w) : Entity(position), waitTime(w) { _init = this; };

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    int getTimeCount() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    void setTimeCount(int timeCount);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    int getWaitTime() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    \n ENSURE(w > 0, "Bus stop wait time must be strictly positive");
    */
    void setWaitTime(int waitTime);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    Vehicle *getBus() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    void setBus(Vehicle *bus);

    /**
    \n REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    */
    void removeBus();

private:
    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //PSE_TRAFFIC_SIM_BUSSTOP_H
