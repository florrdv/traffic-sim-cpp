#include <gtest/gtest.h>
#include "VehicleGenerator.h"

TEST(GeneratorTests, FrequencyMutationNegative) {
    VehicleGenerator* g = new VehicleGenerator();

    EXPECT_DEATH(g->setFrequency(-20), "strictly positive");
}

TEST(GeneratorTests, FrequencyMutationZero) {
    VehicleGenerator* g = new VehicleGenerator();

    EXPECT_DEATH(g->setFrequency(0), "strictly positive");
}

TEST(GeneratorTests, FrequencyMutationHappyDay) {
    VehicleGenerator* g = new VehicleGenerator();
    g->setFrequency(20);
    EXPECT_EQ(20, g->getFrequency());
}

TEST(GeneratorTests, FrequencyCountMutationNegative) {
    VehicleGenerator* g = new VehicleGenerator();

    EXPECT_DEATH(g->setFrequencyCount(-20), "positive");
}

TEST(GeneratorTests, FrequencyCountMutationHappyDay) {
    VehicleGenerator* g = new VehicleGenerator();

    g->setFrequencyCount(0);
    ASSERT_EQ(0, g->getFrequencyCount());
}