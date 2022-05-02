/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: contains road logic
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 10th March 2022 5:12:46 pm
 */

#include <gtest/gtest.h>
#include "Entity.h"

TEST(EntityTests, EntityGenerationHappyDay) {
    EXPECT_EXIT({Entity(10.0); fprintf(stderr, "Done"); exit(0);},
                ::testing::ExitedWithCode(0), "Done");
}

TEST(EntityTests, EntityGenerationNegativePosition) {
    EXPECT_DEATH(Entity(-10), "Entity position cannot be a negative integer");
}

TEST(EntityTests, PositionMutationHappyDay) {
    Entity entity = Entity(10.0);
    ASSERT_EQ(10.0, entity.getPosition());
    entity.setPosition(5.0);
    ASSERT_EQ(5.0, entity.getPosition());
}

TEST(EntityTests, PositionMutationNegative) {
    Entity entity = Entity(10.0);

    EXPECT_DEATH(entity.setPosition(-50.0), "positive double");
}