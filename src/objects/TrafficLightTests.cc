#include <gtest/gtest.h>
#include "TrafficLight.h"

TEST(TrafficLightTests, setPosition1) {
    TrafficLight* light = new TrafficLight();

    light->setPosition(0);
}

TEST(TrafficLightTests, setPosition2) {
    TrafficLight* light = new TrafficLight();

    light->setPosition(-20);
}

TEST(TrafficLightTests, getSetPosition) {
    TrafficLight* light = new TrafficLight();
    light->setPosition(20);
}