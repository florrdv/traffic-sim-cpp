#include "TrafficLight.h"

const std::string &TrafficLight::getRoad() const {
    return road;
}

void TrafficLight::setRoad(const std::string &road) {
    TrafficLight::road = road;
}

int TrafficLight::getPosition() const {
    return position;
}

void TrafficLight::setPosition(int position) {
    TrafficLight::position = position;
}

int TrafficLight::getCycles() const {
    return cycles;
}

void TrafficLight::setCycles(int cycles) {
    TrafficLight::cycles = cycles;
}
