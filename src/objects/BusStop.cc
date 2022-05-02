#include "BusStop.h"
#include "../lib/DesignByContract.h"

Vehicle *BusStop::getBus() const {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");

    return bus;
}

void BusStop::setBus(Vehicle *b) {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    ENSURE(b != nullptr, "Bus cannot be nullptr");
    BusStop::bus = b;
    ENSURE(BusStop::bus == b, "Bus was not set properly");
}

void BusStop::removeBus() {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");

    bus = nullptr;
}

int BusStop::getTimeCount() const {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");

    return timeCount;
}

void BusStop::setTimeCount(int t) {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    ENSURE(t >= 0, "Bus stop wait time must be positive");
    BusStop::timeCount = t;
    ENSURE(BusStop::timeCount == t, "Time count was not set properly");
}

int BusStop::getWaitTime() const {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    return waitTime;
}

void BusStop::setWaitTime(int w) {
    REQUIRE(this->properlyInitialized(), "Bus stop wasn't initialized properly");
    ENSURE(w > 0, "Bus stop wait time must be strictly positive");
    BusStop::waitTime = w;
    ENSURE(BusStop::waitTime == w, "Wait time was not set properly");
}
