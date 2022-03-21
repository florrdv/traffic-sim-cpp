#include <gtest/gtest.h>

#include "data/Constants.cc"
#include "lib/TestingHelpers.h"

TEST(SimulationTests, Temp) {
    EXPECT_EQ(5, 5);
}

TEST(SimulationTests, FileTestExample1) {
    EXPECT_TRUE(fileCompare(TEST_INPUT_FOLDER + "/test1.txt", TEST_INPUT_FOLDER + "/test2.txt"));
}

TEST(SimulationTests, FileTestExample2) {
    EXPECT_TRUE(fileCompare(TEST_INPUT_FOLDER + "/test1.txt", TEST_INPUT_FOLDER + "/test2.txt"));
}