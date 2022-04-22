#include <gtest/gtest.h>
#include "Vehicle.h"

TEST(VehicleTests, PositionMutationHappyDay) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, v.getPosition());
    v.setPosition(1.0);
    EXPECT_EQ(1.0, v.getPosition());
}

TEST(VehicleTests, PositionMutationNegative) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, v.getPosition());
    EXPECT_DEATH(v.setPosition(-1), "positive");
}

TEST(VehicleTests, TickHappyDay) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);

    EXPECT_EQ(0.0, v.getSpeed());
    EXPECT_EQ(0.0, v.getAcceleration());
    EXPECT_EQ(0.0, v.getPosition());

    // Tick twice
    v.tick(nullptr);
    v.tick(nullptr);

    EXPECT_TRUE(std::abs(v.getSpeed() - 0.023903999999999998) < 0.00001);
    EXPECT_TRUE(std::abs(v.getAcceleration() - 1.4399999999938082) < 0.00001);
    EXPECT_TRUE(std::abs(v.getPosition() - 0.00059520959999999996) < 0.00001);
}

TEST(VehicleTests, UpdateAccelerationHappyDay) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, v.getAcceleration());
    v.updateAcceleration(nullptr);

    EXPECT_TRUE(std::abs(v.getAcceleration() - 1.4399999999999999) < 0.00001);
}

TEST(VehicleTests, UpdateSpeedHappyDay) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, v.getSpeed());
    // Update acceleration first
    v.updateAcceleration(nullptr);
    // Then update the speed
    v.updateSpeed();

    EXPECT_TRUE(std::abs(v.getSpeed() - 0.023904) < 0.00001);
}

TEST(VehicleTests, DecelerateHappyDay) {
    Vehicle v = Vehicle(0.0, VehicleType::Personal);
    EXPECT_EQ(gSpeedMax, v.getSpeedMax());
    v.decelerate();
    EXPECT_EQ(v.getDecelerationFactor() * gSpeedMax, v.getSpeedMax());
}
