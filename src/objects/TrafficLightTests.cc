#include <gtest/gtest.h>
#include "TrafficLight.h"

TEST(TrafficLightTests, setPosition) {
    TrafficLight* light = new TrafficLight();

    EXPECT_DEATH(light->setPosition(-20), "positive");
}

TEST(TrafficLightTests, getSetPosition) {
    TrafficLight* light = new TrafficLight();
    light->setPosition(20);
    EXPECT_EQ(20, light->getPosition());
}

TEST(TrafficLightTests, setCycle1) {
    TrafficLight* light = new TrafficLight();

    EXPECT_DEATH(light->setCycle(0), "strictly positive");
}

TEST(TrafficLightTests, setCycle2) {
    TrafficLight* light = new TrafficLight();

    EXPECT_DEATH(light->setCycle(-20), "strictly positive");
}

TEST(TrafficLightTests, getSetCycle) {
    TrafficLight* light = new TrafficLight();
    light->setCycle(20);
    EXPECT_EQ(20, light->getCycle());
}

TEST(TrafficLightTests, toggle) {
    TrafficLight* light = new TrafficLight;
    bool beforeToggle = light->isGreen();
    light->toggle();
    EXPECT_NE(beforeToggle, light->isGreen());
}