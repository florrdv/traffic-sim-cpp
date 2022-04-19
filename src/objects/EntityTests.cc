#include <gtest/gtest.h>
#include "Entity.h"

TEST(EntityTests, PositionMutationHappyDay) {
    Entity entity = Entity(10.0);
    ASSERT_EQ(10.0, entity.getPosition());
    entity.setPosition(5.0);
    ASSERT_EQ(5.0, entity.getPosition());
}

TEST(EntityTests, PositionMutationNegative) {
    Entity entity = Entity(10.0);

    EXPECT_DEATH(entity.setPosition(-50.0), "positive integer");
}
