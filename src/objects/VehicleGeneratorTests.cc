#include <gtest/gtest.h>
#include "VehicleGenerator.h"

TEST(GeneratorTests, FrequencyMutationNegative) {
    VehicleGenerator* g = new VehicleGenerator(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, g->getFrequency());
    EXPECT_DEATH(g->setFrequency(-20), "strictly positive");
}

TEST(GeneratorTests, FrequencyMutationZero) {
    VehicleGenerator* g = new VehicleGenerator(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, g->getFrequency());
    EXPECT_DEATH(g->setFrequency(0), "strictly positive");
}

TEST(GeneratorTests, FrequencyMutationHappyDay) {
    VehicleGenerator* g = new VehicleGenerator(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, g->getFrequency());
    g->setFrequency(20);
    EXPECT_EQ(20, g->getFrequency());
}

TEST(GeneratorTests, FrequencyCountMutationNegative) {
    VehicleGenerator* g = new VehicleGenerator(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, g->getFrequency());
    EXPECT_DEATH(g->setFrequencyCount(-20), "positive");
}

TEST(GeneratorTests, FrequencyCountMutationHappyDay) {
    VehicleGenerator* g = new VehicleGenerator(0.0, VehicleType::Personal);
    EXPECT_EQ(0.0, g->getFrequency());
    g->setFrequencyCount(0);
    ASSERT_EQ(0, g->getFrequencyCount());
}
