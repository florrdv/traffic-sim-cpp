#include <gtest/gtest.h>
#include "VehicleGenerator.h"

TEST(GeneratorTests, setFrequency1) {
    VehicleGenerator* g = new VehicleGenerator();

    EXPECT_DEATH(g->setFrequency(-20), "strictly positive");
}

TEST(GeneratorTests, setFrequency2) {
    VehicleGenerator* g = new VehicleGenerator();

    EXPECT_DEATH(g->setFrequency(0), "strictly positive");
}

TEST(GeneratorTests, getSetFrequency) {
    VehicleGenerator* g = new VehicleGenerator();
    g->setFrequency(20);
    EXPECT_EQ(20, g->getFrequency());
}