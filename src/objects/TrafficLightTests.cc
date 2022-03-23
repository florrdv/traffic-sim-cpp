#include <gtest/gtest.h>
#include "TrafficLight.h"

TEST(TrafficLightTests, setPosition) {
    TrafficLight light = TrafficLight(0.0);

    EXPECT_DEATH(light.setPosition(-20), "positive");
}

TEST(TrafficLightTests, getSetPosition) {
    TrafficLight light = TrafficLight(0.0);
    light.setPosition(20);
    EXPECT_EQ(20, light.getPosition());
}

TEST(TrafficLightTests, setCycle1) {
    TrafficLight light = TrafficLight(0.0);

    EXPECT_DEATH(light.setCycle(0), "strictly positive");
}

TEST(TrafficLightTests, setCycle2) {
    TrafficLight light = TrafficLight(0.0);

    EXPECT_DEATH(light.setCycle(-20), "strictly positive");
}

TEST(TrafficLightTests, getSetCycle) {
    TrafficLight light = TrafficLight(0.0);
    light.setCycle(20);
    EXPECT_EQ(20, light.getCycle());
}

TEST(TrafficLightTests, toggle) {
    TrafficLight light = TrafficLight(0.0);
    bool beforeToggle = light.isGreen();
    light.toggle();
    EXPECT_NE(beforeToggle, light.isGreen());
}

TEST(TrafficLightTests, CycleCountMutationNegative) {
    TrafficLight light = TrafficLight(0.0);

    EXPECT_DEATH(light.setCycleCount(-20), "positive");
}

TEST(TrafficLightTests, CycleCountMutationHappyDay) {
    TrafficLight light = TrafficLight(0.0);

    light.setCycleCount(0);
    ASSERT_EQ(0, light.getCycleCount());
}