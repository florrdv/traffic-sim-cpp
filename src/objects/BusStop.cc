#include "BusStop.h"

const std::string &BusStop::getName() const {
    return name;
}

void BusStop::setName(const std::string &name) {
    BusStop::name = name;
}

int BusStop::getWaitTime() const {
    return waitTime;
}

void BusStop::setWaitTime(int waitTime) {
    BusStop::waitTime = waitTime;
}
