/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains traffic light class definition
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <gtest/gtest.h>
#include "TrafficLight.h"

TEST(TrafficLightTests, TrafficLightGenerationHappyDay) {
    EXPECT_EXIT({TrafficLight(0.0, 10); fprintf(stderr, "Done"); exit(0);},
                ::testing::ExitedWithCode(0), "Done");
}

TEST(TrafficLightTests, TrafficLightGenerationNegativePosition) {
    EXPECT_DEATH(TrafficLight(-10, 10), "Entity position cannot be a negative integer");
}

TEST(TrafficLightTests, TrafficLightGenerationZeroCycleCount) {
    EXPECT_DEATH(TrafficLight(0, 0), "Cycle count must be strictly positive");
}

TEST(TrafficLightTests, TrafficLightGenerationNegativeCycleCount) {
    EXPECT_DEATH(TrafficLight(0, -1), "Cycle count must be strictly positive");
}

TEST(TrafficLightTests, PositionMutationHappyDay) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(0, light.getPosition());
    light.setPosition(20);
    EXPECT_EQ(20, light.getPosition());
}

TEST(TrafficLightTests, PositionMutationNegative) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(0, light.getPosition());
    EXPECT_DEATH(light.setPosition(-20), "positive");
}

TEST(TrafficLightTests, CycleMutationHappyDay) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(10, light.getCycle());
    light.setCycle(20);
    EXPECT_EQ(20, light.getCycle());
}

TEST(TrafficLightTests, CycleMutationZero) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(10, light.getCycle());
    EXPECT_DEATH(light.setCycle(0), "strictly positive");
}

TEST(TrafficLightTests, CycleMutationNegative) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(10, light.getCycle());
    EXPECT_DEATH(light.setCycle(-20), "strictly positive");
}

TEST(TrafficLightTests, StateMutationHappyDay) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(light.getState(), TrafficLightState::Red);

    light.setState(TrafficLightState::Green);
    EXPECT_EQ(light.getState(), TrafficLightState::Green);

    light.setState(TrafficLightState::Orange);
    EXPECT_EQ(light.getState(), TrafficLightState::Orange);

    light.setState(TrafficLightState::Red);
    EXPECT_EQ(light.getState(), TrafficLightState::Red);
}

TEST(TrafficLightTests, CycleCountMutationHappyDay) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(10, light.getCycle());
    light.setCycleCount(0);
    ASSERT_EQ(0, light.getCycleCount());
}

TEST(TrafficLightTests, CycleCountMutationNegative) {
    TrafficLight light = TrafficLight(0.0, 10);
    EXPECT_EQ(10, light.getCycle());
    EXPECT_DEATH(light.setCycleCount(-20), "positive");
}
