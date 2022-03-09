#ifndef TRAFFICSIM_VEHICLE_H
#define TRAFFICSIM_VEHICLE_H

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <string>

class Vehicle {
public:
    int getPosition() const;

    void setPosition(int position);

private:
    int position;
};


#endif //TRAFFICSIM_VEHICLE_H
