#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_

#include <string>

static double gVehicleLength           = 4;
static double gSpeedMax                = 16.6;
static double gAccelerationMax         = 1.44;
static double gBrakeMax                = 4.61;
static double gBrakeDistance           = 15;
static double gFollowMin               = 4;
static double gSimTime                 = 0.0166;
static double gDecelerationDistance    = 50;
static double gDecelerationFactor      = 0.4 ;

static std::string gTestInputFolder = "../input/testing";
static std::string gTestOutputFolder = "../output/testing";

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_DATA_CONSTANTS_CC_