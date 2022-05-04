/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 20th April 2022 9:12:10 pm
 */

#include "BusStop.h"
#include "../lib/DesignByContract.h"

BusStop::BusStop(double position, int w) : Entity(position), waitTime(w) {
    REQUIRE(position >= 0, "Position has to be positive");
    REQUIRE(w > 0, "Wait time has to be strictly positive");
    _init = this;
    ENSURE(_init == this, "_init reference must be set");
}

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
    timeCount = t;
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
