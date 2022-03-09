#ifndef TRAFFICSIM_TRAFFICLIGHT_H
#define TRAFFICSIM_TRAFFICLIGHT_H

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: 
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <string>

class TrafficLight {
public:
    const std::string &getRoad() const;

    int getPosition() const;

    void setPosition(int position);

    int getCycles() const;

    void setCycles(int cycles);

private:
    int position;
    int cycles;
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
