/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains vehicle class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#ifndef TRAFFICSIM_VEHICLE_H
#define TRAFFICSIM_VEHICLE_H

#include <map>
#include <string>
#include <gtest/gtest_prod.h>

#include "../data/Constants.h"
#include "Entity.h"

class VehicleTests;
class Road;

class Vehicle: public Entity {
    FRIEND_TEST(VehicleTests, UpdateAccelerationHappyDay);
    FRIEND_TEST(VehicleTests, UpdateSpeedHappyDay);
    
private:

    Vehicle* _init;

    int id;
    VehicleType type;

    double speed = 0;
    double acceleration = 0;

    double length;
    double speedMaxLimit;
    double speedMax;
    double accelerationMax;
    double brakeMax;
    double followMin;
    double simTime;
    double decelerationDistance;
    double decelerationFactor;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(speed >= 0, "Vehicle speed must be positive");
    \n ENSURE(getPosition() >= 0, "Vehicle position must be positive");
    */
    void updateSpeed();

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(acceleration <= accelerationMax, "Vehicle acceleration cannot be greater than max acceleration");
    */
    void updateAcceleration(Vehicle* leadingVehicle);

public:
    // Constructors / destructors
    /**
    \n REQUIRE(position >= 0, "Position has to be positive");
    \n ENSURE(_init == this, "_init reference must be set");
     */
    Vehicle(double position, VehicleType t);

    // General methods

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    int getId() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(id_>=0, "Vehicle ID cannot be a negative integer");
    \n ENSURE(Vehicle::id == id_, "Vehicle ID was not set properly");
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
    VehicleType getType() const;

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    */
    void tick(Vehicle* leadingVehicle);

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(acceleration <= accelerationBefore, "Acceleration should not increase while stopping");
    */
    void stop();

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(speedMax <= speedBefore, "Speed should not increase while decelerating");
    */
    void decelerate();

    /**
    \n REQUIRE(this->properlyInitialized(), "Vehicle was not properly initialized");
    \n ENSURE(std::abs(speedMax - speedMaxLimit) < std::numeric_limits<double>::epsilon(), "Speed was not set correctly on acceleration");
    */
    void accelerate();

    // Safety specific
    bool properlyInitialized() const { return _init == this; }
};


#endif //TRAFFICSIM_VEHICLE_H
