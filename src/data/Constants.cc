#include "Constants.h"

std::map<VehicleType, VehicleConstant> gVehicleConstants = {
    {
        VehicleType::Personal,
        VehicleConstant {
            .gVehicleLength = 4,
            .gSpeedMax = 16.6,
            .gAccelerationMax = 1.44,
            .gBrakeMax = 4.61,
            .gFollowMin = 4
        }
    },
    {
        VehicleType::Bus,
        VehicleConstant {
            .gVehicleLength = 12,
            .gSpeedMax = 11.4,
            .gAccelerationMax = 1.22,
            .gBrakeMax = 4.29,
            .gFollowMin = 12
        }
    },
    {
        VehicleType::FireTruck,
        VehicleConstant {
            .gVehicleLength = 10,
            .gSpeedMax = 14.6,
            .gAccelerationMax = 1.33,
            .gBrakeMax = 4.56,
            .gFollowMin = 10
        }
    },
    {
        VehicleType::Ambulance,
        VehicleConstant {
            .gVehicleLength = 8,
            .gSpeedMax = 15.5,
            .gAccelerationMax = 1.44,
            .gBrakeMax = 4.47,
            .gFollowMin = 8
        }
    },
    {
        VehicleType::Police,
        VehicleConstant {
            .gVehicleLength = 6,
            .gSpeedMax = 17.2,
            .gAccelerationMax = 1.55,
            .gBrakeMax = 4.92,
            .gFollowMin = 6
        }
    }
};

double gBrakeDistance           = 15;
double gSimTime                 = 0.0166;
double gDecelerationDistance    = 50;
double gDecelerationFactor      = 0.4;