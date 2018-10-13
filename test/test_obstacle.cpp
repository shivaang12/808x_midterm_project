/**
 * @file      test_obstacle.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * Testing file for the Obstacle_generator class.
 */
#include <gtest/gtest.h>
#include <obstacle_generator.hpp>

/**
 * @brief     A general test, for testing all the methods of the class.
 */
TEST(testObstacleClass, allInOneTest) {
  Obstacle_generator obs;
  EXPECT_GE(obs.get_height(), 0);
  EXPECT_GE(obs.get_width(), 0);
  EXPECT_GE(obs.get_goalpoint().first, 0);
  EXPECT_GE(obs.get_startpoint().second, 0);
  EXPECT_FALSE(obs.generate_obstacles().empty());
}
