#include <gtest/gtest.h>
#include <fstream>

#include "data/Constants.cc"
#include "lib/TestingHelpers.h"

TEST(SimulationTests, Temp) {
    EXPECT_EQ(5, 5);
}

TEST(SimulationTests, FileTestExample1) {
    EXPECT_TRUE(fileCompare(TEST_INPUT_FOLDER + "/test1.txt", TEST_INPUT_FOLDER + "/test2.txt"));
}

void writeOnDemo(std::ostream& onStream) {
    onStream << "yes";
}

TEST(SimulationTests, FileTestExample2) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/FileTestExample2.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/test1.txt";

    std::ofstream temp(outPath);
	writeOnDemo(temp);
	temp.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}

std::string generateYes() {
    return "yes";
}

TEST(SimulationTests, FileTestExample3) {
    std::string outPath = TEST_OUTPUT_FOLDER + "/FileTestExample3.txt";
    std::string inPath = TEST_INPUT_FOLDER + "/test1.txt";

    std::ofstream temp(outPath);
	temp << generateYes();
	temp.close();

    EXPECT_TRUE(fileCompare(inPath, outPath));
}