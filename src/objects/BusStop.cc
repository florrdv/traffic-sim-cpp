#include "BusStop.h"

const std::string &BusStop::getName() const {
    return name;
}

void BusStop::setName(const std::string &n) {
    BusStop::name = n;
}

Vehicle *BusStop::getBus() const {
    return bus;
}

void BusStop::setBus(Vehicle *b) {
    BusStop::bus = b;
}

void BusStop::removeBus() {
    bus = nullptr;
}

int BusStop::getTimeCount() const {
    return timeCount;
}

void BusStop::setTimeCount(int t) {
    BusStop::timeCount = t;
}

int BusStop::getWaitTime() const {
    return waitTime;
}
