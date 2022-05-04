/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description:
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 21st April 2022 10:30:44 pm
 */

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_

#include <string>
#include <map>

enum VehicleType {
    Personal,
    Bus,
    FireTruck,
    Ambulance,
    Police
};

struct VehicleConstant {
    int     gVehicleLength;
    double  gSpeedMax;
    double  gAccelerationMax;
    double  gBrakeMax;
    double  gFollowMin;
};

std::vector<VehicleType> priorityVehicleTypes;

extern std::map<VehicleType, VehicleConstant> gVehicleConstants;

extern double gBrakeDistance;
extern double gSimTime;
extern double gDecelerationDistance;
extern double gDecelerationFactor;

static std::string gTestInputFolder = "../input/testing";
static std::string gTestOutputFolder = "../output/testing";



#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_
