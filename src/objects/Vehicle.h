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
#include "../data/Constants.cc"

class Vehicle {
private:
    Vehicle* _init;

private:
    double position = 0;
    int id;

    double speed = 0;
    double acceleration = 0;

    double length               = VEHICLE_LENGTH;
    double speedMax             = SPEED_MAX;
    double accelerationMax      = ACCELERATION_MAX;
    double brakeMax             = BRAKE_MAX;
    double followMin            = FOLLOW_MIN;
    double simTime              = SIM_TIME;
    double decelerationDistance = DECELERATION_DISTANCE;
    double decelerationFactor   = DECELERATION_FACTOR;


    void updateSpeed();
    void updateAcceleration(Vehicle* leadingVehicle);
    bool stopping = false;

public:
    // Constructors / destructors
    Vehicle() { _init = this; }

    // General methods
    double getPosition() const;
    void setPosition(int position);

    int getId() const;
    void setId(int id);

    double getLength() const;

    double getSpeed() const;
    double getAcceleration() const;

    void tick(Vehicle* leadingVehicle);

    void stop();

    void decelerate();
    void accelerate();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_VEHICLE_H
