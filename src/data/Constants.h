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

extern std::map<VehicleType, VehicleConstant> gVehicleConstants;

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



#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_