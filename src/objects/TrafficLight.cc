/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains traffic light logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:38 pm
 */

#include "TrafficLight.h"

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
