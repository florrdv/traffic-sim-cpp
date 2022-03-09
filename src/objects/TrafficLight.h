#ifndef TRAFFICSIM_TRAFFICLIGHT_H
#define TRAFFICSIM_TRAFFICLIGHT_H

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains traffic light class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <string>

class TrafficLight {
private:
    TrafficLight* _init;

    int position;
    int cycle;

public:
    // Constructors / destructors
    TrafficLight() { _init = this; }

    // Regular methods
    const std::string &getRoad() const;
    int getPosition() const;
    void setPosition(int position);
    int getCycle() const;
    void setCycle(int cycles);

    // Safety specific
    bool properlyInitialized() { return _init == this; }
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
