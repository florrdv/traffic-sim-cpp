#include "TrafficLight.h"

const std::string &TrafficLight::getRoad() const {
    return road;
}

void TrafficLight::setRoad(const std::string &r) {
    TrafficLight::road = r;
}

int TrafficLight::getPosition() const {
    return position;
}

void TrafficLight::setPosition(int p) {
    TrafficLight::position = p;
}

int TrafficLight::getCycles() const {
    return cycles;
}

void TrafficLight::setCycles(int c) {
    TrafficLight::cycles = c;
}
