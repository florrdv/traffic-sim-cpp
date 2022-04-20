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
#include <gtest/gtest_prod.h>

#include "../data/Constants.h"
#include "Entity.h"

class VehicleTests;

enum VehicleType {
    Personal,
    Bus,
    FireTruck,
    Ambulance,
    Police
};

class Vehicle: public Entity {
    FRIEND_TEST(VehicleTests, UpdateAccelerationHappyDay);
    FRIEND_TEST(VehicleTests, UpdateSpeedHappyDay);
    
private:

    Vehicle* _init;

    int id;
    VehicleType type;

    double speed = 0;
    double acceleration = 0;

    double length = gVehicleLength;
    double speedMax = gSpeedMax;
    double accelerationMax = gAccelerationMax;
    double brakeMax = gBrakeMax;
    double followMin = gFollowMin;
    double simTime = gSimTime;
    double decelerationDistance = gDecelerationDistance;
    double decelerationFactor = gDecelerationFactor;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(speed >= 0, "Vehicle speed must be positive");
    */
    void updateSpeed();
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(acceleration <= accelerationMax, "Vehicle acceleration cannot be greater than max acceleration");
    */
    void updateAcceleration(Vehicle* leadingVehicle);

public:
    // Constructors / destructors
    Vehicle(double position, VehicleType t): Entity(position), type(t) { _init = this; }

    // General methods

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    int getId() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(id_>=0, "Vehicle ID cannot be a negative integer");
    */
    void setId(int id);

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    double getLength() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    double getSpeed() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    double getSpeedMax() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    double getAcceleration() const;
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    double getDecelerationFactor() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    void tick(Vehicle* leadingVehicle);

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    void stop();
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    void decelerate();
    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    void accelerate();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_VEHICLE_H
