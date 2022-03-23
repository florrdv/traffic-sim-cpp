#include <gtest/gtest.h>
#include "TrafficLight.h"

TEST(TrafficLightTests, setPosition) {
    TrafficLight light;

    EXPECT_DEATH(light.setPosition(-20), "positive");
}

TEST(TrafficLightTests, getSetPosition) {
    TrafficLight light;
    light.setPosition(20);
    EXPECT_EQ(20, light.getPosition());
}

TEST(TrafficLightTests, setCycle1) {
    TrafficLight light;

    EXPECT_DEATH(light.setCycle(0), "strictly positive");
}

TEST(TrafficLightTests, setCycle2) {
    TrafficLight light;

    EXPECT_DEATH(light.setCycle(-20), "strictly positive");
}

TEST(TrafficLightTests, getSetCycle) {
    TrafficLight light;
    light.setCycle(20);
    EXPECT_EQ(20, light.getCycle());
}

TEST(TrafficLightTests, toggle) {
    TrafficLight light;
    bool beforeToggle = light.isGreen();
    light.toggle();
    EXPECT_NE(beforeToggle, light.isGreen());
}

TEST(TrafficLightTests, CycleCountMutationNegative) {
    TrafficLight light;

    EXPECT_DEATH(light.setCycleCount(-20), "positive");
}

TEST(TrafficLightTests, CycleCountMutationHappyDay) {
    TrafficLight light;

    light.setCycleCount(0);
    ASSERT_EQ(0, light.getCycleCount());
}