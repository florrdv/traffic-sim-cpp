#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_

#include <string>

extern double gVehicleLength;
extern double gSpeedMax;
extern double gAccelerationMax;
extern double gBrakeMax;
extern double gBrakeDistance;
extern double gFollowMin;
extern double gSimTime;
extern double gDecelerationDistance;
extern double gDecelerationFactor;


static std::string gTestInputFolder = "../input/testing";
static std::string gTestOutputFolder = "../output/testing";

enum VehicleType {
    Personal,
    Bus,
    FireTruck,
    Ambulance,
    Police,
    num_types
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_